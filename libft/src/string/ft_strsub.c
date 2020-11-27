/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krambono <krambono@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 17:24:56 by krambono          #+#    #+#             */
/*   Updated: 2020/11/27 17:39:06 by krambono         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*dest;

	if (!(dest = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	dest[len] = '\0';
	ft_memcpy(dest, s + start, len);
	return (dest);
}
