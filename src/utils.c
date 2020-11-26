#include "scop.h"

int error_int(int ret, const char *error)
{
	ft_dprintf(2, "\033[31mError:\033[0m %s\n", error);
	if (errno != 0)
		perror(NULL);
	return ret;
}

int error_0(const char *error)
{
	return error_int(0, error);
}

char *error_null(const char *error)
{
	ft_dprintf(2, "\033[31mError:\033[0m %s\n", error);
	if (errno != 0)
		perror(NULL);
	return NULL;
}
