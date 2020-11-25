#include "scop.h"

void ft1(void)
{
	t_mat4x4 model = g_matI4;

	t_vec3 transVec = { 1, 2, 3 };
	model = translate(&model, &transVec);

	t_vec3 scaleVec = { 2, 2, 2 };
	model = scale(&model, &scaleVec);

	print_mat(&model, 4);
	// printf("%d\n", (int)mat_at(&model, 3, 1, 4));
}

void ft2(void)
{
	t_mat3x3 mat = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	t_mat3x3 res = dotmm3x3(&mat, &mat);
	print_mat(&res, 3);
}

int main(void)
{
	setbuf(stdout, NULL);

	ft1();
	// ft2();
	return 0;
}
