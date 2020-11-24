/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strndup.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: krambono <krambono@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/26 19:48:37 by krambono     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/27 13:18:03 by krambono    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *src, size_t n)
{
	char	*new;
	size_t	len;
	size_t	min;

	len = ft_strlen(src);
	min = len < n ? len : n;
	if (len < n)
		return (ft_strdup(src));
	else
	{
		if (!(new = (char*)malloc((min + 1) * sizeof(char))))
			return (NULL);
		ft_memcpy(new, src, min);
		new[min] = '\0';
		return (new);
	}
}
