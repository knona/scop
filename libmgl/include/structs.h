/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krambono <krambono@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 11:17:51 by krambono          #+#    #+#             */
/*   Updated: 2020/12/04 11:21:41 by krambono         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MGL_STRUCTS_H
# define MGL_STRUCTS_H

struct					s_mat2x2
{
	float m00;
	float m01;
	float m10;
	float m11;
};

struct					s_mat3x3
{
	float m00;
	float m01;
	float m02;
	float m10;
	float m11;
	float m12;
	float m20;
	float m21;
	float m22;
};

struct					s_mat4x4
{
	float m00;
	float m01;
	float m02;
	float m03;
	float m10;
	float m11;
	float m12;
	float m13;
	float m20;
	float m21;
	float m22;
	float m23;
	float m30;
	float m31;
	float m32;
	float m33;
};

struct					s_vec2
{
	float x;
	float y;
};

struct					s_vec3
{
	float x;
	float y;
	float z;
};

struct					s_vec4
{
	float x;
	float y;
	float z;
	float w;
};

typedef struct s_mat2x2	t_mat2x2;
typedef struct s_mat3x3	t_mat3x3;
typedef struct s_mat4x4	t_mat4x4;
typedef struct s_vec2	t_vec2;
typedef struct s_vec3	t_vec3;
typedef struct s_vec4	t_vec4;

#endif
