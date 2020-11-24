/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strdup.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: krambono <krambono@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/26 19:48:02 by krambono     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/27 13:18:36 by krambono    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*new;
	size_t	len;

	len = ft_strlen(src);
	if (!(new = (char*)malloc((len + 1) * sizeof(char))))
		return (NULL);
	ft_memcpy(new, src, len);
	new[len] = '\0';
	return (new);
}
