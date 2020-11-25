#include "mgl.h"

float mat_at(void *mat, int i, int j, int size)
{
	return ((float *)mat)[i * size + j];
}

float *mat_at_addr(void *mat, int i, int j, int size)
{
	return ((float *)mat) + i * size + j;
}
