#include "mgl.h"

double deg_to_rad(double degrees)
{
	return (degrees * M_PI / 180.0);
}

double rad_to_deg(double radians)
{
	return (radians * (180.0 / M_PI));
}
