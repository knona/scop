#include "scop.h"

void init_options(t_object *obj)
{
	ft_bzero(&g_event_options, sizeof(t_event_options));
	g_event_options.obj = obj;
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

int clean(t_object *obj)
{
	clean_object(obj);
	glfwTerminate();
	return (0);
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
