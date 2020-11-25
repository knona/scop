#include "scop.h"

void mylib(void)
{
	t_mat4x4 model = g_matI4;

	t_vec3 transVec = { 2, 1, 4 };
	model = translate(&model, &transVec);

	t_vec3 scaleVec = { 2, 2, 1 };
	model = scale(&model, &scaleVec);

	// model = transpose4x4(&model);
	print_mat(&model, 4);
}

int main(void)
{
	setbuf(stdout, NULL);

	mylib();
	return 0;
}
