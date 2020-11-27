/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krambono <krambono@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 12:05:25 by krambono          #+#    #+#             */
/*   Updated: 2020/11/27 17:35:14 by krambono         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	min_zero(int a, int b)
{
	int min;

	min = a < b ? a : b;
	return (min < 0 ? 0 : min);
}

unsigned int	nb_digit2(__uint128_t nb, char *base, int base_len, int k)
{
	if (nb == 0 && !k)
		return (0);
	return (1 + nb_digit2(nb / base_len, base, base_len, 0));
}

unsigned int	nb_digit(__int128_t nb, char *base)
{
	char		neg;

	neg = 0;
	if (nb < 0)
	{
		neg = 1;
		nb = -nb;
	}
	return (nb_digit2(nb, base, ft_strlen(base), 1) + neg);
}

void			get_base(char **base, t_params *params)
{
	if (params->specifier == 'u' || params->specifier == 'd')
		*base = "0123456789";
	else if (params->specifier == 'x' || params->specifier == 'p')
		*base = "0123456789abcdef";
	else if (params->specifier == 'X')
		*base = "0123456789ABCDEF";
	else if (params->specifier == 'o')
		*base = "01234567";
	else if (params->specifier == 'b')
		*base = "01";
}

void			arg_first_char(t_params *params, char is_neg)
{
	if (is_neg)
		write_char_buf('-');
	if (flag_exists(params->flags, '+') && !is_neg)
		write_char_buf('+');
	if (flag_exists(params->flags, ' ') && !is_neg)
		write_char_buf(' ');
	if (params->specifier == 'p')
		write_str_buf_n("0x", 2);
}
