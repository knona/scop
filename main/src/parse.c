#include "scop.h"

int add_vertex(t_object *obj, const t_vec3 *vec)
{
	static int vertices_max_size = 0;
	static int vertices_size = 0;
	int        nb_buffers;

	if (vertices_size + 1 > vertices_max_size)
	{
		nb_buffers = (vertices_size + 1) / SCOP_ELEMENTS_BUFFER + 1;
		if (!(obj->vertices = (t_vec3 *)realloc(
				  obj->vertices, sizeof(t_vec3) * SCOP_ELEMENTS_BUFFER * nb_buffers)))
			return (error_0("Malloc error"));
		vertices_max_size = nb_buffers * SCOP_ELEMENTS_BUFFER;
	}
	ft_memcpy(obj->vertices + vertices_size, vec, sizeof(t_vec3));
	vertices_size++;
	return (1);
}

int add_vbo_element(t_object *obj, const uint *indices, t_vec2 *coord)
{
	static int   vbo_max_size = 0;
	static int   vbo_size = 0;
	const t_vec2 coords[3] = { { 0, 1 }, { coord->x, coord->y }, { 1, 0 } };
	int          nb_buffers;
	int          i;

	if (vbo_size + 3 > vbo_max_size)
	{
		nb_buffers = (vbo_size + 3) / SCOP_ELEMENTS_BUFFER + 1;
		if (!(obj->vbo_data = (float *)realloc(
				  obj->vbo_data, 5 * sizeof(float) * SCOP_ELEMENTS_BUFFER * nb_buffers)))
			return (error_0("Malloc error"));
		vbo_max_size = nb_buffers * SCOP_ELEMENTS_BUFFER;
	}
	i = 0;
	while (i < 3)
	{
		ft_memcpy(obj->vbo_data + vbo_size * 5, obj->vertices + indices[i], sizeof(t_vec3));
		ft_memcpy(obj->vbo_data + vbo_size * 5 + 3, coords + i, sizeof(t_vec2));
		vbo_size++;
		i++;
	}
	obj->nb_elements = vbo_size;
	return (1);
}

void get_max_range(t_object *obj, t_vec3 *vertex)
{
	static int first = 1;

	if (first)
	{
		obj->range.x_max = vertex->x;
		obj->range.x_min = vertex->x;
		obj->range.y_max = vertex->y;
		obj->range.y_min = vertex->y;
		obj->range.z_max = vertex->z;
		obj->range.z_min = vertex->z;
		first = 0;
	}
	else
	{
		if (vertex->x > obj->range.x_max)
			obj->range.x_max = vertex->x;
		if (vertex->x < obj->range.x_min)
			obj->range.x_min = vertex->x;
		if (vertex->y > obj->range.y_max)
			obj->range.y_max = vertex->y;
		if (vertex->y < obj->range.y_min)
			obj->range.y_min = vertex->y;
		if (vertex->z > obj->range.z_max)
			obj->range.z_max = vertex->z;
		if (vertex->z < obj->range.z_min)
			obj->range.z_min = vertex->z;
	}
}

int process_vertex(t_object *obj, const char *line)
{
	int    i;
	int    j;
	t_vec3 vertex;
	char * end;

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

int process_face(t_object *obj, const char *line)
{
	int    i;
	int    j;
	uint   indices[4];
	t_vec2 coord;
	char * end;

	i = 0;
	j = 0;
	while (j < 3)
	{
		indices[j++] = strtoul(line + i, &end, 10) - 1;
		i = end - line;
		while (line[i] && line[i] != ' ')
			i++;
	}
	coord.x = 1;
	coord.y = 1;
	if (!add_vbo_element(obj, indices, &coord))
		return (0);
	while (line[i] == ' ')
		i++;
	if (line[i] != '\0')
	{
		indices[1] = strtoul(line + i, &end, 10) - 1;
		coord.x = 0;
		coord.y = 0;
		if (!add_vbo_element(obj, indices, &coord))
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
		if (!process_face(obj, line + 2))
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
	free(obj->vertices);
	obj->vertices = NULL;
	close(fd);
	return (1);
}
