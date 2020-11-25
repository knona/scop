#include "scop.h"

int error_int(int ret, char *error)
{
	ft_dprintf(2, "\033[31mError:\033[0m %s\n", error);
	if (errno != 0)
		perror(NULL);
	return ret;
}

char *error_null(char *error)
{
	ft_dprintf(2, "\033[31mError:\033[0m %s\n", error);
	if (errno != 0)
		perror(NULL);
	return NULL;
}
