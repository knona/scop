#include "scop.h"

int bmp_reader(const char *path, int fd, t_image_infos *infos)
{
	unsigned char header[54];
	long          ret;

	ret = read(fd, header, 54);
	if (ret == -1)
		return (error_0("Cannot read file %s", path));
	if (ret != 54 || header[0] != 'B' || header[1] != 'M')
		return (error_0("Invalid BMP file"));
	infos->data_offset = *(int *)(header + BMP_DATA_OFFSET);
	infos->size = *(int *)(header + BMP_SIZE);
	infos->width = *(int *)(header + BMP_WIDTH);
	infos->height = *(int *)(header + BMP_HEIGHT);
	if (!(infos->data = (unsigned char *)malloc(infos->size)))
		return (error_0("Malloc error"));
	lseek(fd, infos->data_offset, SEEK_SET);
	ret = read(fd, infos->data, infos->size);
	if (ret == -1)
		return (error_0("Cannot read file %s", path));
	if (ret != infos->size || header[0] != 'B' || header[1] != 'M')
		return (error_0("Invalid BMP file"));
	return (1);
}

int get_bmp_image(const char *path, t_image_infos *infos)
{
	int fd;

	if ((fd = open(path, O_RDONLY)) == -1)
		return (error_0("Cannot open file %s", path));
	if (!bmp_reader(path, fd, infos))
	{
		if (infos->data)
		{
			free(infos->data);
			infos->data = NULL;
		}
		return (0);
	}
	close(fd);
	return (1);
}

int get_texture(const char *path, t_object *obj)
{
	t_image_infos infos;

	if (!get_bmp_image(path, &infos))
		return (0);
	glGenTextures(1, &obj->texture);
	glBindTexture(GL_TEXTURE_2D, obj->texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D,
				 0,
				 GL_RGB,
				 infos.width,
				 infos.height,
				 0,
				 GL_BGR,
				 GL_UNSIGNED_BYTE,
				 infos.data);
	glGenerateMipmap(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 0);
	free(infos.data);
	return (1);
}
