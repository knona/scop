#include "scop.h"

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

int clean(t_object *obj)
{
	clean_object(obj);
	glfwTerminate();
	return (0);
}

int init_window(GLFWwindow *window)
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

		model = rotate(&g_matI4, glfwGetTime() * M_PI_2, get_vec3(0, 1, 0));
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

	if (argc != 2)
		return (error_int(1, "Path to .obj file is required"));
	t_object obj = parse_obj_file(argv[1]);
	window = NULL;
	if (!init_window(window))
		return (1);
	ret = !start(window, &obj);
	clean(&obj);
	return (ret);
}
