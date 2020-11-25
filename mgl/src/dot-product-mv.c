#include "mgl.h"

void dotmv(const void *mat, const void *vec, void *out, int size)
{
	int   i;
	int   k;
	float v1;
	float v2;

	i = 0;
	while (i < size)
	{
		k = 0;
		while (k < size)
		{
			v1 = ((float *)mat)[i * size + k];
			v2 = ((float *)vec)[k];
			((float *)out)[i] += v1 * v2;
			k++;
		}
		i++;
	}
}

t_vec2 dotmv2x2(const t_mat2x2 *mat, const t_vec2 *vec)
{
	t_vec2 out;

	out = g_vec02;
	dotmv(mat, vec, &out, 2);
	return (out);
}

t_vec3 dotmv3x3(const t_mat3x3 *mat, const t_vec3 *vec)
{
	t_vec3 out;

	out = g_vec03;
	dotmv(mat, vec, &out, 3);
	return (out);
}

t_vec4 dotmv4x4(const t_mat4x4 *mat, const t_vec4 *vec)
{
	t_vec4 out;

	out = g_vec04;
	dotmv(mat, vec, &out, 4);
	return (out);
}
