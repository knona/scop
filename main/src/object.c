#include "scop.h"

void create_vao(t_object *obj)
{
	glBindVertexArray(obj->vao);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, obj->ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, obj->indices_size * sizeof(float), obj->indices, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, obj->vbo);
	glBufferData(GL_ARRAY_BUFFER, obj->vertices_size * sizeof(float), obj->vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
	glEnableVertexAttribArray(0);
	glBindVertexArray(0);
}

int set_uniform_matrices(t_object *obj)
{
	t_mat4x4 view;
	t_mat4x4 projection;

	glUseProgram(obj->program);
	view = g_matI4;
	projection = perspective(
		deg_to_rad(45), (float)SCOP_WIN_WIDTH / (float)SCOP_WIN_HEIGHT, 0.1f, 100.0f);
	view = translate(&g_matI4, get_vec3(0, 0, -3));
	if (!uniform_set_mat4x4(obj->program, "projection", &projection))
		return (0);
	if (!uniform_set_mat4x4(obj->program, "view", &view))
		return (0);
	return (1);
}

int init_object(t_object *obj)
{
	ft_bzero(obj, sizeof(t_object));
	glGenVertexArrays(1, &obj->vao);
	glGenBuffers(1, &obj->ebo);
	glGenBuffers(1, &obj->vbo);
	if (!create_program(&obj->program, "main/shaders/shader.vert", "main/shaders/shader.frag"))
		return (0);
	if (!set_uniform_matrices(obj))
		return (0);
	create_vao(obj);
	return (1);
}

void clean_object(t_object *obj)
{
	if (!obj->program)
		glDeleteProgram(obj->program);
	if (!obj->vao)
		glDeleteVertexArrays(1, &obj->vao);
	if (!obj->ebo)
		glDeleteBuffers(1, &obj->ebo);
	if (!obj->vbo)
		glDeleteBuffers(1, &obj->vbo);
}