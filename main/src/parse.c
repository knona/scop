#include "scop.h"

int add_vertex(t_object *obj, const float *vec)
{
	int nb_buffers;

	if (obj->vertices_max_size < obj->vertices_size + 1)
	{
		nb_buffers = ((obj->vertices_size + 1) / SCOP_VERTICES_BUFFER) + 1;
		if (!(obj->vertices = (float *)realloc(
				  obj->vertices, 3 * sizeof(float) * SCOP_VERTICES_BUFFER * nb_buffers)))
			return (error_0("Malloc error"));
		obj->vertices_max_size = nb_buffers * SCOP_VERTICES_BUFFER;
	}
	ft_memcpy(obj->vertices + obj->vertices_size, vec, 3 * sizeof(float));
	obj->vertices_size += 3;
	return (1);
}

int add_indices(t_object *obj, const uint *indices)
{
	int nb_buffers;

	if (obj->indices_max_size < obj->indices_size + 1)
	{
		nb_buffers = (obj->indices_size + 1) / SCOP_INDICES_BUFFER + 1;
		if (!(obj->indices = (uint *)realloc(
				  obj->indices, 3 * sizeof(uint) * SCOP_INDICES_BUFFER * nb_buffers)))
			return (error_0("Malloc error"));
		obj->indices_max_size = nb_buffers * SCOP_INDICES_BUFFER;
	}
	ft_memcpy(obj->indices + obj->indices_size, indices, 3 * sizeof(uint));
	obj->indices_size += 3;
	return (1);
}

int process_vertex(t_object *obj, const char *line)
{
	int   i;
	int   j;
	float vertex[3];
	char *end;

	i = 0;
	j = 0;
	while (j < 3)
	{
		vertex[j] = strtof(line + i, &end);
		i = end - line;
		j++;
	}
	if (!add_vertex(obj, vertex))
		return (0);
	return (1);
}

int process_indices(t_object *obj, const char *line)
{
	int   i;
	int   j;
	uint  indices[4];
	char *end;

	i = 0;
	j = 0;
	while (j < 3)
	{
		indices[j++] = strtoul(line + i, &end, 10) - 1;
		i = end - line;
		while (line[i] && line[i] != ' ')
			i++;
	}
	if (!add_indices(obj, indices))
		return (0);
	while (line[i] == ' ')
		i++;
	if (line[i] != '\0')
	{
		indices[1] = strtoul(line + i, &end, 10) - 1;
		if (!add_indices(obj, indices))
			return (0);
	}
	return (1);
}

int process_line(t_object *obj, char *line)
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
		if (!process_indices(obj, line + 2))
			return (0);
	}
	return (1);
}

int parse_obj_file(const char *path, t_object *obj)
{
	int   fd;
	int   ret;
	char *line;

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
