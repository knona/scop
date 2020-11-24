#ifndef MGL_H
#define MGL_H

#include "libft.h"
#include <stdio.h>

typedef float t_mat2x2[2][2];
typedef float t_mat3x3[3][3];
typedef float t_mat4x4[4][4];

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

void print_mat(void *mat, int matSize);
void print_vec(void *vec, int vecSize);
void dotmm(void *mat1, void *mat2, void *out, int size);
void dotmv(void *mat, void *vec, void *out, int size);

void test(void);

#endif // !MGL_H
