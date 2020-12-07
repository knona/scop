/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krambono <krambono@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 15:03:17 by krambono          #+#    #+#             */
/*   Updated: 2020/12/07 15:11:26 by krambono         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
	t_mat4x4 projection;

	(void)window;
	glViewport(0, 0, width, height);
	projection = perspective(deg_to_rad(30), (float)width / (float)height,
	0.1f, 100.0f);
	uniform_set_mat4x4(g_event_options.obj->program, "projection", &projection);
}

void	scroll_callback(GLFWwindow *window, double xoffset, double yoffset)
{
	const float speed = 0.15;

	(void)window;
	(void)xoffset;
	if (yoffset > 0)
		g_event_options.pos.z += speed;
	if (yoffset < 0)
		g_event_options.pos.z -= speed;
}

void	cursor_position_callback(GLFWwindow *window, double xpos, double ypos)
{
	t_vec3		pos_cpy;
	t_cursor	curs_pos;

	(void)window;
	pos_cpy = g_event_options.pos_cpy;
	curs_pos = g_event_options.curs_pos;
	if (g_event_options.l_click)
	{
		g_event_options.pos.x = pos_cpy.x - (curs_pos.x - xpos) / 200;
		g_event_options.pos.y = pos_cpy.y + (curs_pos.y - ypos) / 200;
	}
}

void	mouse_button_callback(GLFWwindow *window, int button, int action,
		int mods)
{
	t_vec3		pos;
	t_cursor	*curs_pos;

	(void)mods;
	pos = g_event_options.pos;
	curs_pos = &g_event_options.curs_pos;
	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
	{
		g_event_options.l_click = 1;
		glfwGetCursorPos(window, &curs_pos->x, &curs_pos->y);
		g_event_options.pos_cpy.x = pos.x;
		g_event_options.pos_cpy.y = pos.y;
	}
	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE)
		g_event_options.l_click = 0;
}
