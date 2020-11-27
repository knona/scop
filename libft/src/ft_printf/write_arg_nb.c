/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_arg_nb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krambono <krambono@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 12:05:47 by krambono          #+#    #+#             */
/*   Updated: 2020/11/27 17:35:25 by krambono         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	write_arg_nb3_2(t_params *params, int total_len)
{
	int width;

	width = params->width + 1;
	while (--width > total_len)
		write_char_buf(' ');
}

static void	write_arg_nb3_1(t_params *params, char is_neg, int len_nb)
{
	int precision;

	arg_first_char(params, is_neg);
	precision = params->precision + 1;
	while (--precision > len_nb)
		write_char_buf('0');
}

static void	write_arg_nb2(t_params *params, char is_neg,
			int total_len, int len_nb)
{
	int width;
	int precision;

	if (params->precision != -1)
	{
		width = params->width + 1;
		while (--width > total_len)
			write_char_buf(' ');
		arg_first_char(params, is_neg);
		precision = params->precision + 1;
		while (--precision > len_nb)
			write_char_buf('0');
	}
	else
	{
		if (flag_exists(params->flags, '0'))
			arg_first_char(params, is_neg);
		width = params->width + 1;
		while (--width > total_len)
			write_char_buf(flag_exists(params->flags, '0') ? '0' : ' ');
		if (!flag_exists(params->flags, '0'))
			arg_first_char(params, is_neg);
	}
}

void		write_arg_nb(t_params *params, __int128_t nb)
{
	char	*base;
	int		len_nb;
	int		first_char;
	int		total_len;
	char	is_neg;

	get_base(&base, params);
	is_neg = nb < 0 ? 1 : 0;
	nb = nb < 0 ? -nb : nb;
	len_nb = nb_digit(nb, base);
	first_char = params->specifier == 'p' ? 2 : is_neg || (flag_exists(
	params->flags, '+') && !is_neg) || flag_exists(params->flags, ' ');
	total_len = ft_max(params->precision, len_nb) + first_char;
	if (!flag_exists(params->flags, '-'))
	{
		write_arg_nb2(params, is_neg, total_len, len_nb);
		write_num_buf(nb, base);
	}
	else
	{
		write_arg_nb3_1(params, is_neg, len_nb);
		write_num_buf(nb, base);
		write_arg_nb3_2(params, total_len);
	}
}
