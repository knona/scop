/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   write_arg.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: krambono <krambono@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/05 12:05:40 by krambono     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/26 19:46:19 by krambono    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	write_arg_unb(t_params *params, va_list ap)
{
	__int128_t nb;

	if (params->length == 'l')
		nb = (unsigned long)va_arg(ap, unsigned long);
	else if (params->length == 'h')
		nb = (unsigned short)va_arg(ap, unsigned int);
	else if (params->length == 'H')
		nb = (unsigned char)va_arg(ap, unsigned int);
	else
		nb = (unsigned int)va_arg(ap, unsigned int);
	write_arg_nb(params, nb);
}

void	write_arg_snb(t_params *params, va_list ap)
{
	__int128_t	nb;

	if (params->length == 'l')
		nb = (long)va_arg(ap, long);
	else if (params->length == 'h')
		nb = (short)va_arg(ap, int);
	else if (params->length == 'H')
		nb = (char)va_arg(ap, int);
	else
		nb = (int)va_arg(ap, int);
	write_arg_nb(params, nb);
}

void	write_arg(t_params *params, va_list ap)
{
	if (params->specifier == 'd')
		write_arg_snb(params, ap);
	else if (params->specifier == 'u' || params->specifier == 'x' ||
			params->specifier == 'X' || params->specifier == 'o' ||
			params->specifier == 'b')
		write_arg_unb(params, ap);
	else if (params->specifier == 'p')
		write_arg_p(params, ap);
	else if (params->specifier == 'c')
		write_arg_c(params, ap);
	else if (params->specifier == 's')
		write_arg_str(params, ap);
}
