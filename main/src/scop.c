#include "scop.h"

t_vec3 pos;
float  scaling;

void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
	const float speed = 0.1;

	(void)window;
	(void)scancode;
	(void)mods;

	if (action == GLFW_PRESS || action == GLFW_REPEAT)
	{
		if (key == GLFW_KEY_W)
			pos.y += speed * (1 << (int)(action == GLFW_REPEAT));
		if (key == GLFW_KEY_S)
			pos.y -= speed * (1 << (int)(action == GLFW_REPEAT));
		if (key == GLFW_KEY_D)
			pos.x += speed * (1 << (int)(action == GLFW_REPEAT));
		if (key == GLFW_KEY_A)
			pos.x -= speed * (1 << (int)(action == GLFW_REPEAT));
		if (key == GLFW_KEY_P)
			pos.z += speed * (1 << (int)(action == GLFW_REPEAT));
		if (key == GLFW_KEY_O)
			pos.z -= speed * (1 << (int)(action == GLFW_REPEAT));
	}
}

int clean(t_object *obj)
{
	clean_object(obj);
	glfwTerminate();
	return (0);
}

int init_window(GLFWwindow **window)
{
	if (!glfwInit())
		return (error_0("Failed to initialize GLFW"));
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	// glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	*window = glfwCreateWindow(SCOP_WIN_WIDTH, SCOP_WIN_HEIGHT, "LearnOpenGL", NULL, NULL);
	if (!*window)
		return (error_0("Failed to create GLFW window"));
	glfwMakeContextCurrent(*window);
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		return (error_0("Failed to initialize GLAD"));
	glViewport(0, 0, SCOP_WIN_WIDTH, SCOP_WIN_HEIGHT);
	// glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	glfwSetKeyCallback(*window, (void (*)(GLFWwindow *, int, int, int, int))key_callback);
	return (1);
}

void processInput(GLFWwindow *window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, 1);
}

int renderLoop(GLFWwindow *window, t_object *obj)
{
	t_mat4x4 model;

	while (!glfwWindowShouldClose(window))
	{
		processInput(window);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glBindVertexArray(obj->vao);

		model = translate(&g_matI4, pos);
		model = rotate(&model, glfwGetTime() * M_PI_2, get_vec3(0, 1, 0));
		model = scale(&model, get_vec3(scaling, scaling, scaling));
		if (!uniform_set_mat4x4(obj->program, "model", &model))
			return (0);

		glDrawElements(GL_TRIANGLES, obj->indices_size, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	return (1);
}

int start(GLFWwindow *window, t_object *obj)
{
	ft_bzero(&pos, 3 * sizeof(float));
	scaling = 1;
	glEnable(GL_DEPTH_TEST);
	glClearColor(0.9686f, 0.9765f, 0.9765f, 1.0f);
	if (!init_object(obj))
		return (0);
	if (!renderLoop(window, obj))
		return (0);
	return (1);
}

int main(int argc, const char **argv)
{
	GLFWwindow *window;
	int         ret;
	t_object    obj;

	if (argc != 2)
		return (error_int(1, "Path to .obj file is required"));
	ft_bzero(&obj, sizeof(t_object));
	if (!parse_obj_file(argv[1], &obj))
	{
		clean_object(&obj);
		return (1);
	}
	window = NULL;
	if (!init_window(&window))
		return (1);
	ret = !start(window, &obj);
	clean(&obj);
	return (ret);
}
