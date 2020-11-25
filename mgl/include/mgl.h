#ifndef MGL_H
#define MGL_H

#include "libft.h"
#include <math.h>
#include <stdio.h>

struct s_mat2x2
{
	float x1;
	float y1;
	float x2;
	float y2;
};
typedef struct s_mat2x2 t_mat2x2;

struct s_mat3x3
{
	float x1;
	float y1;
	float z1;
	float x2;
	float y2;
	float z2;
	float x3;
	float y3;
	float z3;
};
typedef struct s_mat3x3 t_mat3x3;

struct s_mat4x4
{
	float x1;
	float y1;
	float z1;
	float w1;
	float x2;
	float y2;
	float z2;
	float w2;
	float x3;
	float y3;
	float z3;
	float w3;
	float x4;
	float y4;
	float z4;
	float w4;
};
typedef struct s_mat4x4 t_mat4x4;

struct s_vec2
{
	float x;
	float y;
};
typedef struct s_vec2 t_vec2;

struct s_vec3
{
	float x;
	float y;
	float z;
};
typedef struct s_vec3 t_vec3;

struct s_vec4
{
	float x;
	float y;
	float z;
	float w;
};
typedef struct s_vec4 t_vec4;

extern const t_mat2x2 g_matI2;
extern const t_mat3x3 g_matI3;
extern const t_mat4x4 g_matI4;
extern const t_mat2x2 g_mat02;
extern const t_mat3x3 g_mat03;
extern const t_mat4x4 g_mat04;
extern const t_vec2   g_vec02;
extern const t_vec3   g_vec03;
extern const t_vec4   g_vec04;

/*
** DOT PRODUCT
*/
void     dotmm(const void *mat1, const void *mat2, void *out, int size);
void     dotmv(const void *mat, const void *vec, void *out, int size);
t_mat2x2 dotmm2x2(const t_mat2x2 *mat1, const t_mat2x2 *mat2);
t_mat3x3 dotmm3x3(const t_mat3x3 *mat1, const t_mat3x3 *mat2);
t_mat4x4 dotmm4x4(const t_mat4x4 *mat1, const t_mat4x4 *mat2);
t_vec2   dotmv2x2(const t_mat2x2 *mat, const t_vec2 *vec);
t_vec3   dotmv3x3(const t_mat3x3 *mat, const t_vec3 *vec);
t_vec4   dotmv4x4(const t_mat4x4 *mat, const t_vec4 *vec);

/*
** TRANSFORMATIONS
*/
t_mat4x4 translate(const t_mat4x4 *mat, const t_vec3 *vec);
t_mat4x4 scale(const t_mat4x4 *mat, const t_vec3 *vec);
t_mat4x4 rotx(const t_mat4x4 *mat, float angle);
t_mat4x4 roty(const t_mat4x4 *mat, float angle);
t_mat4x4 rotz(const t_mat4x4 *mat, float angle);

/*
** TRANSPOSE
*/
void     transpose(const void *mat, void *out, int size);
t_mat2x2 transpose2x2(const void *mat);
t_mat3x3 transpose3x3(const void *mat);
t_mat4x4 transpose4x4(const void *mat);

/*
** UTILS
*/
float  mat_at(void *mat, int i, int j, int size);
float *mat_at_addr(void *mat, int i, int j, int size);

/*
** PRINT
*/
void print_mat(void *mat, int matSize);
void print_vec(void *vec, int vecSize);

#endif // !MGL_H
