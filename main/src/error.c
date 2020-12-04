/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krambono <krambono@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 11:38:18 by krambono          #+#    #+#             */
/*   Updated: 2020/12/04 11:40:20 by krambono         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	error(const char *format, va_list ap)
{
	ft_dprintf(2, "\033[31mError:\033[0m ");
	ft_vdprintf(2, format, ap);
	ft_dprintf(2, "\n");
	if (errno != 0)
		perror(NULL);
}

int		error_int(int ret, const char *format, ...)
{
	va_list ap;

	va_start(ap, format);
	error(format, ap);
	va_end(ap);
	return (ret);
}

int		error_0(const char *format, ...)
{
	va_list ap;

	va_start(ap, format);
	error(format, ap);
	va_end(ap);
	return (0);
}

char	*error_null(const char *format, ...)
{
	va_list ap;

	va_start(ap, format);
	error(format, ap);
	va_end(ap);
	return (NULL);
}
