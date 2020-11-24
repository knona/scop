/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memmove.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: krambono <krambono@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 13:50:19 by krambono     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/26 21:13:43 by krambono    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t					i;

	if (dst < src)
		ft_memcpy(dst, src, len);
	else
	{
		i = 1;
		while (i <= len)
		{
			((unsigned char*)dst)[len - i] = ((unsigned char*)src)[len - i];
			i++;
		}
	}
	return (dst);
}
