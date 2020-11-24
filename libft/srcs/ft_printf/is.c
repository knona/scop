/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   is.c                                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: krambono <krambono@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/05 12:04:08 by krambono     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/27 13:21:59 by krambono    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

char	is_specifier(char c)
{
	const char *specifiers = "duxXopbcs";

	return (ft_strchr_i(specifiers, c) != -1);
}

char	is_flag(char c)
{
	const char *flags = " 0-+";

	return (ft_strchr_i(flags, c) != -1);
}

char	is_length(char c)
{
	const char *length = "hl";

	return (ft_strchr_i(length, c) != -1);
}

char	is_auth(char c)
{
	return (is_specifier(c) || is_flag(c) || is_length(c));
}
