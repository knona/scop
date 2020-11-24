/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: krambono <krambono@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/28 10:34:52 by krambono     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/28 15:31:05 by krambono    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

# define FTPF_BUFF_SIZE		100
# define FTPF_BUFF_WRITE	1
# define FTPF_BUFF_READ		2
# define FTPF_SETTINGS		3

typedef struct	s_params
{
	char		flags[5];
	int			width;
	int			precision;
	char		length;
	char		specifier;
}				t_params;

typedef struct	s_settings
{
	int			fd;
	char		str_out;
	char		*str;
	size_t		size;
}				t_settings;

typedef struct	s_buff_manager
{
	char		buf[FTPF_BUFF_SIZE];
	int			pos;
	int			cycle;
	t_settings	*sets;
}				t_buff_manager;

int				my_printf(const char *format, va_list ap);
int				ft_handle_buf(const char *str, int len, int choice,
				t_settings *settings);

/*
** BUF
*/
int				ft_handle_buf(const char *str, int len, int choice,
				t_settings *settings);
void			write_char_buf(char c);
void			write_num_buf(__int128_t nb, char *base);
void			write_str_buf(char *str);
void			write_str_buf_n(char *str, int n);

/*
** IS
*/
char			is_specifier(char c);
char			is_flag(char c);
char			is_length(char c);
char			is_auth(char c);

/*
** PARSE
*/
void			read_flags(const char *format, t_params *params, int *i);
void			read_width(const char *format, t_params *params, int *i,
				va_list ap);
void			read_precision(const char *format, t_params *params, int *i,
				va_list ap);
void			read_length(const char *format, t_params *params, int *i);
int				parse_format(const char *format, t_params *params, int *index,
				va_list ap);

/*
** PARAMS
**void			print_params(t_params *params);
*/
void			init_params(t_params *params);
int				flag_exists(const char *flags, char flag);
void			rm_flag(char *flags, char flag);
void			valid_params(t_params *params);

/*
** WRITE_ARG
*/
void			write_arg(t_params *params, va_list ap);
void			write_arg_nb(t_params *params, __int128_t nb);
void			write_arg_unb(t_params *params, va_list ap);
void			write_arg_snb(t_params *params, va_list ap);
void			write_arg_p(t_params *params, va_list ap);
void			write_arg_str(t_params *params, va_list ap);
void			write_arg_str2(t_params *params, char *str);
void			write_arg_c(t_params *params, va_list ap);
void			write_arg_c2(t_params *params, char c);

/*
** UTILITIES
*/
unsigned int	min_zero(int a, int b);
unsigned int	nb_digit(__int128_t nb, char *base);
void			get_base(char **base, t_params *params);
void			arg_first_char(t_params *params, char is_neg);

#endif
