#include "mgl.h"

t_mat4x4 translate(const t_mat4x4 *mat, t_vec3 vec)
{
	t_mat4x4 transf;

	transf = g_matI4;
	transf.m30 = vec.x;
	transf.m31 = vec.y;
	transf.m32 = vec.z;
	return (dotmm4x4(mat, &transf));
}

t_mat4x4 scale(const t_mat4x4 *mat, t_vec3 vec)
{
	t_mat4x4 transf;

	transf = g_matI4;
	transf.m00 = vec.x;
	transf.m11 = vec.y;
	transf.m22 = vec.z;
	return (dotmm4x4(mat, &transf));
}

t_mat4x4 rotate_x(const t_mat4x4 *mat, float angle)
{
	t_mat4x4 transf = g_matI4;

	transf = g_matI4;
	transf.m11 = cosf(angle);
	transf.m12 = -sinf(angle);
	transf.m21 = sinf(angle);
	transf.m22 = cosf(angle);
	return (dotmm4x4(mat, &transf));
}

t_mat4x4 rotate_y(const t_mat4x4 *mat, float angle)
{
	t_mat4x4 transf = g_matI4;

	transf = g_matI4;
	transf.m00 = cosf(angle);
	transf.m20 = sinf(angle);
	transf.m02 = -sinf(angle);
	transf.m22 = cosf(angle);
	return (dotmm4x4(mat, &transf));
}

t_mat4x4 rotate_z(const t_mat4x4 *mat, float angle)
{
	t_mat4x4 transf = g_matI4;

	transf = g_matI4;
	transf.m00 = cosf(angle);
	transf.m10 = -sinf(angle);
	transf.m01 = sinf(angle);
	transf.m11 = cosf(angle);
	return (dotmm4x4(mat, &transf));
}

t_mat4x4 rotate(const t_mat4x4 *mat, float angle, t_vec3 vec)
{
	t_vec4   q;
	t_mat4x4 transf = g_matI4;

	normalize(&vec, 3);
	q.x = sinf(angle / 2.0f) * vec.x;
	q.y = sinf(angle / 2.0f) * vec.y;
	q.z = sinf(angle / 2.0f) * vec.z;
	q.w = cosf(angle / 2.0f);
	transf.m00 = q.w * q.w + q.x * q.x - q.y * q.y - q.z * q.z;
	transf.m01 = 2 * q.x * q.y + 2 * q.w * q.z;
	transf.m02 = 2 * q.x * q.z - 2 * q.w * q.y;
	transf.m10 = 2 * q.x * q.y - 2 * q.w * q.z;
	transf.m11 = q.w * q.w - q.x * q.x + q.y * q.y - q.z * q.z;
	transf.m12 = 2 * q.y * q.z + 2 * q.w * q.x;
	transf.m20 = 2 * q.x * q.z + 2 * q.w * q.y;
	transf.m21 = 2 * q.y * q.z - 2 * q.w * q.x;
	transf.m22 = q.w * q.w - q.x * q.x - q.y * q.y + q.z * q.z;
	return (dotmm4x4(mat, &transf));
}
