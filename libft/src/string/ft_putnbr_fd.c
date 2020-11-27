/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krambono <krambono@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 18:48:34 by krambono          #+#    #+#             */
/*   Updated: 2020/11/27 19:11:43 by krambono         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	recursive(int nb, int fd)
{
	if (nb == 0)
		return ;
	recursive(nb / 10, fd);
	ft_putchar_fd(nb % 10 + '0', fd);
}

void		ft_putnbr_fd(int nb, int fd)
{
	if (nb == 0)
		ft_putchar_fd('0', fd);
	else if (nb == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else
	{
		if (nb < 0)
		{
			ft_putchar_fd('-', fd);
			recursive(-nb, fd);
		}
		else
			recursive(nb, fd);
	}
}
