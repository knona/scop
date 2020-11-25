#include "mgl.h"

void transpose(const void *mat, void *out, int size)
{
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			((float *)out)[i * size + j] = ((float *)mat)[j * size + i];
			j++;
		}
		i++;
	}
}

t_mat2x2 transpose2x2(const void *mat)
{
	t_mat2x2 out;

	transpose(mat, &out, 2);
	return (out);
}

t_mat3x3 transpose3x3(const void *mat)
{
	t_mat3x3 out;

	transpose(mat, &out, 3);
	return (out);
}

t_mat4x4 transpose4x4(const void *mat)
{
	t_mat4x4 out;

	transpose(mat, &out, 4);
	return (out);
}
