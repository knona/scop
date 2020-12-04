/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krambono <krambono@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 11:38:39 by krambono          #+#    #+#             */
/*   Updated: 2020/12/04 11:46:22 by krambono         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

char	*get_shader_code(const char *shader_path, int *out_length)
{
	int		fd;
	int		ret;
	char	*shader_code;
	char	*buffer[SCOP_SHADER_BUFFER];

	shader_code = NULL;
	fd = open(shader_path, O_RDONLY);
	if (fd == -1)
		return (error_null("Cannot open file %s", shader_path));
	*out_length = 0;
	while ((ret = read(fd, buffer, SCOP_SHADER_BUFFER)))
	{
		if (ret == -1)
			return (error_null("Cannot read file %s", shader_path));
		shader_code = (char *)realloc(shader_code, *out_length + ret);
		if (!shader_code)
			return (error_null("Malloc error"));
		ft_memcpy(shader_code + *out_length, buffer, ret);
		*out_length += ret;
	}
	close(fd);
	return (shader_code);
}

int		check_compilation_success(GLuint shader, const char *shader_path)
{
	int		success;
	char	buffer[SCOP_GL_ERROR_BUFFER];

	ft_bzero(buffer, SCOP_GL_ERROR_BUFFER);
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(shader, SCOP_GL_ERROR_BUFFER, NULL, buffer);
		return (error_0("Failed to compile shader \"%s\":\ns%s",
		shader_path, buffer));
	}
	return (1);
}

int		create_shader(GLuint *shader, const GLenum shader_type,
		const char *shader_path)
{
	int		length;
	char	*shader_code;

	*shader = glCreateShader(shader_type);
	if (!*shader)
		return (error_0("Failed to create shader %s", shader_path));
	shader_code = get_shader_code(shader_path, &length);
	if (!shader_code)
		return (0);
	glShaderSource(*shader, 1, (const char **)&shader_code, &length);
	glCompileShader(*shader);
	free((void *)shader_code);
	return (check_compilation_success(*shader, shader_path));
}
