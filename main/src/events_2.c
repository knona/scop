/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krambono <krambono@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 15:10:38 by krambono          #+#    #+#             */
/*   Updated: 2020/12/07 15:11:01 by krambono         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	key_callback2(GLFWwindow *window, int key, int action)
{
	int *line_m;

	line_m = &g_event_options.line_mode;
	if (action != GLFW_REPEAT)
	{
		if (key == GLFW_KEY_SPACE)
			g_event_options.scop_pause = !g_event_options.scop_pause;
		if (key == GLFW_KEY_T)
			g_event_options.increase = !g_event_options.increase;
		if (key == GLFW_KEY_R)
			init_options(g_event_options.obj);
		if (key == GLFW_KEY_F)
		{
			*line_m = !*line_m;
			glPolygonMode(GL_FRONT_AND_BACK, *line_m ? GL_LINE : GL_FILL);
		}
		if (key == GLFW_KEY_ESCAPE)
			glfwSetWindowShouldClose(window, 1);
	}
}

void	key_callback(GLFWwindow *window, int key, int scancode, int action,
		int mods)
{
	const float	speed = 0.1;

	(void)mods;
	(void)scancode;
	if (action == GLFW_PRESS || action == GLFW_REPEAT)
	{
		if (key == GLFW_KEY_W)
			g_event_options.pos.y += speed * (1 << (action == GLFW_REPEAT));
		if (key == GLFW_KEY_S)
			g_event_options.pos.y -= speed * (1 << (action == GLFW_REPEAT));
		if (key == GLFW_KEY_D)
			g_event_options.pos.x += speed * (1 << (action == GLFW_REPEAT));
		if (key == GLFW_KEY_A)
			g_event_options.pos.x -= speed * (1 << (action == GLFW_REPEAT));
		if (key == GLFW_KEY_P)
			g_event_options.pos.z += speed * (1 << (action == GLFW_REPEAT));
		if (key == GLFW_KEY_O)
			g_event_options.pos.z -= speed * (1 << (action == GLFW_REPEAT));
		if (key == GLFW_KEY_K)
			g_event_options.rotx += speed * (1 << (action == GLFW_REPEAT));
		if (key == GLFW_KEY_L)
			g_event_options.rotx -= speed * (1 << (action == GLFW_REPEAT));
		key_callback2(window, key, action);
	}
}
