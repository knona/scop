#include "scop.h"

int get_uniform_location(const char *uniform_name, GLuint program, GLint *location)
{
	*location = glGetUniformLocation(program, uniform_name);
	if (*location == -1)
		return error_0("Location %s cannot be found", uniform_name);
	return (1);
}
