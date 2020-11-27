/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krambono <krambono@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 11:27:47 by krambono          #+#    #+#             */
/*   Updated: 2020/11/27 17:35:42 by krambono         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	clear_list(t_list **list)
{
	t_list *tmp;

	while (*list)
	{
		tmp = (*list)->next;
		free(tmp);
		*list = tmp;
	}
}

t_list	*create_node(void)
{
	t_list *list;

	if (!(list = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	list->index_lf = -1;
	list->len = 0;
	list->next = NULL;
	return (list);
}

void	add_node(t_list **list, t_list *new)
{
	t_list *tmp;

	if (!*list)
	{
		*list = new;
		return ;
	}
	tmp = *list;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}
