#include "mgl.h"

t_mat4x4 perspective(float fovy, float aspect, float near, float far)
{
	float tan_half_fovy = tanf(fovy / 2.0f);

	t_mat4x4 proj = g_mat04;

	proj.m00 = 1.0f / (aspect * tan_half_fovy);
	proj.m11 = 1.0f / (tan_half_fovy);
	proj.m22 = far / (near - far);
	proj.m23 = -1.0f;
	proj.m32 = -(far * near) / (far - near);
	return (proj);
}

t_mat4x4 perspective2(float fovy, float aspect, float near, float far)
{
	float    top;
	float    bottom;
	float    left;
	float    right;
	t_mat4x4 proj;

	proj = g_mat04;
	top = near * tanf(fovy / 2.0f);
	bottom = -top;
	right = top * aspect;
	left = -right;
	((float *)&proj)[0] = 2 * near / (right - left);
	((float *)&proj)[5] = 2 * near / (top - bottom);
	((float *)&proj)[10] = -(far + near) / (far - near);
	((float *)&proj)[11] = -1;
	((float *)&proj)[12] = -near * (left + right) / (right - left);
	((float *)&proj)[13] = -near * (bottom + top) / (top - bottom);
	((float *)&proj)[14] = 2 * near * far / (near - far);
	return (proj);
}

t_mat4x4 perspective3(float fovy, float aspect, float near, float far)
{
	float    top;
	float    bottom;
	float    left;
	float    right;
	t_mat4x4 proj;

	proj = g_mat04;
	// float scale = tanf(fovy * 0.5f * M_PI / 180) * near;
	top = tanf(fovy * 0.5f * M_PI / 180) * near;
	right = aspect * top;
	left = -right;
	bottom = -top;

	proj.m00 = 2 * near / (right - left);
	proj.m11 = 2 * near / (top - bottom);
	proj.m20 = (right + left) / (right - left);
	proj.m21 = (top + bottom) / (top - bottom);
	proj.m22 = -(far + near) / (far - near);
	proj.m23 = -1;
	proj.m32 = -2 * far * near / (far - near);
	// return (transpose4x4(&proj));
	return (proj);
}

t_mat4x4 ortho(float left, float right, float bottom, float top)
{
	t_mat4x4 proj = g_matI4;

	proj.m00 = 2.0f / (right - left);
	proj.m11 = 2.0f / (top - bottom);
	proj.m22 = -1.0f;
	proj.m30 = -(right + left) / (right - left);
	proj.m31 = -(top + bottom) / (top - bottom);
	return (proj);
}
