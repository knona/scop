/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: krambono <krambono@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/28 11:28:09 by krambono     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/28 11:29:15 by krambono    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

/*
** void	debug_buf(t_list *list, int index)
** {
** 	int		i;
**
** 	ft_printf("BUFF %d -----\n", index);
** 	ft_printf("ret: %d index_lf: %d len: %d\n", list->ret,
**  list->index_lf, list->len);
** 	ft_printf("content: |");
** 	i = 0;
** 	while (i < list->ret)
** 	{
** 		if (list->buf[i] == '\n')
** 			ft_putstr("\\n");
** 		else if (list->buf[i] == '\t')
** 			ft_putstr("\\t");
** 		else
** 			ft_putchar(list->buf[i]);
** 		i++;
** 	}
** 	ft_printf("|\n\n");
** }
*/

int		clean(t_list *el, t_list **list, int choice)
{
	if (choice == 1)
		free(el);
	clear_list(list);
	return (0);
}

int		read_file(const int fd, t_list_infos *infos)
{
	t_list	*node_reader;
	int		ret;
	int		index_lf;

	if (!(node_reader = create_node()))
		return (clean(NULL, &(infos->list), 0));
	while ((ret = read(fd, node_reader->buf, GNL_BUFF_SIZE)))
	{
		if (ret == -1)
			return (clean(node_reader, &(infos->list), 1));
		node_reader->ret = ret;
		index_lf = ft_strnchr_i(node_reader->buf, '\n', ret);
		node_reader->index_lf = index_lf;
		node_reader->len = index_lf == -1 ? ret : index_lf;
		infos->line_size += node_reader->len;
		add_node(&(infos->list), node_reader);
		if (!(node_reader = create_node()))
			return (clean(NULL, &(infos->list), 0));
		if (index_lf != -1)
			break ;
	}
	free(node_reader);
	return (1);
}

void	get_line2(t_list_infos *infos, t_list *list)
{
	size_t	new_len;

	infos->line_size = 0;
	infos->list = NULL;
	if (list->index_lf != -1)
	{
		if (list->index_lf == list->ret - 1)
			free(list);
		else
		{
			new_len = list->ret - list->index_lf - 1;
			ft_memmove(list->buf, list->buf + list->index_lf + 1, new_len);
			list->ret = new_len;
			list->index_lf = ft_strnchr_i(list->buf, '\n', new_len);
			list->len = list->index_lf == -1 ? (int)new_len : list->index_lf;
			infos->line_size = list->len;
			infos->list = list;
		}
	}
}

void	get_line(char **line, t_list_infos *infos)
{
	t_list	*tmp;
	t_list	*list;
	int		index;

	*line = (char *)malloc(sizeof(char) * (infos->line_size + 1));
	(*line)[infos->line_size] = '\0';
	if (!(list = infos->list))
	{
		infos->line_size = 0;
		return ;
	}
	index = 0;
	while (1)
	{
		tmp = list->next;
		ft_memcpy(*line + index, list->buf, list->len);
		index += list->len;
		if (tmp == NULL)
			break ;
		free(list);
		list = tmp;
	}
	get_line2(infos, list);
}

int		get_next_line(const int fd, char **line, const int behavior)
{
	static t_list_infos infos = {NULL, 0};

	if (behavior == GNL_FREE)
	{
		clear_list(&(infos.list));
		return (1);
	}
	if (fd < 0 || !line)
		return (-1);
	*line = NULL;
	if (infos.list)
	{
		if (infos.list->index_lf == -1 && !read_file(fd, &infos))
			return (-1);
	}
	else
	{
		if (!read_file(fd, &infos))
			return (-1);
		if (!infos.list)
			return (0);
	}
	get_line(line, &infos);
	return (1);
}
