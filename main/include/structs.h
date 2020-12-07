/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krambono <krambono@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 15:45:31 by krambono          #+#    #+#             */
/*   Updated: 2020/12/07 15:48:33 by krambono         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOP_STRUCTS_H
# define SCOP_STRUCTS_H

# include "glad/glad.h"
# include "mgl.h"

struct							s_range
{
	float x_min;
	float x_max;
	float y_min;
	float y_max;
	float z_min;
	float z_max;
};
typedef struct s_range			t_range;

struct							s_object
{
	GLuint	vao;
	GLuint	vbo;
	GLuint	program;
	GLuint	texture;
	float	*vbo_data;
	t_vec3	*vertices;
	int		vertices_size;
	int		nb_elements;
	t_range	range;
};
typedef struct s_object			t_object;

struct							s_cursor
{
	double x;
	double y;
};
typedef struct s_cursor			t_cursor;

struct							s_image_infos
{
	unsigned int	width;
	unsigned int	height;
	unsigned int	size;
	unsigned int	data_offset;
	unsigned char	*data;
};
typedef struct s_image_infos	t_image_infos;

struct							s_event_options
{
	t_object	*obj;
	t_vec3		pos;
	t_vec3		pos_cpy;
	t_cursor	curs_pos;
	double		time;
	float		rotx;
	int			scop_pause;
	int			line_mode;
	int			l_click;
	int			increase;
};
typedef struct s_event_options	t_event_options;

#endif
