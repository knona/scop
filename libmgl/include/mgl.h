/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mgl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krambono <krambono@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 11:18:26 by krambono          #+#    #+#             */
/*   Updated: 2020/12/04 11:25:48 by krambono         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MGL_H
# define MGL_H

# define M_PI 3.14159265358979323846
# define M_PI_2 1.57079632679489661923
# define M_PI_4 0.78539816339744830962
# define M_PI_8 0.39269908169872415481
# define M_PI_16 0.19634954084936207740
# define M_2XPI 6.28318530717958647692
# define M_1_PI 0.31830988618379067154
# define M_2_PI 0.63661977236758134308
# define M_2_SQRTPI 1.12837916709551257390
# define M_SQRT2 1.41421356237309504880
# define M_SQRT1_2 0.70710678118654752440

# include "libft.h"
# include "structs.h"
# include <math.h>
# include <stdio.h>

extern const t_mat2x2	g_mati2;
extern const t_mat3x3	g_mati3;
extern const t_mat4x4	g_mati4;
extern const t_mat2x2	g_mat02;
extern const t_mat3x3	g_mat03;
extern const t_mat4x4	g_mat04;
extern const t_vec2		g_vec02;
extern const t_vec3		g_vec03;
extern const t_vec4		g_vec04;

/*
** DOT PRODUCT
*/
void					dotmm(const void *mat1, const void *mat2, void *out,
						int size);
void					dotmv(const void *mat, const void *vec, void *out,
						int size);
t_mat2x2				dotmm2x2(const t_mat2x2 *mat1, const t_mat2x2 *mat2);
t_mat3x3				dotmm3x3(const t_mat3x3 *mat1, const t_mat3x3 *mat2);
t_mat4x4				dotmm4x4(const t_mat4x4 *mat1, const t_mat4x4 *mat2);
t_vec2					dotmv2x2(const t_mat2x2 *mat, const t_vec2 *vec);
t_vec3					dotmv3x3(const t_mat3x3 *mat, const t_vec3 *vec);
t_vec4					dotmv4x4(const t_mat4x4 *mat, const t_vec4 *vec);

/*
** TRANSFORMATIONS
*/
t_mat4x4				translate(const t_mat4x4 *mat, t_vec3 vec);
t_mat4x4				scale(const t_mat4x4 *mat, t_vec3 vec);
t_mat4x4				rotate(const t_mat4x4 *mat, float angle, t_vec3 vec);
t_mat4x4				rotate_x(const t_mat4x4 *mat, float angle);
t_mat4x4				rotate_y(const t_mat4x4 *mat, float angle);
t_mat4x4				rotate_z(const t_mat4x4 *mat, float angle);

/*
** PROJECTIONS
*/
t_mat4x4				perspective(float fovy, float aspect, float near,
						float far);
t_mat4x4				ortho(float left, float right, float bottom, float top);

/*
** TRANSPOSE
*/
void					transpose(const void *mat, void *out, int size);
t_mat2x2				transpose2x2(const t_mat2x2 *mat);
t_mat3x3				transpose3x3(const t_mat3x3 *mat);
t_mat4x4				transpose4x4(const t_mat4x4 *mat);

/*
** MAT AT
*/
float					mat2x2at(const t_mat2x2 *mat, int x, int y);
float					mat3x3at(const t_mat3x3 *mat, int x, int y);
float					mat4x4at(const t_mat4x4 *mat, int x, int y);

/*
** MAT SET
*/
void					mat2x2set(t_mat2x2 *mat, int x, int y, float value);
void					mat3x3set(t_mat3x3 *mat, int x, int y, float value);
void					mat4x4set(t_mat4x4 *mat, int x, int y, float value);

/*
** PRINT
*/
void					print_mat(void *mat, int mat_size);
void					print_vec(void *vec, int vec_size);

/*
** ANGLE
*/
double					deg_to_rad(double degrees);
double					rad_to_deg(double radians);

/*
** GET VECTORS
*/
t_vec2					get_vec2(float x, float y);
t_vec3					get_vec3(float x, float y, float z);
t_vec4					get_vec4(float x, float y, float z, float w);

/*
** NORME
*/
float					get_norme(const void *vec, int size);
void					normalize(void *vec, int size);

#endif
