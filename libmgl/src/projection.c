#include "mgl.h"

t_mat4x4 perspective(float fovy, float aspect, float near, float far)
{
	float    tan_half_fovy;
	t_mat4x4 proj;

	proj = g_mat04;
	tan_half_fovy = tanf(fovy / 2.0f);
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
	top = tanf(fovy) * near;
	right = aspect * top;
	left = -right;
	bottom = -top;

	proj.m00 = near / right;
	proj.m11 = near / top;
	proj.m22 = -(far + near) / (far - near);
	proj.m23 = -1;
	proj.m32 = -2 * far * near / (far - near);
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
	top = tanf(fovy) * near;
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
