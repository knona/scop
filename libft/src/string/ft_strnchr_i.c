/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnchr_i.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: krambono <krambono@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/26 19:47:28 by krambono     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/27 13:22:28 by krambono    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnchr_i(const char *str, char c, size_t n)
{
	size_t i;

	i = 0;
	while (str[i] && i < n)
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}
