/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krambono <krambono@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 15:47:57 by krambono          #+#    #+#             */
/*   Updated: 2020/12/07 15:51:08 by krambono         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOP_H
# define SCOP_H

# define GLFW_INCLUDE_NONE
# include "GLFW/glfw3.h"
# include "glad/glad.h"
# include "libft.h"
# include "mgl.h"
# include "structs.h"
# include <errno.h>
# include <fcntl.h>
# include <stdarg.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

# define SCOP_SHADER_BUFFER 200
# define SCOP_GL_ERROR_BUFFER 500
# define SCOP_ELEMENTS_BUFFER 1000
# define SCOP_WIN_WIDTH 1280
# define SCOP_WIN_HEIGHT 720

# define BMP_DATA_OFFSET 0x0A
# define BMP_WIDTH 0x12
# define BMP_HEIGHT 0x16
# define BMP_SIZE 0x22

extern t_event_options	g_event_options;

/*
** ERROR
*/
int						error_int(int ret, const char *format, ...);
int						error_0(const char *format, ...);
char					*error_null(const char *format, ...);

/*
** SHADER
*/
int						create_shader(GLuint *shader, const GLenum shader_type,
						const char *shader_path);

/*
** PROGRAM
*/
int						create_program(GLuint *program,
						const char *vertex_shader_path,
						const char *fragment_shader_path);

/*
** PROGRAM UNIFORM
*/
int						uniform_set_mat4x4(GLuint program,
						const char *uniform_name, const t_mat4x4 *mat);
int						uniform_set_vec4(GLuint program,
						const char *uniform_name, const t_vec4 *vec);
int						uniform_set_1f(GLuint program,
						const char *uniform_name, float value);
int						uniform_set_1i(GLuint program,
						const char *uniform_name, int value);

/*
** OBJECT
*/
int						init_object(t_object *obj);
void					clean_object(t_object *obj);

/*
** PARSE
*/
int						add_vertex(t_object *obj, const t_vec3 *vec);
int						add_vbo_element(t_object *obj, const int *indices,
						t_vec2 coord);
int						parse_obj_file(const char *path, t_object *obj);

/*
** TEXTURE
*/
int						get_texture(const char *path, t_object *obj);

/*
** EVENTS
*/
void					framebuffer_size_callback(GLFWwindow *window,
						int width, int height);
void					scroll_callback(GLFWwindow *window,
						double xoffset, double yoffset);
void					cursor_position_callback(GLFWwindow *window,
						double xpos, double ypos);
void					mouse_button_callback(GLFWwindow *window,
						int button, int action, int mods);
void					key_callback(GLFWwindow *window,
						int key, int scancode, int action, int mods);

/*
** Utils
*/
void					init_options(t_object *obj);
int						clean(t_object *obj);
int						init_window(GLFWwindow **window);
void					display_commands();
void					get_max_range(t_object *obj, t_vec3 *vertex);

/*
** RENDER LOOP
*/
int						render_loop(GLFWwindow *window, t_object *obj);

#endif
