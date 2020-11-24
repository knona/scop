/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: krambono <krambono@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/05 12:05:03 by krambono     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/26 20:52:46 by krambono    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		my_printf(const char *format, va_list ap)
{
	int			i;
	int			temp;
	t_params	params;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (parse_format(format + i + 1, &params, &i, ap))
			{
				valid_params(&params);
				write_arg(&params, ap);
			}
		}
		else
		{
			temp = i;
			while (format[i] && format[i] != '%')
				i++;
			if (temp != i)
				ft_handle_buf(format + temp, i - temp, FTPF_BUFF_WRITE, NULL);
		}
	}
	return (ft_handle_buf(NULL, 0, FTPF_BUFF_READ, NULL));
}
