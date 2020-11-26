#include "scop.h"

char *getShaderCode(const char *shaderPath, int *outLength)
{
	int   fd;
	int   ret;
	char *shaderCode;
	char *buffer[SCOP_SHADER_BUFFER];

	shaderCode = NULL;
	fd = open(shaderPath, O_RDONLY);
	if (fd == -1)
		return (error_null("Cannot open file"));
	*outLength = 0;
	while ((ret = read(fd, buffer, SCOP_SHADER_BUFFER)))
	{
		if (ret == -1)
			return (error_null("Cannot read file"));
		shaderCode = (char *)realloc(shaderCode, *outLength + ret);
		if (!shaderCode)
			return (error_null("Malloc error"));
		ft_memcpy(shaderCode + *outLength, buffer, ret);
		*outLength += ret;
	}
	return (shaderCode);
}

int checkCompilationSuccess(GLuint shader)
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

int createShader(GLuint *shader, const GLenum shaderType, const char *shaderPath)
{
	int length;

	*shader = glCreateShader(shaderType);
	if (!*shader)
		return (error_0("Failed to create shader"));
	const char *shaderCode = getShaderCode(shaderPath, &length);
	if (!shaderCode)
		return (0);
	glShaderSource(*shader, 1, &shaderCode, &length);
	glCompileShader(*shader);
	free((void *)shaderCode);
	return (checkCompilationSuccess(*shader));
}
