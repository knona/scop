/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchr_i.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krambono <krambono@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 19:47:28 by krambono          #+#    #+#             */
/*   Updated: 2020/11/27 17:38:32 by krambono         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnchr_i(const char *str, char c, size_t n)
{
	size_t i;

	i = 0;
	while (str[i] && i < n)
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}
