/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   write_arg2.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: krambono <krambono@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/05 12:04:53 by krambono     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/26 19:46:19 by krambono    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	write_arg_str2(t_params *params, char *str)
{
	int strlen;
	int width;

	strlen = params->precision == -1 ? (int)ft_strlen(str) :
	ft_min(ft_strlen(str), params->precision);
	if (flag_exists(params->flags, '-'))
		write_str_buf_n(str, strlen);
	width = params->width + 1;
	while (--width > strlen)
		write_char_buf(' ');
	if (!flag_exists(params->flags, '-'))
		write_str_buf_n(str, strlen);
}

void	write_arg_c2(t_params *params, char c)
{
	int width;

	if (flag_exists(params->flags, '-'))
		write_char_buf(c);
	width = params->width + 1;
	while (--width > 1)
		write_char_buf(' ');
	if (!flag_exists(params->flags, '-'))
		write_char_buf(c);
}

void	write_arg_str(t_params *params, va_list ap)
{
	char *str;

	str = (char *)va_arg(ap, void *);
	if (!str)
		str = "(null)";
	write_arg_str2(params, str);
}

void	write_arg_c(t_params *params, va_list ap)
{
	char c;

	c = (char)va_arg(ap, int);
	write_arg_c2(params, c);
}

void	write_arg_p(t_params *params, va_list ap)
{
	void *p;

	p = va_arg(ap, void*);
	write_arg_nb(params, (__uint64_t)p);
}
