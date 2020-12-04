/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krambono <krambono@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 11:13:01 by krambono          #+#    #+#             */
/*   Updated: 2020/12/04 11:14:18 by krambono         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mgl.h"

t_mat4x4	perspective(float fovy, float aspect, float near, float far)
{
	float		top;
	float		bottom;
	float		left;
	float		right;
	t_mat4x4	proj;

	proj = g_mat04;
	top = tanf(fovy) * near;
	right = aspect * top;
	left = -right;
	bottom = -top;
	proj.m00 = near / right;
	proj.m11 = near / top;
	proj.m22 = -(far + near) / (far - near);
	proj.m23 = -1;
	proj.m32 = -2 * far * near / (far - near);
	return (proj);
}

t_mat4x4	ortho(float left, float right, float bottom, float top)
{
	t_mat4x4 proj;

	proj = g_mati4;
	proj.m00 = 2.0f / (right - left);
	proj.m11 = 2.0f / (top - bottom);
	proj.m22 = -1.0f;
	proj.m30 = -(right + left) / (right - left);
	proj.m31 = -(top + bottom) / (top - bottom);
	return (proj);
}
