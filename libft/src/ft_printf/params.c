/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   params.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: krambono <krambono@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/05 12:05:15 by krambono     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/26 20:48:47 by krambono    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** void	print_params(t_params *params)
** {
** 	int i;
**
**	printf("PARAMS DEBUG ---\n");
**	printf("Flags:\n");
**	i = 0;
**	while (params->flags[i])
**		printf("|%c| ", params->flags[i++]);
**	printf("\n");
**	printf("Width: %d\n", params->width);
**	printf("Precision: %d\n", params->precision);
**	printf("Length: %c\n", params->length);
**	printf("Specifier: %c\n", params->specifier);
**	printf("----------------\n");
**}
*/

void	init_params(t_params *params)
{
	ft_bzero(params, sizeof(*params));
	params->precision = -1;
}

int		flag_exists(const char *flags, char flag)
{
	int i;

	i = 0;
	while (flags[i])
	{
		if (flags[i] == flag)
			return (1);
		i++;
	}
	return (0);
}

void	rm_flag(char *flags, char flag)
{
	char	tmp[5];
	int		i;
	int		j;

	ft_bzero(&tmp, sizeof(tmp));
	i = 0;
	j = 0;
	while (flags[i])
	{
		if (flags[i] != flag)
			tmp[j++] = flags[i];
		i++;
	}
	i = -1;
	while (++i < 5)
		flags[i] = tmp[i] ? tmp[i] : '\0';
}

void	valid_params(t_params *params)
{
	if (flag_exists(params->flags, '0') && flag_exists(params->flags, '-'))
		rm_flag(params->flags, '0');
	if (flag_exists(params->flags, ' ') && (flag_exists(params->flags, '0')
		|| flag_exists(params->flags, '+')))
		rm_flag(params->flags, ' ');
	if (params->specifier == 's' || params->specifier == 'c'
		|| params->specifier == 'p')
	{
		rm_flag(params->flags, '+');
		rm_flag(params->flags, '0');
		rm_flag(params->flags, ' ');
		params->length = '\0';
		if (params->specifier != 's')
			params->precision = -1;
	}
	if (params->specifier == 'o' || params->specifier == 'x' ||
		params->specifier == 'X' || params->specifier == 'u' ||
		params->specifier == 'b')
	{
		rm_flag(params->flags, '+');
		rm_flag(params->flags, ' ');
	}
}
