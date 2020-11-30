#include "scop.h"

GLFWwindow *window;
GLuint      program;
GLuint      ebo;
GLuint      vao;
GLuint      vbo;

void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
	(void)window;
	(void)key;
	(void)scancode;
	(void)action;
	(void)mods;

	if (action == GLFW_PRESS || action == GLFW_REPEAT)
	{
		if (key == GLFW_KEY_LEFT || key == GLFW_KEY_P)
			;
		if (key == GLFW_KEY_LEFT || key == GLFW_KEY_O)
			;
		if (key == GLFW_KEY_LEFT || key == GLFW_KEY_L)
			;
		if (key == GLFW_KEY_LEFT || key == GLFW_KEY_K)
			;
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
	float cube[] = {
		-0.5f, -0.5f, -0.5f, 0.37f, 0.46f, 0.37f, //
		0.5f,  -0.5f, -0.5f, 0.37f, 0.46f, 0.37f, //
		0.5f,  0.5f,  -0.5f, 0.37f, 0.46f, 0.37f, //
		0.5f,  0.5f,  -0.5f, 0.37f, 0.46f, 0.37f, //
		-0.5f, 0.5f,  -0.5f, 0.37f, 0.46f, 0.37f, //
		-0.5f, -0.5f, -0.5f, 0.37f, 0.46f, 0.37f, //

		-0.5f, -0.5f, 0.5f,  0.37f, 0.18f, 0.47f, //
		0.5f,  -0.5f, 0.5f,  0.37f, 0.18f, 0.47f, //
		0.5f,  0.5f,  0.5f,  0.37f, 0.18f, 0.47f, //
		0.5f,  0.5f,  0.5f,  0.37f, 0.18f, 0.47f, //
		-0.5f, 0.5f,  0.5f,  0.37f, 0.18f, 0.47f, //
		-0.5f, -0.5f, 0.5f,  0.37f, 0.18f, 0.47f, //

		-0.5f, 0.5f,  0.5f,  0.37f, 0.62f, 0.63f, //
		-0.5f, 0.5f,  -0.5f, 0.37f, 0.62f, 0.63f, //
		-0.5f, -0.5f, -0.5f, 0.37f, 0.62f, 0.63f, //
		-0.5f, -0.5f, -0.5f, 0.37f, 0.62f, 0.63f, //
		-0.5f, -0.5f, 0.5f,  0.37f, 0.62f, 0.63f, //
		-0.5f, 0.5f,  0.5f,  0.37f, 0.62f, 0.63f, //

		0.5f,  0.5f,  0.5f,  0.38f, 0.69f, 1.0f, //
		0.5f,  0.5f,  -0.5f, 0.38f, 0.69f, 1.0f, //
		0.5f,  -0.5f, -0.5f, 0.38f, 0.69f, 1.0f, //
		0.5f,  -0.5f, -0.5f, 0.38f, 0.69f, 1.0f, //
		0.5f,  -0.5f, 0.5f,  0.38f, 0.69f, 1.0f, //
		0.5f,  0.5f,  0.5f,  0.38f, 0.69f, 1.0f, //

		-0.5f, -0.5f, -0.5f, 0.40f, 0.0f,  1.0f, //
		0.5f,  -0.5f, -0.5f, 0.40f, 0.0f,  1.0f, //
		0.5f,  -0.5f, 0.5f,  0.40f, 0.0f,  1.0f, //
		0.5f,  -0.5f, 0.5f,  0.40f, 0.0f,  1.0f, //
		-0.5f, -0.5f, 0.5f,  0.40f, 0.0f,  1.0f, //
		-0.5f, -0.5f, -0.5f, 0.40f, 0.0f,  1.0f, //

		-0.5f, 0.5f,  -0.5f, 0.55f, 0.24f, 0.18f, //
		0.5f,  0.5f,  -0.5f, 0.55f, 0.24f, 0.18f, //
		0.5f,  0.5f,  0.5f,  0.55f, 0.24f, 0.18f, //
		0.5f,  0.5f,  0.5f,  0.55f, 0.24f, 0.18f, //
		-0.5f, 0.5f,  0.5f,  0.55f, 0.24f, 0.18f, //
		-0.5f, 0.5f,  -0.5f, 0.55f, 0.24f, 0.18f  //
	};

	// uint indices[] = {
	// 	0, 1, 2, // first triangle
	// 	1, 2, 3  // second triangle
	// };

	glBindVertexArray(vao);

	// glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	// glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(cube), cube, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(
		1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

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
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glBindVertexArray(vao);

		model = rotate(&g_matI4, glfwGetTime() * M_PI_2, get_vec3(0.5f, 1, 0));
		if (!uniform_set_mat4x4(program, "model", &model))
			return (0);

		glDrawArrays(GL_TRIANGLES, 0, 36);
		glBindVertexArray(0);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	return (1);
}

int start(void)
{
	t_mat4x4 projection;
	t_mat4x4 view;

	glEnable(GL_DEPTH_TEST);
	glClearColor(0.9686f, 0.9765f, 0.9765f, 1.0f);
	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &ebo);
	glGenBuffers(1, &vbo);
	create_vao();
	if (!create_program(&program, "main/shaders/shader.vert", "main/shaders/shader.frag"))
		return (0);
	glUseProgram(program);
	view = g_matI4;
	projection = perspective(
		deg_to_rad(45), (float)SCOP_WIN_WIDTH / (float)SCOP_WIN_HEIGHT, 0.1f, 100.0f);
	view = translate(&g_matI4, get_vec3(0, 0, -3));

	if (!uniform_set_mat4x4(program, "projection", &projection))
		return (0);
	if (!uniform_set_mat4x4(program, "view", &view))
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
