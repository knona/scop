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

int process_line(t_object *obj, char *line)
{
	int    i;
	uint   indices[3];
	t_vec3 vec;
	char * end;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (line[i] == 'v' && line[i + 1] == ' ')
	{
		i += 2;
		vec.x = strtof(line + i, &end);
		i = end - line;
		vec.y = strtof(line + i, &end);
		i = end - line;
		vec.z = strtof(line + i, &end);
		if (!add_vertex(obj, (float *)&vec))
			return (0);
	}
	else if (line[i] == 'f' && line[i + 1] == ' ')
	{
		i += 2;
		indices[0] = strtoul(line + i, &end, 10) - 1;
		i = end - line;
		indices[1] = strtoul(line + i, &end, 10) - 1;
		i = end - line;
		indices[2] = strtoul(line + i, &end, 10) - 1;
		if (!add_indices(obj, indices))
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
