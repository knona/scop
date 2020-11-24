/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsplit.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: krambono <krambono@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 18:39:57 by krambono     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/26 22:03:30 by krambono    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static char	**clear_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	return (NULL);
}

static int	count_words(char const *s, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	if (s[i] != c && s[i] != '\0')
		count++;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			count++;
		i++;
	}
	return (count);
}

static char	*get_word(char const *s, char c, int *index)
{
	size_t len;

	s += *index;
	while (*s && *s == c)
	{
		(*index)++;
		s++;
	}
	if (!*s)
		return (NULL);
	len = 0;
	while (s[len] && s[len] != c)
	{
		len++;
		(*index)++;
	}
	return (ft_strndup(s, len));
}

char		**ft_strsplit(char const *s, char c)
{
	int		words;
	int		i;
	char	**tab;
	int		index;

	index = 0;
	if (!s)
		return (NULL);
	words = count_words(s, c);
	if (!(tab = (char **)malloc(sizeof(char *) * (words + 1))))
		return (NULL);
	ft_bzero(tab, sizeof(char *) * (words + 1));
	i = 0;
	while (i < words)
	{
		if (!(tab[i] = get_word(s, c, &index)))
			return (clear_tab(tab));
		i++;
	}
	tab[i] = 0;
	return (tab);
}
