#include "mgl.h"

float mat_at(void *mat, int x, int y, int size)
{
	return (((float *)mat)[x * size + y]);
}

void mat2x2set(t_mat2x2 *mat, int x, int y, float value)
{
	((float *)mat)[x * 2 + y] = value;
}

void mat3x3set(t_mat3x3 *mat, int x, int y, float value)
{
	((float *)mat)[x * 3 + y] = value;
}

void mat4x4set(t_mat4x4 *mat, int x, int y, float value)
{
	((float *)mat)[x * 4 + y] = value;
}
