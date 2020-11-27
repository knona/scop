/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krambono <krambono@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 16:36:15 by krambono          #+#    #+#             */
/*   Updated: 2020/11/27 17:36:19 by krambono         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_memprint(const void *src, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		if (i != 0)
			ft_printf(" ");
		ft_printf("%02X", ((const unsigned char*)src)[i]);
		i++;
	}
	ft_printf("\n");
}
