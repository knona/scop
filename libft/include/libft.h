/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libft.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: krambono <krambono@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/02 16:36:53 by rcepre       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/01 14:37:56 by krambono    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <stdarg.h>
# include "ft_limits.h"
# define GNL_READ 1
# define GNL_FREE 2
# define GNL_BUFF_SIZE 200

/*
****************************** STRINGS *****************************************
*/
char				*ft_itoa(int n);
int					ft_atoi(const char *str);
char				*ft_strstr(const char *s, const char *needle);
char				*ft_strnstr(const char *s, const char *needle, size_t len);
char				*ft_strnew(size_t size);
char				*ft_strsub(const char *s, unsigned int start, size_t len);
char				*ft_strtrim(const char *s);
char				**ft_strsplit(const char *s, char c);
char				*ft_strcat(char *dest, const char *src);
size_t				ft_strlen(const char *s);
char				*ft_strncat(char *dest, const char *src, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
void				ft_strclr(char *s);
char				*ft_strdup(const char *s);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dest, const char *src, size_t n);
void				ft_strdel(char **as);
char				*ft_strndup(const char *s, size_t n);
char				*ft_strjoin(char const *s1, char const *s2);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_strchr_i(const char *str, char c);
char				*ft_strchr(const char *str, char c);
int					ft_strnchr_i(const char *str, char c, size_t n);
char				*ft_strnchr(const char *str, char c, size_t n);
void				ft_putchar(char c);
void				ft_putnbr(int nb);
void				ft_putstr_fd(const char *s, int fd);
void				ft_putstr(const char *s);
void				ft_putendl(const char *s);
void				ft_putendl_fd(const char *s, int fd);
void				ft_putchar_fd(char c, int fd);
void				ft_putnbr_fd(int n, int fd);

/*
******************************* MEMORY *****************************************
*/
void				ft_bzero(void *s, size_t n);
void				*ft_memset(void *s, int c, size_t n);
void				ft_memprint(const void *src, size_t n);
void				ft_memdel(void **ap);
void				*ft_memalloc(size_t size);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);

/*
******************************** OTHER *****************************************
*/
int					ft_max(int a, int b);
int					ft_min(int a, int b);
void				ft_optprint(__uint32_t options, const char *valid);
int					ft_opttest(__uint32_t options, char c, const char *valid);
int					ft_optparse(__uint32_t *options, int ac, char **av,
					const char *valid);

/*
******************************** PRINTF ****************************************
*/
int					ft_printf(const char *format, ...)
					 __attribute__((format(printf,1,2)));
int					ft_dprintf(int fd, const char *format, ...)
					 __attribute__((format(printf,2,3)));
int					ft_vprintf(const char *format, va_list ap);
int					ft_vdprintf(int fd, const char *format, va_list ap);
int					ft_sprintf(char *str, size_t size, const char *format, ...)
					 __attribute__((format(printf,3,4)));
int					ft_vsprintf(char *str, size_t size, const char *format,
					va_list ap);

/*
********************************* GNL ******************************************
*/
int					get_next_line(const int fd, char **line,
					const int behavior);

#endif
