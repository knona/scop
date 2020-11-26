#include "scop.h"

char *get_shader_code(const char *shader_path, int *out_length)
{
	int   fd;
	int   ret;
	char *shader_code;
	char *buffer[SCOP_SHADER_BUFFER];

	shader_code = NULL;
	fd = open(shader_path, O_RDONLY);
	if (fd == -1)
		return (error_null("Cannot open file"));
	*out_length = 0;
	while ((ret = read(fd, buffer, SCOP_SHADER_BUFFER)))
	{
		if (ret == -1)
			return (error_null("Cannot read file"));
		shader_code = (char *)realloc(shader_code, *out_length + ret);
		if (!shader_code)
			return (error_null("Malloc error"));
		ft_memcpy(shader_code + *out_length, buffer, ret);
		*out_length += ret;
	}
	return (shader_code);
}

int check_compilation_success(GLuint shader)
{
	int  success;
	char buffer[500];

	ft_bzero(buffer, 500);
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(shader, 500, NULL, buffer);
		ft_dprintf(2, "Shader: Compilation failed: %s\n", buffer);
		return (0);
	}
	return (1);
}

int create_shader(GLuint *shader, const GLenum shader_type, const char *shader_path)
{
	int length;

	*shader = glCreateShader(shader_type);
	if (!*shader)
		return (error_0("Failed to create shader"));
	const char *shader_code = get_shader_code(shader_path, &length);
	if (!shader_code)
		return (0);
	glShaderSource(*shader, 1, &shader_code, &length);
	glCompileShader(*shader);
	free((void *)shader_code);
	return (check_compilation_success(*shader));
}
