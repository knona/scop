#include "mgl.h"

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
			printf("%6.2f", ((float *)mat)[j * matSize + i]);
			j++;
		}
		printf("\n");
		i++;
	}
}
