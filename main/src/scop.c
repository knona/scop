#include "scop.h"

int start(GLFWwindow *window, t_object *obj)
{
	glEnable(GL_DEPTH_TEST);
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	if (!init_object(obj))
		return (0);
	init_options(obj);
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
