#include "mgl.h"

void dotmm(const void *mat1, const void *mat2, void *out, int size)
{
	int   i;
	int   j;
	int   k;
	float v1;
	float v2;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			k = 0;
			while (k < size)
			{
				v1 = ((float *)mat1)[k * size + i];
				v2 = ((float *)mat2)[j * size + k];
				((float *)out)[j * size + i] += v1 * v2;
				k++;
			}
			j++;
		}
		i++;
	}
}

t_mat2x2 dotmm2x2(const t_mat2x2 *mat1, const t_mat2x2 *mat2)
{
	t_mat2x2 out;

	out = g_mat02;
	dotmm(mat1, mat2, &out, 2);
	return (out);
}

t_mat3x3 dotmm3x3(const t_mat3x3 *mat1, const t_mat3x3 *mat2)
{
	t_mat3x3 out;

	out = g_mat03;
	dotmm(mat1, mat2, &out, 3);
	return (out);
}

t_mat4x4 dotmm4x4(const t_mat4x4 *mat1, const t_mat4x4 *mat2)
{
	t_mat4x4 out;

	out = g_mat04;
	dotmm(mat1, mat2, &out, 4);
	return (out);
}
