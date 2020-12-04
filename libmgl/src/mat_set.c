/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krambono <krambono@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 11:14:29 by krambono          #+#    #+#             */
/*   Updated: 2020/12/04 11:14:30 by krambono         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mgl.h"

void	mat2x2set(t_mat2x2 *mat, int x, int y, float value)
{
	((float *)mat)[x * 2 + y] = value;
}

void	mat3x3set(t_mat3x3 *mat, int x, int y, float value)
{
	((float *)mat)[x * 3 + y] = value;
}

void	mat4x4set(t_mat4x4 *mat, int x, int y, float value)
{
	((float *)mat)[x * 4 + y] = value;
}
