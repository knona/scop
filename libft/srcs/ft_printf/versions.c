/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   versions.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: krambono <krambono@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/05 12:05:34 by krambono     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/26 19:46:16 by krambono    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	int			len;
	t_settings	settings;

	ft_bzero(&settings, sizeof(settings));
	settings.fd = 1;
	ft_handle_buf(NULL, 0, FTPF_SETTINGS, &settings);
	va_start(ap, format);
	len = my_printf(format, ap);
	va_end(ap);
	return (len);
}

int		ft_dprintf(int fd, const char *format, ...)
{
	va_list		ap;
	int			len;
	t_settings	settings;

	ft_bzero(&settings, sizeof(settings));
	settings.fd = fd;
	ft_handle_buf(NULL, 0, FTPF_SETTINGS, &settings);
	va_start(ap, format);
	len = my_printf(format, ap);
	va_end(ap);
	return (len);
}

int		ft_vprintf(const char *format, va_list ap)
{
	t_settings	settings;

	ft_bzero(&settings, sizeof(settings));
	settings.fd = 1;
	ft_handle_buf(NULL, 0, FTPF_SETTINGS, &settings);
	return (my_printf(format, ap));
}

int		ft_vdprintf(int fd, const char *format, va_list ap)
{
	t_settings	settings;

	ft_bzero(&settings, sizeof(settings));
	settings.fd = fd;
	ft_handle_buf(NULL, 0, FTPF_SETTINGS, &settings);
	return (my_printf(format, ap));
}
