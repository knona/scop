/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krambono <krambono@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 11:17:40 by krambono          #+#    #+#             */
/*   Updated: 2020/11/27 17:35:05 by krambono         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	read_flags(const char *format, t_params *params, int *i)
{
	int		j;
	char	test;

	while (is_flag(format[*i]))
	{
		j = 0;
		test = 1;
		while (params->flags[j])
		{
			if (params->flags[j] == format[*i])
			{
				test = 0;
				break ;
			}
			j++;
		}
		if (test)
			params->flags[j] = format[*i];
		(*i)++;
	}
}

void	read_width(const char *format, t_params *params, int *i, va_list ap)
{
	int temp;

	if (format[*i] == '*')
	{
		params->width = va_arg(ap, int);
		if (params->width < 0)
			params->width = 0;
		(*i)++;
	}
	else
	{
		temp = *i;
		while (ft_isdigit(format[*i]))
		{
			(*i)++;
		}
		if (temp != (*i))
			params->width = ft_atoi(format + temp);
	}
}

void	read_precision(const char *format, t_params *params, int *i, va_list ap)
{
	int temp;

	(*i)++;
	if (format[*i] == '*')
	{
		params->precision = va_arg(ap, int);
		if (params->precision < -1)
			params->precision = -1;
		(*i)++;
	}
	else
	{
		temp = *i;
		while (ft_isdigit(format[*i]))
			(*i)++;
		if (temp != (*i))
			params->precision = ft_atoi(format + temp);
	}
}

void	read_length(const char *format, t_params *params, int *i)
{
	if (format[*i] == 'h')
	{
		if (format[++(*i)] == 'h')
		{
			params->length = 'H';
			(*i)++;
		}
		else
			params->length = 'h';
	}
	else if (format[*i] == 'l')
	{
		params->length = 'l';
		(*i)++;
	}
}

int		parse_format(const char *format, t_params *params, int *index,
		va_list ap)
{
	int		i;
	char	is_valid;

	init_params(params);
	i = 0;
	read_flags(format, params, &i);
	read_width(format, params, &i, ap);
	if (format[i] == '.')
		read_precision(format, params, &i, ap);
	read_length(format, params, &i);
	is_valid = 0;
	if (is_specifier(format[i]))
	{
		params->specifier = format[i];
		is_valid = 1;
	}
	if (!is_valid && format[0] == '%')
	{
		write_char_buf('%');
		*index += 2;
	}
	else
		*index += is_valid ? i + 2 : i + 1;
	return (is_valid);
}
