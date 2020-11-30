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
#define SCOP_WIN_WIDTH 1280
#define SCOP_WIN_HEIGHT 720

struct s_key_cb_params
{
	void *      padding;
	int         mods;
	int         action;
	int         scancode;
	int         key;
	GLFWwindow *window;
};
typedef struct s_key_cb_params t_key_cb_params;

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

/*
** PROGRAM UNIFORM
*/
int uniform_set_mat4x4(GLuint program, const char *uniformName, const t_mat4x4 *mat);
int uniform_set_vec4(GLuint program, const char *uniformName, const t_vec4 *vec);
int uniform_set_1i(GLuint program, const char *uniformName, int value);

#endif // !SCOP_H