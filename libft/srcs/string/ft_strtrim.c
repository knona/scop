/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strtrim.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: krambono <krambono@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 17:48:12 by krambono     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/26 19:49:03 by krambono    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static void	find_index(char const *s, int *start, int *end)
{
	*start = 0;
	*end = 0;
	while ((s[*start] == ' ' || s[*start] == '\n' ||
				s[*start] == '\t') && s[*start])
		(*start)++;
	while (s[*end + 1])
		(*end)++;
	while ((s[*end] == ' ' || s[*end] == '\n' || s[*end] == '\t') && s[*end])
		(*end)--;
	if (*start >= *end)
	{
		*start = 0;
		*end = -1;
	}
}

char		*ft_strtrim(char const *s)
{
	char	*dest;
	int		start;
	int		end;
	int		i;

	if (!s)
		return (NULL);
	find_index(s, &start, &end);
	if (!(dest = (char *)malloc(sizeof(char) * (end - start + 2))))
		return (NULL);
	i = 0;
	while (i < end - start + 1)
	{
		dest[i] = s[i + start];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
