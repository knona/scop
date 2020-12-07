/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krambono <krambono@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 15:24:38 by krambono          #+#    #+#             */
/*   Updated: 2020/12/07 15:27:17 by krambono         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

float	get_scaling(t_object *obj)
{
	float max;
	float abs_value;

	max = 1;
	for (int i = 0; i < 6; i++)
	{
		abs_value = fabsf(((float *)(&obj->range))[i]);
		if (abs_value > max)
			max = abs_value;
	}
	return (max != 0 ? 2 / max : 1);
}

t_vec3	get_vec_center(t_object *obj)
{
	float x;
	float y;
	float z;

	x = (obj->range.x_max + obj->range.x_min) / 2;
	y = (obj->range.y_max + obj->range.y_min) / 2;
	z = (obj->range.z_max + obj->range.z_min) / 2;
	return (get_vec3(-x, -y, -z));
}

void	change_mix_value(t_object *obj)
{
	static float mix_value = 0;

	uniform_set_1f(obj->program, "mix_value", mix_value);
	if (!g_event_options.scop_pause)
			g_event_options.time += 0.01;
	if (g_event_options.increase)
	{
		mix_value += 0.01;
		if (mix_value > 1)
			mix_value = 1;
	}
	else
	{
		mix_value -= 0.01;
		if (mix_value < 0)
			mix_value = 0;
	}
}

int		renderLoop(GLFWwindow *window, t_object *obj)
{
	t_mat4x4	model;
	float		scaling;
	t_vec3		vec_center;

	vec_center = get_vec_center(obj);
	scaling = get_scaling(obj);
	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glBindVertexArray(obj->vao);
		model = translate(&g_mati4, g_event_options.pos);
		model = scale(&model, get_vec3(scaling, scaling, scaling));
		model = rotate_y(&model, g_event_options.time * M_2_PI);
		model = rotate_x(&model, g_event_options.rotx);
		model = translate(&model, vec_center);
		if (!uniform_set_mat4x4(obj->program, "model", &model))
			return (0);
		change_mix_value(obj);
		glBindTexture(GL_TEXTURE_2D, obj->texture);
		glDrawArrays(GL_TRIANGLES, 0, obj->nb_elements);
		glBindVertexArray(0);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	return (1);
}
