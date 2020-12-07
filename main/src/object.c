/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krambono <krambono@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 15:12:58 by krambono          #+#    #+#             */
/*   Updated: 2020/12/07 17:55:43 by krambono         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	create_vao(t_object *obj)
{
	glBindVertexArray(obj->vao);
	glBindBuffer(GL_ARRAY_BUFFER, obj->vbo);
	glBufferData(GL_ARRAY_BUFFER, obj->nb_elements * 5 * sizeof(float),
	obj->vbo_data, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float),
	(void *)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float),
	(void *)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
	glBindVertexArray(0);
}

int		set_uniform_matrices(t_object *obj)
{
	t_mat4x4 view;
	t_mat4x4 projection;

	glUseProgram(obj->program);
	view = g_mati4;
	projection = perspective(deg_to_rad(30), (float)SCOP_WIN_WIDTH /
				(float)SCOP_WIN_HEIGHT, 0.1f, 100.0f);
	view = translate(&g_mati4, get_vec3(0, 0, -3));
	if (!uniform_set_mat4x4(obj->program, "projection", &projection))
		return (0);
	if (!uniform_set_mat4x4(obj->program, "view", &view))
		return (0);
	return (1);
}

int		init_object(t_object *obj)
{
	glGenVertexArrays(1, &obj->vao);
	glGenBuffers(1, &obj->vbo);
	if (!create_program(&obj->program, "main/shaders/shader.vert",
		"main/shaders/shader.frag"))
		return (0);
	if (!set_uniform_matrices(obj))
		return (0);
	if (!get_texture("resources/unicorn.bmp", obj))
		return (0);
	create_vao(obj);
	return (1);
}

void	clean_object(t_object *obj)
{
	if (obj->vbo_data)
		free(obj->vbo_data);
	if (obj->vertices)
		free(obj->vertices);
	if (obj->program)
		glDeleteProgram(obj->program);
	if (obj->vao)
		glDeleteVertexArrays(1, &obj->vao);
	if (obj->vbo)
		glDeleteBuffers(1, &obj->vbo);
	if (obj->texture)
		glDeleteTextures(1, &obj->texture);
	ft_bzero(obj, sizeof(t_object));
}
