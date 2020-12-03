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
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define SCOP_SHADER_BUFFER 200
#define SCOP_GL_ERROR_BUFFER 500
#define SCOP_VERTICES_BUFFER 1000
#define SCOP_INDICES_BUFFER 1000
#define SCOP_WIN_WIDTH 1280
#define SCOP_WIN_HEIGHT 720

#define BMP_DATA_OFFSET 0x0A
#define BMP_WIDTH 0x12
#define BMP_HEIGHT 0x16
#define BMP_SIZE 0x22

typedef unsigned int uint;

struct s_range
{
	float x_min;
	float x_max;
	float y_min;
	float y_max;
	float z_min;
	float z_max;
};
typedef struct s_range t_range;

struct s_object
{
	GLuint  vao;
	GLuint  ebo;
	GLuint  vbo;
	GLuint  program;
	float * vertices;
	uint *  indices;
	int     vertices_size;
	int     indices_size;
	int     vertices_max_size;
	int     indices_max_size;
	t_range range;
};
typedef struct s_object t_object;

struct s_cursor
{
	double x;
	double y;
};
typedef struct s_cursor t_cursor;

struct s_image_infos
{
	uint           width;
	uint           height;
	uint           size;
	uint           data_offset;
	unsigned char *data;
};
typedef struct s_image_infos t_image_infos;

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

/*
** OBJECT
*/
int  init_object(t_object *obj);
void clean_object(t_object *obj);

/*
** PARSE
*/
int parse_obj_file(const char *path, t_object *obj);

/*
** TEXTURE
*/
int get_bmp_image(const char *path, t_image_infos *infos);
int get_texture(const char *path, GLuint *texture);

#endif // !SCOP_H
