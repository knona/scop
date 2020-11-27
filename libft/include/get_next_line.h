/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krambono <krambono@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 11:29:35 by krambono          #+#    #+#             */
/*   Updated: 2020/11/27 17:39:48 by krambono         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "libft.h"
# include <stdlib.h>
# include <unistd.h>

struct						s_list
{
	int						index_lf;
	int						len;
	int						ret;
	char					buf[GNL_BUFF_SIZE];
	struct s_list			*next;
};
typedef struct s_list		t_list;

struct						s_list_infos
{
	t_list					*list;
	size_t					line_size;
};
typedef struct s_list_infos	t_list_infos;

/*
** LIST
*/
void						clear_list(t_list **list);
t_list						*create_node(void);
void						add_node(t_list **list, t_list *new);

#endif
