/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krambono <krambono@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 15:23:59 by krambono          #+#    #+#             */
/*   Updated: 2020/12/07 15:29:41 by krambono         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int		add_vertex(t_object *obj, const t_vec3 *vec)
{
	static int	vertices_max_size = 0;
	int			nb_buffers;

	if (obj->vertices_size + 1 > vertices_max_size)
	{
		nb_buffers = (obj->vertices_size + 1) / SCOP_ELEMENTS_BUFFER + 1;
		if (!(obj->vertices = (t_vec3 *)realloc(obj->vertices, sizeof(t_vec3)
			* SCOP_ELEMENTS_BUFFER * nb_buffers)))
			return (error_0("Malloc error"));
		vertices_max_size = nb_buffers * SCOP_ELEMENTS_BUFFER;
	}
	ft_memcpy(obj->vertices + obj->vertices_size, vec, sizeof(t_vec3));
	obj->vertices_size++;
	return (1);
}

int		add_vbo_element(t_object *obj, const int *indices, t_vec2 coord)
{
	static int		vbo_max_size = 0;
	static int		vbo_size = 0;
	const t_vec2	coords[3] = { { 0, 1 }, { coord.x, coord.y }, { 1, 0 } };
	int				nb_buffers;
	int				i;

	if (vbo_size + 3 > vbo_max_size)
	{
		nb_buffers = (vbo_size + 3) / SCOP_ELEMENTS_BUFFER + 1;
		if (!(obj->vbo_data = (float *)realloc(obj->vbo_data, 5 * sizeof(float)
			* SCOP_ELEMENTS_BUFFER * nb_buffers)))
			return (error_0("Malloc error"));
		vbo_max_size = nb_buffers * SCOP_ELEMENTS_BUFFER;
	}
	i = 0;
	while (i < 3)
	{
		ft_memcpy(obj->vbo_data + vbo_size * 5, obj->vertices + indices[i],
		sizeof(t_vec3));
		ft_memcpy(obj->vbo_data + vbo_size * 5 + 3, coords + i, sizeof(t_vec2));
		vbo_size++;
		i++;
	}
	obj->nb_elements = vbo_size;
	return (1);
}
