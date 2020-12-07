/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krambono <krambono@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 15:13:32 by krambono          #+#    #+#             */
/*   Updated: 2020/12/07 15:39:23 by krambono         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int		process_vertex(t_object *obj, const char *line)
{
	int		i;
	int		j;
	t_vec3	vertex;
	char	*end;

	i = 0;
	j = 0;
	while (j < 3)
	{
		((float *)&vertex)[j] = strtof(line + i, &end);
		i = end - line;
		j++;
	}
	if (!add_vertex(obj, &vertex))
		return (0);
	get_max_range(obj, &vertex);
	return (1);
}

int		add_4th_vertex(t_object *obj, int *indices, const char *line, int i)
{
	while (line[i] == ' ')
		i++;
	if (line[i] != '\0')
	{
		indices[1] = strtoul(line + i, NULL, 10) - 1;
		if (indices[1] >= obj->vertices_size)
			return (1);
		if (!add_vbo_element(obj, indices, get_vec2(0, 0)))
			return (0);
	}
	return (1);
}

int		process_face(t_object *obj, const char *line)
{
	int		i;
	int		j;
	int		indices[4];
	char	*end;

	i = 0;
	j = 0;
	while (j < 3)
	{
		indices[j] = strtoul(line + i, &end, 10) - 1;
		if (indices[j] >= obj->vertices_size)
			return (1);
		i = end - line;
		while (line[i] && line[i] != ' ')
			i++;
		j++;
	}
	if (!add_vbo_element(obj, indices, get_vec2(1, 1)))
		return (0);
	if (!add_4th_vertex(obj, indices, line, i))
		return (0);
	return (1);
}

int		process_line(t_object *obj, char *line)
{
	int i;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (line[i] == 'v' && line[i + 1] == ' ')
	{
		if (!process_vertex(obj, line + i + 2))
			return (0);
	}
	else if (line[i] == 'f' && line[i + 1] == ' ')
	{
		if (!process_face(obj, line + 2))
			return (0);
	}
	return (1);
}

int		parse_obj_file(const char *path, t_object *obj)
{
	int		fd;
	int		ret;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (error_0("Cannot open file %s", path));
	while ((ret = get_next_line(fd, &line, GNL_READ)))
	{
		if (ret == -1)
		{
			get_next_line(0, NULL, GNL_FREE);
			return (error_0("Error while reading the .obj file: %s", path));
		}
		if (!process_line(obj, line))
		{
			free(line);
			return (0);
		}
		free(line);
	}
	close(fd);
	return (1);
}
