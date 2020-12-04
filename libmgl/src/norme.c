/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norme.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krambono <krambono@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 11:14:34 by krambono          #+#    #+#             */
/*   Updated: 2020/12/04 11:16:31 by krambono         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mgl.h"

float	get_norme(const void *vec, int size)
{
	int		i;
	float	sum;

	i = 0;
	sum = 0;
	while (i < size)
	{
		sum += ((float *)vec)[i] * ((float *)vec)[i];
		i++;
	}
	return (sqrtf(sum));
}

void	normalize(void *vec, int size)
{
	int		i;
	float	norme;

	norme = get_norme(vec, size);
	i = 0;
	while (i < size)
	{
		((float *)vec)[i] /= norme;
		i++;
	}
}
