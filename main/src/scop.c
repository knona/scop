#include "scop.h"

t_vec3   pos;
int      scop_pause;
double   time;
int      line_mode;
int      l_click;
t_cursor curs_pos;
t_vec3   pos_cpy;
float    rotx;

void init_options(void)
{
	ft_bzero(&pos, 3 * sizeof(float));
	scop_pause = 0;
	time = 0;
	line_mode = 0;
	l_click = 0;
	rotx = 0;
}

void scroll_callback(GLFWwindow *window, double xoffset, double yoffset)
{
	const float speed = 0.2;

	(void)window;
	(void)xoffset;
	if (yoffset > 0)
		pos.z += speed;
	if (yoffset < 0)
		pos.z -= speed;
}

void cursor_position_callback(GLFWwindow *window, double xpos, double ypos)
{
	(void)window;
	if (l_click)
	{
		pos.x = pos_cpy.x - (curs_pos.x - xpos) / 100;
		pos.y = pos_cpy.y + (curs_pos.y - ypos) / 100;
	}
}

void mouse_button_callback(GLFWwindow *window, int button, int action, int mods)
{
	(void)mods;
	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
	{
		l_click = 1;
		glfwGetCursorPos(window, &curs_pos.x, &curs_pos.y);
		pos_cpy.x = pos.x;
		pos_cpy.y = pos.y;
	}
	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE)
		l_click = 0;
}

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
		if (key == GLFW_KEY_K)
			rotx += speed * (1 << (int)(action == GLFW_REPEAT));
		if (key == GLFW_KEY_L)
			rotx -= speed * (1 << (int)(action == GLFW_REPEAT));
		if (key == GLFW_KEY_SPACE)
			scop_pause = !scop_pause;
		if (key == GLFW_KEY_R)
			init_options();
		if (key == GLFW_KEY_F)
		{
			line_mode = !line_mode;
			glPolygonMode(GL_FRONT_AND_BACK, line_mode ? GL_LINE : GL_FILL);
		}
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
	*window = glfwCreateWindow(SCOP_WIN_WIDTH, SCOP_WIN_HEIGHT, "LearnOpenGL", NULL, NULL);
	if (!*window)
		return (error_0("Failed to create GLFW window"));
	glfwMakeContextCurrent(*window);
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		return (error_0("Failed to initialize GLAD"));
	glViewport(0, 0, SCOP_WIN_WIDTH, SCOP_WIN_HEIGHT);
	// glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	glfwSetKeyCallback(*window, (void (*)(GLFWwindow *, int, int, int, int))key_callback);
	glfwSetMouseButtonCallback(*window, mouse_button_callback);
	glfwSetCursorPosCallback(*window, cursor_position_callback);
	glfwSetScrollCallback(*window, scroll_callback);
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
		// model = scale(&model, get_vec3(0.1f, 0.1f, 0.1f));
		model = rotate_y(&model, time * M_2_PI);
		model = rotate_x(&model, rotx);
		if (!uniform_set_mat4x4(obj->program, "model", &model))
			return (0);

		glDrawElements(GL_TRIANGLES, obj->indices_size, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);
		glfwSwapBuffers(window);
		glfwPollEvents();
		if (!scop_pause)
			time += 0.01;
	}
	return (1);
}

int start(GLFWwindow *window, t_object *obj)
{
	init_options();
	glEnable(GL_DEPTH_TEST);
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
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
