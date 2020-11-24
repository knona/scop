/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_options.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: krambono <krambono@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/01 14:34:03 by krambono     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/01 14:46:59 by krambono    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

/*
**	MAN
**
**	__uint32__t	options;
**	char		*valid = "agdlHPm1";
**
**	ft_optparse(&options, argc - 1, argv + 1, valid); // parse args and get
**	// options
**	ft_opttest(0, 0, valid); // set the static with "valid" value
**	// must be called 1 time at start
**	ft_opttest(options, c, NULL) // next you can call the function
**	// with your char and options
*/

static int	print_error(char c)
{
	if (c != -1)
		ft_dprintf(2, "illegal option -- '%c'\n", c);
	else
		ft_dprintf(2, "illegal option -- ''\n");
	return (0);
}

void		ft_optprint(__uint32_t options, const char *valid)
{
	int i;
	int k;
	int len;

	ft_printf("options: |");
	i = 0;
	len = ft_strlen(valid);
	k = 0;
	while (i < len)
	{
		if (options & (__uint32_t)1 << i)
		{
			ft_printf(k == 0 ? "%c" : " %c", valid[i]);
			k = 1;
		}
		i++;
	}
	ft_printf("|\n");
}

int			ft_opttest(__uint32_t options, char c, const char *valid)
{
	static const char	*valid_store;
	int					index;

	if (valid)
		valid_store = valid;
	index = ft_strchr_i(valid_store, c);
	return (index == -1 ? 0 : !!(options & ((__uint32_t)1 << index)));
}

int			ft_optparse(__uint32_t *options, int ac, char **av,
			const char *valid)
{
	int i;
	int j;
	int index;

	*options = 0;
	i = -1;
	while (++i < ac)
	{
		if (!ft_strcmp(av[i], "--"))
			break ;
		if (av[i][0] == '-')
		{
			j = 1;
			if (av[i][1] == '\0')
				return (print_error(-1));
			while (av[i][j])
			{
				if ((index = ft_strchr_i(valid, av[i][j])) == -1)
					return (print_error(av[i][j]));
				*options = *options | ((__uint32_t)1 << index);
				j++;
			}
		}
	}
	return (1);
}
