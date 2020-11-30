#include "mgl.h"

t_vec2 get_vec2(float x, float y)
{
	t_vec2 vec2;

	vec2.x = x;
	vec2.y = y;
	return (vec2);
}

t_vec3 get_vec3(float x, float y, float z)
{
	t_vec3 vec3;

	vec3.x = x;
	vec3.y = y;
	vec3.z = z;
	return (vec3);
}

t_vec4 get_vec4(float x, float y, float z, float w)
{
	t_vec4 vec4;

	vec4.x = x;
	vec4.y = y;
	vec4.z = z;
	vec4.w = w;
	return (vec4);
}
