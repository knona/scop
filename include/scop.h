#ifndef SCOP_H
#define SCOP_H

#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"
#include "glad/glad.h"
#include "libft.h"
#include "mgl.h"
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define SCOP_SHADER_BUFFER 15

/*
** UTILS
*/
int   error_int(int ret, char *error);
char *error_null(char *error);

/*
** SHADER
*/
int createShader(GLuint *shader, const GLenum shaderType, const char *shaderPath);
char *getShaderCode(const char *shaderPath, int *outLength);

#endif // !SCOP_H
