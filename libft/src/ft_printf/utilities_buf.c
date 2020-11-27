/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_buf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krambono <krambono@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 12:04:30 by krambono          #+#    #+#             */
/*   Updated: 2020/11/27 17:35:10 by krambono         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	write_char_buf(char c)
{
	ft_handle_buf(&c, 1, FTPF_BUFF_WRITE, NULL);
}

void	write_str_buf(char *str)
{
	ft_handle_buf(str, ft_strlen(str), FTPF_BUFF_WRITE, NULL);
}

void	write_str_buf_n(char *str, int n)
{
	ft_handle_buf(str, n, FTPF_BUFF_WRITE, NULL);
}

void	base_buf(__uint128_t nb, char *base, int base_len, int k)
{
	if (nb == 0 && !k)
		return ;
	base_buf(nb / base_len, base, base_len, 0);
	write_char_buf(base[nb % base_len]);
}

void	write_num_buf(__int128_t nb, char *base)
{
	if (nb < 0)
	{
		write_char_buf('-');
		nb = -nb;
	}
	base_buf(nb, base, ft_strlen(base), 1);
}
