#include "mgl.h"

void dotmm(void *mat1, void *mat2, void *out, int size)
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
				v1 = ((float *)mat1)[i * size + k];
				v2 = ((float *)mat2)[k * size + j];
				((float *)out)[i * size + j] += v1 * v2;
				k++;
			}
			j++;
		}
		i++;
	}
}

void dotmv(void *mat, void *vec, void *out, int size)
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

void print_vec(void *vec, int vecSize)
{
	int   i;
	char *properties = "xyzw";

	i = 0;
	while (i < vecSize)
	{
		if (i != 0)
			printf(" ; ");
		printf("%c: %6.2f", properties[i], ((float *)vec)[i]);
		i++;
	}
	printf("\n");
}

void print_mat(void *mat, int matSize)
{
	int i;
	int j;

	i = 0;
	while (i < matSize)
	{
		j = 0;
		while (j < matSize)
		{
			if (j != 0)
				printf(" ");
			printf("%6.2f", ((float *)mat)[i * matSize + j]);
			j++;
		}
		printf("\n");
		i++;
	}
}
