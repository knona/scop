#include "scop.h"

int get_uniform_location(GLuint program, const char *uniform_name, GLint *location)
{
	*location = glGetUniformLocation(program, uniform_name);
	if (*location == -1)
		return error_0("Location %s cannot be found", uniform_name);
	return (1);
}

int uniform_set_mat4x4(GLuint program, const char *uniformName, const t_mat4x4 *mat)
{
	GLint location;

	if (!get_uniform_location(program, uniformName, &location))
		return (0);
	glUniformMatrix4fv(location, 1, 0, (const float *)mat);
	return (1);
}

int uniform_set_vec4(GLuint program, const char *uniformName, const t_vec4 *vec)
{
	GLint location;

	if (!get_uniform_location(program, uniformName, &location))
		return (0);
	glUniform4fv(location, 1, (const float *)vec);
	return (1);
}

int uniform_set_1i(GLuint program, const char *uniformName, int value)
{
	GLint location;

	if (!get_uniform_location(program, uniformName, &location))
		return (0);
	glUniform1i(location, value);
	return (1);
}
