#include "mgl.h"

float deg_to_rad(float degrees)
{
	return (degrees * M_PI / 180.0);
}

float rad_to_deg(float radians)
{
	return (radians * (180.0f / M_PI));
}
