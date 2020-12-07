/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krambono <krambono@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 15:35:50 by krambono          #+#    #+#             */
/*   Updated: 2020/12/07 18:45:36 by krambono         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	init_options(t_object *obj)
{
	ft_bzero(&g_event_options, sizeof(t_event_options));
	g_event_options.obj = obj;
}

int		init_window(GLFWwindow **window)
{
	if (!glfwInit())
		return (error_0("Failed to initialize GLFW"));
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	*window = glfwCreateWindow(SCOP_WIN_WIDTH, SCOP_WIN_HEIGHT, "LearnOpenGL",
				NULL, NULL);
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

int		clean(t_object *obj)
{
	clean_object(obj);
	glfwTerminate();
	return (0);
}

void	display_commands(void)
{
	ft_printf("Commands:\n");
	ft_printf("Move (x y axis): \033[36mW / A / S / D\033[0m or "
	"\033[36mMOUSE\033[0m (left click)\n");
	ft_printf("Move (z axis): \033[36mO / P\033[0m or "
	"\033[36mSCROLL\033[0m\n");
	ft_printf("Rotation (x axis): \033[36mK / L\033[0m \n");
	ft_printf("Pause the rotation: \033[36mSPACE\033[0m \n");
	ft_printf("Fill polygons: \033[36mF\033[0m \n");
	ft_printf("Add texture: \033[36mT\033[0m \n");
	ft_printf("Reset options: \033[36mR\033[0m \n");
}

void	get_max_range(t_object *obj, t_vec3 *vertex)
{
	static int first = 1;

	if (first)
	{
		obj->range.x_max = vertex->x;
		obj->range.x_min = vertex->x;
		obj->range.y_max = vertex->y;
		obj->range.y_min = vertex->y;
		obj->range.z_max = vertex->z;
		obj->range.z_min = vertex->z;
		first = 0;
		return ;
	}
	if (vertex->x > obj->range.x_max)
		obj->range.x_max = vertex->x;
	if (vertex->x < obj->range.x_min)
		obj->range.x_min = vertex->x;
	if (vertex->y > obj->range.y_max)
		obj->range.y_max = vertex->y;
	if (vertex->y < obj->range.y_min)
		obj->range.y_min = vertex->y;
	if (vertex->z > obj->range.z_max)
		obj->range.z_max = vertex->z;
	if (vertex->z < obj->range.z_min)
		obj->range.z_min = vertex->z;
}
