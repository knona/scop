#include "scop.h"

t_vec3   pos;
int      scop_pause;
double   time;
int      line_mode;
int      l_click;
t_cursor curs_pos;
t_vec3   pos_cpy;
float    rotx;
GLuint   program;

void init_options(void)
{
	ft_bzero(&pos, 3 * sizeof(float));
	scop_pause = 0;
	time = 0;
	line_mode = 0;
	l_click = 0;
	rotx = 0;
}

void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
	t_mat4x4 projection;

	(void)window;
	glViewport(0, 0, width, height);
	projection = perspective(deg_to_rad(30), (float)width / (float)height, 0.1f, 100.0f);
	uniform_set_mat4x4(program, "projection", &projection);
}

void scroll_callback(GLFWwindow *window, double xoffset, double yoffset)
{
	const float speed = 0.15;

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
		pos.x = pos_cpy.x - (curs_pos.x - xpos) / 200;
		pos.y = pos_cpy.y + (curs_pos.y - ypos) / 200;
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
		if (action != GLFW_REPEAT)
		{
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
	glfwSetWindowSizeLimits(*window, 400, 225, GLFW_DONT_CARE, GLFW_DONT_CARE);
	glfwSetFramebufferSizeCallback(*window, framebuffer_size_callback);
	glfwSetKeyCallback(*window, key_callback);
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
	float    x;
	float    y;
	float    z;
	float    scaling;
	float    max;
	float    abs_value;

	x = (obj->range.x_max + obj->range.x_min) / 2;
	y = (obj->range.y_max + obj->range.y_min) / 2;
	z = (obj->range.z_max + obj->range.z_min) / 2;

	max = 1;
	for (int i = 0; i < 6; i++)
	{
		abs_value = fabsf(((float *)(&obj->range))[i]);
		if (abs_value > max)
			max = abs_value;
	}
	scaling = max != 0 ? 2 / max : 1;

	while (!glfwWindowShouldClose(window))
	{
		processInput(window);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glBindVertexArray(obj->vao);
		model = translate(&g_matI4, pos);
		model = scale(&model, get_vec3(scaling, scaling, scaling));
		model = rotate_y(&model, time * M_2_PI);
		model = rotate_x(&model, rotx);
		model = translate(&model, get_vec3(-x, -y, -z));
		if (!uniform_set_mat4x4(obj->program, "model", &model))
			return (0);
		glBindTexture(GL_TEXTURE_2D, obj->texture);
		glDrawElements(GL_TRIANGLES, obj->indices_size, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);
		glfwSwapBuffers(window);
		glfwPollEvents();
		if (!scop_pause)
			time += 0.01;
	}
	return (1);
}

void display_commands()
{
	ft_printf("Commands:\n");
	ft_printf("Move (x y axis): \033[36mw / a / s / d\033[0m or "
			  "\033[36mmouse\033[0m (left click)\n");
	ft_printf("Move (z axis): \033[36mo / p\033[0m or "
			  "\033[36mscroll\033[0m\n");
	ft_printf("Rotation (x axis): \033[36mk / l\033[0m \n");
	ft_printf("Pause the rotation: \033[36mspace\033[0m \n");
	ft_printf("Fill polygons: \033[36mf\033[0m \n");
}

int start(GLFWwindow *window, t_object *obj)
{
	init_options();
	glEnable(GL_DEPTH_TEST);
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	if (!init_object(obj))
		return (0);
	program = obj->program;
	display_commands();
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
