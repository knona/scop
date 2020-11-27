/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krambono <krambono@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 12:03:52 by krambono          #+#    #+#             */
/*   Updated: 2020/11/27 17:34:42 by krambono         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_handle_buf2(t_buff_manager *manager, const char *str, int len)
{
	int rest;

	if (manager->pos + len <= FTPF_BUFF_SIZE)
	{
		ft_memcpy(manager->buf + manager->pos, str, len);
		manager->pos += len;
	}
	else
	{
		rest = FTPF_BUFF_SIZE - manager->pos;
		ft_memcpy(manager->buf + manager->pos, str, rest);
		write(manager->sets->fd, manager->buf, FTPF_BUFF_SIZE);
		manager->pos = 0;
		manager->cycle++;
		ft_handle_buf(str + rest, len - rest, FTPF_BUFF_WRITE, NULL);
	}
}

int		ft_handle_buf(const char *str, int len, int choice,
		t_settings *settings)
{
	static t_buff_manager	manager;
	int						total_len;

	if (choice == FTPF_SETTINGS)
	{
		manager.pos = 0;
		manager.cycle = 0;
		manager.sets = settings;
	}
	if (choice == FTPF_BUFF_READ && manager.sets->str_out == 0)
		write(manager.sets->fd, manager.buf, manager.pos);
	else if (choice == FTPF_BUFF_WRITE && manager.sets->str_out == 0)
		ft_handle_buf2(&manager, str, len);
	else if (choice == FTPF_BUFF_WRITE && manager.sets->str_out == 1)
	{
		total_len = manager.cycle * FTPF_BUFF_SIZE + manager.pos;
		ft_memcpy(manager.sets->str + total_len, str,
		min_zero((manager.sets->size - total_len), len));
		manager.pos += len;
	}
	return (manager.cycle * FTPF_BUFF_SIZE + manager.pos);
}
