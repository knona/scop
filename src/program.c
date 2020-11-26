#include "scop.h"

void delete_shaders(GLuint vertex_shader, GLuint fragment_shader)
{
	glDeleteShader(vertex_shader);
	glDeleteShader(fragment_shader);
}

int check_program_link_success(GLuint program)
{
	int  success;
	char buffer[500];

	ft_bzero(buffer, 500);
	glGetProgramiv(program, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(program, 500, NULL, buffer);
		ft_dprintf(2, "Shader: Compilation failed: %s\n", buffer);
		return (0);
	}
	return (1);
}

int create_program(GLuint *program, const char *vertex_shader_path, const char *fragment_shader_path)
{
	GLuint vertex_shader;
	GLuint fragment_shader;

	if (!createShader(&vertex_shader, GL_VERTEX_SHADER, vertex_shader_path))
		return (1);
	if (!createShader(&fragment_shader, GL_FRAGMENT_SHADER, fragment_shader_path))
	{
		glDeleteShader(vertex_shader);
		return (1);
	}
	if (!(*program = glCreateProgram()))
	{
		delete_shaders(vertex_shader, fragment_shader);
		return (error_0("Failed to create program"));
	}
	glAttachShader(*program, vertex_shader);
	glAttachShader(*program, fragment_shader);
	glLinkProgram(*program);
	delete_shaders(vertex_shader, fragment_shader);
	return (check_program_link_success(*program));
}
