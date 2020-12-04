/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krambono <krambono@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 11:10:45 by krambono          #+#    #+#             */
/*   Updated: 2020/12/04 11:15:17 by krambono         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mgl.h"

void	print_vec(void *vec, int vec_size)
{
	int		i;
	char	*properties;

	properties = "xyzw";
	i = 0;
	while (i < vec_size)
	{
		if (i != 0)
			printf(" ; ");
		printf("%c: %6.2f", properties[i], ((float *)vec)[i]);
		i++;
	}
	printf("\n");
}

void	print_mat(void *mat, int mat_size)
{
	int i;
	int j;

	i = 0;
	while (i < mat_size)
	{
		j = 0;
		while (j < mat_size)
		{
			if (j != 0)
				printf(" ");
			printf("%15f", ((float *)mat)[j * mat_size + i]);
			j++;
		}
		printf("\n");
		i++;
	}
}
