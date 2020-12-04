/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krambono <krambono@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 11:12:58 by krambono          #+#    #+#             */
/*   Updated: 2020/12/04 11:15:48 by krambono         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mgl.h"

t_mat4x4	translate(const t_mat4x4 *mat, t_vec3 vec)
{
	t_mat4x4 transf;

	transf = g_mati4;
	transf.m30 = vec.x;
	transf.m31 = vec.y;
	transf.m32 = vec.z;
	return (dotmm4x4(mat, &transf));
}

t_mat4x4	scale(const t_mat4x4 *mat, t_vec3 vec)
{
	t_mat4x4 transf;

	transf = g_mati4;
	transf.m00 = vec.x;
	transf.m11 = vec.y;
	transf.m22 = vec.z;
	return (dotmm4x4(mat, &transf));
}
