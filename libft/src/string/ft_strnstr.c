/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnstr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: krambono <krambono@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/26 19:48:45 by krambono     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/26 19:56:33 by krambono    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t i;
	size_t len_needle;
	size_t len_haystack;
	size_t limit;

	i = 0;
	len_needle = ft_strlen(needle);
	len_haystack = ft_strlen(haystack);
	limit = len_haystack < n ? len_haystack : n;
	while (i < limit - len_needle + 1)
	{
		if (!ft_strncmp(haystack + i, needle, len_needle))
			return ((char*)haystack + i);
		i++;
	}
	return (NULL);
}
