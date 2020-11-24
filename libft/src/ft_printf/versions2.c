/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   versions2.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: krambono <krambono@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/05 12:04:43 by krambono     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/26 19:46:17 by krambono    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_sprintf(char *str, size_t size, const char *format, ...)
{
	va_list		ap;
	int			len;
	t_settings	settings;

	ft_bzero(&settings, sizeof(settings));
	settings.str_out = 1;
	settings.str = str;
	settings.size = size;
	ft_handle_buf(NULL, 0, FTPF_SETTINGS, &settings);
	va_start(ap, format);
	len = my_printf(format, ap);
	va_end(ap);
	return (len);
}

int		ft_vsprintf(char *str, size_t size, const char *format, va_list ap)
{
	t_settings	settings;

	ft_bzero(&settings, sizeof(settings));
	settings.str_out = 1;
	settings.str = str;
	settings.size = size;
	ft_handle_buf(NULL, 0, FTPF_SETTINGS, &settings);
	return (my_printf(format, ap));
}
