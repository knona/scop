#include "mgl.h"

t_mat4x4 perspective(float fovy, float aspect, float near, float far)
{
	float tanHalfFovy = tanf(fovy / 2.0f);

	t_mat4x4 proj = g_mat04;

	mat4x4set(&proj, 0, 0, 1.0f / (aspect * tanHalfFovy));
	mat4x4set(&proj, 1, 1, 1.0f / (tanHalfFovy));
	mat4x4set(&proj, 2, 2, far / (near - far));
	mat4x4set(&proj, 2, 3, -1.0f);
	mat4x4set(&proj, 3, 2, -(far * near) / (far - near));
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

t_mat4x4 ortho(float left, float right, float top, float bottom)
{
	t_mat4x4 proj = g_matI4;

	mat4x4set(&proj, 0, 0, 2.0f / (right - left));
	mat4x4set(&proj, 1, 1, 2.0f / (top - bottom));
	mat4x4set(&proj, 2, 2, -1.0f);
	mat4x4set(&proj, 3, 0, -(right + left) / (right - left));
	mat4x4set(&proj, 3, 1, -(top + bottom) / (top - bottom));
	return (proj);
}
