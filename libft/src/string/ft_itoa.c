/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: krambono <krambono@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 19:27:08 by krambono     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/26 22:08:56 by krambono    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa(int n)
{
	int		mul;
	int		neg;
	int		i;
	char	*str;

	i = -1;
	mul = 1;
	neg = n < 0 ? -1 : 1;
	while ((n < 0 && n / mul <= -10) || (n > 0 && n / mul >= 10))
	{
		mul *= 10;
		i++;
	}
	if (!(str = malloc(sizeof(char) * (i + 1 + (n < 0)))))
		return (NULL);
	str[0] = n < 0 ? '-' : ' ';
	i = n < 0 ? 1 : 0;
	while (mul >= 1)
	{
		str[i++] = (n / mul * neg) + '0';
		n %= mul;
		mul /= 10;
	}
	str[i] = '\0';
	return (str);
}
