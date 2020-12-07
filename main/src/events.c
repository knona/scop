#include "scop.h"

void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
	t_mat4x4 projection;

	(void)window;
	glViewport(0, 0, width, height);
	projection = perspective(deg_to_rad(30), (float)width / (float)height, 0.1f, 100.0f);
	uniform_set_mat4x4(g_event_options.obj->program, "projection", &projection);
}

void scroll_callback(GLFWwindow *window, double xoffset, double yoffset)
{
	const float speed = 0.15;

	(void)window;
	(void)xoffset;
	if (yoffset > 0)
		g_event_options.pos.z += speed;
	if (yoffset < 0)
		g_event_options.pos.z -= speed;
}

void cursor_position_callback(GLFWwindow *window, double xpos, double ypos)
{
	t_vec3   pos_cpy;
	t_cursor curs_pos;

	(void)window;
	pos_cpy = g_event_options.pos_cpy;
	curs_pos = g_event_options.curs_pos;
	if (g_event_options.l_click)
	{
		g_event_options.pos.x = pos_cpy.x - (curs_pos.x - xpos) / 200;
		g_event_options.pos.y = pos_cpy.y + (curs_pos.y - ypos) / 200;
	}
}

void mouse_button_callback(GLFWwindow *window, int button, int action, int mods)
{
	t_vec3    pos;
	t_cursor *curs_pos;

	(void)mods;
	pos = g_event_options.pos;
	curs_pos = &g_event_options.curs_pos;
	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
	{
		g_event_options.l_click = 1;
		glfwGetCursorPos(window, &curs_pos->x, &curs_pos->y);
		g_event_options.pos_cpy.x = pos.x;
		g_event_options.pos_cpy.y = pos.y;
	}
	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE)
		g_event_options.l_click = 0;
}

void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
	const float speed = 0.1;
	t_vec3 *    pos;
	int *       line_m;

	(void)mods;
	(void)scancode;
	pos = &g_event_options.pos;
	line_m = &g_event_options.line_mode;
	if (action == GLFW_PRESS || action == GLFW_REPEAT)
	{
		if (key == GLFW_KEY_W)
			pos->y += speed * (1 << (int)(action == GLFW_REPEAT));
		if (key == GLFW_KEY_S)
			pos->y -= speed * (1 << (int)(action == GLFW_REPEAT));
		if (key == GLFW_KEY_D)
			pos->x += speed * (1 << (int)(action == GLFW_REPEAT));
		if (key == GLFW_KEY_A)
			pos->x -= speed * (1 << (int)(action == GLFW_REPEAT));
		if (key == GLFW_KEY_P)
			pos->z += speed * (1 << (int)(action == GLFW_REPEAT));
		if (key == GLFW_KEY_O)
			pos->z -= speed * (1 << (int)(action == GLFW_REPEAT));
		if (key == GLFW_KEY_K)
			g_event_options.rotx += speed * (1 << (int)(action == GLFW_REPEAT));
		if (key == GLFW_KEY_L)
			g_event_options.rotx -= speed * (1 << (int)(action == GLFW_REPEAT));
		if (action != GLFW_REPEAT)
		{
			if (key == GLFW_KEY_SPACE)
				g_event_options.scop_pause = !g_event_options.scop_pause;
			if (key == GLFW_KEY_T)
				g_event_options.increase = !g_event_options.increase;
			if (key == GLFW_KEY_R)
				init_options(g_event_options.obj);
			if (key == GLFW_KEY_F)
			{
				*line_m = !*line_m;
				glPolygonMode(GL_FRONT_AND_BACK, *line_m ? GL_LINE : GL_FILL);
			}
			if (key == GLFW_KEY_ESCAPE)
				glfwSetWindowShouldClose(window, 1);
		}
	}
}
