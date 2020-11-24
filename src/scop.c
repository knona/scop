#include "scop.h"

int main(void)
{
	setbuf(stdout, NULL);
	t_mat3x3 matrix = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
	t_vec3   vec = { 1, 2, 3 };
	t_vec3   vecResult;

	print_mat(matrix, 3);
	print_vec(&vec, 3);

	dotmv(matrix, &vec, &vecResult, 3);

	print_vec(&vecResult, 3);

	return 0;
}
