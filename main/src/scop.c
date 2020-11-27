#include "scop.h"

GLFWwindow *window;
GLuint      program;
GLuint      ebo;
GLuint      vao;
GLuint      vbo;
t_vec2      pos;
float       rotz;
int         grow;

void key_callback(t_key_cb_params params)
{
	const int speed = 10;
	const int action = params.action;
	const int key = params.key;

	if (action == GLFW_PRESS || action == GLFW_REPEAT)
	{
		if (key == GLFW_KEY_UP || key == GLFW_KEY_W)
			pos.y += speed * powf(2, action == GLFW_REPEAT);
		if (key == GLFW_KEY_DOWN || key == GLFW_KEY_S)
			pos.y -= speed * powf(2, action == GLFW_REPEAT);
		if (key == GLFW_KEY_RIGHT || key == GLFW_KEY_D)
			pos.x += speed * powf(2, action == GLFW_REPEAT);
		if (key == GLFW_KEY_LEFT || key == GLFW_KEY_A)
			pos.x -= speed * powf(2, action == GLFW_REPEAT);
		if (key == GLFW_KEY_LEFT || key == GLFW_KEY_P)
			rotz += M_PI_16;
		if (key == GLFW_KEY_LEFT || key == GLFW_KEY_O)
			rotz -= M_PI_16;
		if (key == GLFW_KEY_LEFT || key == GLFW_KEY_L)
			grow += speed * powf(2, action == GLFW_REPEAT);
		if (key == GLFW_KEY_LEFT || key == GLFW_KEY_K)
			grow -= speed * powf(2, action == GLFW_REPEAT);
	}
}

int clean()
{
	if (program)
		glDeleteProgram(program);
	if (vao)
		glDeleteVertexArrays(1, &vao);
	if (vbo)
		glDeleteBuffers(1, &vbo);
	if (ebo)
		glDeleteBuffers(1, &ebo);
	glfwTerminate();
	return (0);
}

int init()
{
	if (!glfwInit())
		return (error_0("Failed to initialize GLFW"));

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow(SCOP_WIN_WIDTH, SCOP_WIN_HEIGHT, "LearnOpenGL", NULL, NULL);
	if (!window)
		return (error_0("Failed to create GLFW window"));

	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		return (error_0("Failed to initialize GLAD"));

	glViewport(0, 0, SCOP_WIN_WIDTH, SCOP_WIN_HEIGHT);
	// glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	glfwSetKeyCallback(window, (void (*)(GLFWwindow *, int, int, int, int))key_callback);
	return (1);
}

void create_vao()
{
	float cell[] = {
		-0.5f, +0.5f, // top left
		-0.5f, -0.5f, // bottom left
		+0.5f, +0.5f, // top right
		+0.5f, -0.5f, // bottom right
	};

	uint indices[] = {
		0, 1, 2, // first triangle
		1, 2, 3  // second triangle
	};

	glBindVertexArray(vao);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(cell), cell, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void *)0);
	glEnableVertexAttribArray(0);

	glBindVertexArray(0);
}

void processInput(GLFWwindow *window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, 1);
}

int renderLoop()
{
	t_mat4x4 model;

	while (!glfwWindowShouldClose(window))
	{
		processInput(window);
		glClear(GL_COLOR_BUFFER_BIT);
		glBindVertexArray(vao);
		model = g_matI4;
		t_vec3 vec = { pos.x, pos.y, 0 };
		model = translate(&model, &vec);
		model = rotation_z(&model, rotz);
		t_vec3 vec2 = { grow, grow, 1 };
		model = scale(&model, &vec2);
		if (!uniform_set_mat4x4(program, "model", &model))
			return (0);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);
		glfwSwapBuffers(window);
		glfwWaitEvents();
	}
	return (1);
}

int start(void)
{
	t_mat4x4 view;
	t_mat4x4 projection;

	glClearColor(0.9686f, 0.9765f, 0.9765f, 1.0f);
	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &ebo);
	glGenBuffers(1, &vbo);
	create_vao();
	if (!create_program(&program, "main/shaders/shader.vert", "main/shaders/shader.frag"))
		return (0);
	pos.x = 500;
	pos.y = 500;
	rotz = 0;
	grow = 100;
	glUseProgram(program);
	view = g_matI4;
	projection = ortho(0, SCOP_WIN_WIDTH, 0, SCOP_WIN_HEIGHT);
	if (!uniform_set_mat4x4(program, "view", &view))
		return (0);
	if (!uniform_set_mat4x4(program, "projection", &projection))
		return (0);
	if (!renderLoop())
		return (0);
	return (1);
}

int main(void)
{
	int ret;
	// setbuf(stdout, NULL);
	if (!init())
		return (1);

	program = 0;
	ebo = 0;
	vao = 0;
	vbo = 0;
	ret = !start();
	clean();
	return (ret);
}
