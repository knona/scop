#include "scop.h"

void error(const char *format, va_list ap)
{
	ft_dprintf(2, "\033[31mError:\033[0m ");
	ft_vdprintf(2, format, ap);
	ft_dprintf(2, "\n");
	if (errno != 0)
		perror(NULL);
}

int error_int(int ret, const char *format, ...)
{
	va_list ap;
	va_start(ap, format);
	error(format, ap);
	va_end(ap);
	return ret;
}

int error_0(const char *format, ...)
{
	va_list ap;
	va_start(ap, format);
	error(format, ap);
	va_end(ap);
	return 0;
}

char *error_null(const char *format, ...)
{
	va_list ap;
	va_start(ap, format);
	error(format, ap);
	va_end(ap);
	return NULL;
}