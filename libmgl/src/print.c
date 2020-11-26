#include "mgl.h"

void print_vec(void *vec, int vec_size)
{
	int   i;
	char *properties = "xyzw";

	i = 0;
	while (i < vec_size)
	{
		if (i != 0)
			printf(" ; ");
		printf("%c: %6.2f", properties[i], ((float *)vec)[i]);
		i++;
	}
	printf("\n");
}

void print_mat(void *mat, int mat_size)
{
	int i;
	int j;

	i = 0;
	while (i < mat_size)
	{
		j = 0;
		while (j < mat_size)
		{
			if (j != 0)
				printf(" ");
			printf("%15f", ((float *)mat)[j * mat_size + i]);
			j++;
		}
		printf("\n");
		i++;
	}
}
