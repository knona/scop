#include "scop.h"

int parse_obj_file(const char *path, t_object *obj)
{
	int fd;

	ft_bzero(obj, sizeof(t_object));
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (error_0("Cannot open file %s", path));
	close(fd);
	return (1);
}
