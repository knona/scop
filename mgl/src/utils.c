#include "mgl.h"

float mat_at(void *mat, int x, int y, int size)
{
	return (((float *)mat)[x * size + y]);
}

float *mat_at_addr(void *mat, int x, int y, int size)
{
	return (((float *)mat) + x * size + y);
}
