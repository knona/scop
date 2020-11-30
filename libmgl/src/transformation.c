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
	float    cos_a;
	float    sin_a;
	t_mat4x4 transf;

	transf = g_matI4;
	normalize(&vec, 3);
	cos_a = cosf(angle);
	sin_a = sinf(angle);

	transf.m00 = cos_a + (1 - cos_a) * vec.x * vec.x;
	transf.m01 = (1 - cos_a) * vec.x * vec.y - sin_a * vec.z;
	transf.m02 = (1 - cos_a) * vec.x * vec.z + sin_a * vec.y;
	transf.m10 = (1 - cos_a) * vec.x * vec.y + sin_a * vec.z;
	transf.m11 = cos_a + (1 - cos_a) * vec.y * vec.y;
	transf.m12 = (1 - cos_a) * vec.y * vec.z - sin_a * vec.x;
	transf.m20 = (1 - cos_a) * vec.x * vec.z - sin_a * vec.y;
	transf.m21 = (1 - cos_a) * vec.y * vec.z + sin_a * vec.x;
	transf.m22 = cos_a + (1 - cos_a) * vec.z * vec.z;
	return (dotmm4x4(mat, &transf));
}
