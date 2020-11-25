#include "mgl.h"

t_mat4x4 translate(const t_mat4x4 *mat, const t_vec3 *vec)
{
	t_mat4x4 transf;

	transf = g_matI4;
	transf.w1 = vec->x;
	transf.w2 = vec->y;
	transf.w3 = vec->z;
	return (dotmm4x4(mat, &transf));
}

t_mat4x4 scale(const t_mat4x4 *mat, const t_vec3 *vec)
{
	t_mat4x4 transf;

	transf = g_matI4;
	transf.x1 = vec->x;
	transf.y2 = vec->y;
	transf.z3 = vec->z;
	return (dotmm4x4(mat, &transf));
}

t_mat4x4 rotx(const t_mat4x4 *mat, float angle)
{
	t_mat4x4 transf = g_matI4;

	transf = g_matI4;
	transf.y2 = cosf(angle);
	transf.z2 = -sinf(angle);
	transf.y3 = sinf(angle);
	transf.z3 = cosf(angle);
	return (dotmm4x4(mat, &transf));
}

t_mat4x4 roty(const t_mat4x4 *mat, float angle)
{
	t_mat4x4 transf = g_matI4;

	transf = g_matI4;
	transf.x1 = cosf(angle);
	transf.z1 = sinf(angle);
	transf.x3 = -sinf(angle);
	transf.z3 = cosf(angle);
	return (dotmm4x4(mat, &transf));
}

t_mat4x4 rotz(const t_mat4x4 *mat, float angle)
{
	t_mat4x4 transf = g_matI4;

	transf = g_matI4;
	transf.x1 = cosf(angle);
	transf.y1 = -sinf(angle);
	transf.x2 = sinf(angle);
	transf.y2 = cosf(angle);
	return (dotmm4x4(mat, &transf));
}
