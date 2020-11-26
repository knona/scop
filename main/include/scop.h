#ifndef SCOP_H
#define SCOP_H

#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"
#include "glad/glad.h"
#include "libft.h"
#include "mgl.h"
#include <errno.h>
#include <fcntl.h>
#include <stdarg.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define SCOP_SHADER_BUFFER 500
#define SCOP_GL_ERROR_BUFFER 500

typedef unsigned int uint;

/*
** ERROR
*/
int   error_int(int ret, const char *format, ...);
int   error_0(const char *format, ...);
char *error_null(const char *format, ...);

/*
** SHADER
*/
int create_shader(GLuint *shader, const GLenum shaderType, const char *shaderPath);

/*
** PROGRAM
*/
int create_program(GLuint *program, const char *vertex_shader_path, const char *fragment_shader_path);

#endif // !SCOP_H
