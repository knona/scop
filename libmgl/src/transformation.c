#include "mgl.h"

t_mat4x4 translate(const t_mat4x4 *mat, const t_vec3 *vec)
{
	t_mat4x4 transf;

	transf = g_matI4;
	transf.m30 = vec->x;
	transf.m31 = vec->y;
	transf.m32 = vec->z;
	return (dotmm4x4(mat, &transf));
}

t_mat4x4 scale(const t_mat4x4 *mat, const t_vec3 *vec)
{
	t_mat4x4 transf;

	transf = g_matI4;
	transf.m00 = vec->x;
	transf.m11 = vec->y;
	transf.m22 = vec->z;
	return (dotmm4x4(mat, &transf));
}

t_mat4x4 rotation_x(const t_mat4x4 *mat, float angle)
{
	t_mat4x4 transf = g_matI4;

	transf = g_matI4;
	transf.m11 = cosf(angle);
	transf.m12 = -sinf(angle);
	transf.m21 = sinf(angle);
	transf.m22 = cosf(angle);
	return (dotmm4x4(mat, &transf));
}

t_mat4x4 rotation_y(const t_mat4x4 *mat, float angle)
{
	t_mat4x4 transf = g_matI4;

	transf = g_matI4;
	transf.m00 = cosf(angle);
	transf.m20 = sinf(angle);
	transf.m02 = -sinf(angle);
	transf.m22 = cosf(angle);
	return (dotmm4x4(mat, &transf));
}

t_mat4x4 rotation_z(const t_mat4x4 *mat, float angle)
{
	t_mat4x4 transf = g_matI4;

	transf = g_matI4;
	transf.m00 = cosf(angle);
	transf.m10 = -sinf(angle);
	transf.m01 = sinf(angle);
	transf.m11 = cosf(angle);
	return (dotmm4x4(mat, &transf));
}
