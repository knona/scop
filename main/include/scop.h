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
#define SCOP_ELEMENTS_BUFFER 1000
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
	GLuint  vbo;
	GLuint  program;
	GLuint  texture;
	float * vbo_data;
	t_vec3 *vertices;
	int     nb_elements;
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

struct s_event_options
{
	t_vec3    pos;
	int       scop_pause;
	double    time;
	int       line_mode;
	int       l_click;
	t_cursor  curs_pos;
	t_vec3    pos_cpy;
	float     rotx;
	t_object *obj;
};
typedef struct s_event_options t_event_options;

extern t_event_options g_event_options;

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
int get_texture(const char *path, t_object *obj);

/*
** EVENTS
*/
void framebuffer_size_callback(GLFWwindow *window, int width, int height);
void scroll_callback(GLFWwindow *window, double xoffset, double yoffset);
void cursor_position_callback(GLFWwindow *window, double xpos, double ypos);
void mouse_button_callback(GLFWwindow *window, int button, int action, int mods);
void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);

/*
** Utils
*/
void init_options(t_object *obj);
int  clean(t_object *obj);
int  init_window(GLFWwindow **window);
void display_commands();

/*
** RENDER LOOP
*/
int renderLoop(GLFWwindow *window, t_object *obj);

#endif // !SCOP_H
