#include "scop.h"

GLFWwindow *window;
GLuint      program;
GLuint      ebo;
GLuint      vao;
GLuint      vbo;

int init()
{
	if (!glfwInit())
		return (error_0("Failed to initialize GLFW"));

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow(1280, 720, "LearnOpenGL", NULL, NULL);
	if (!window)
		return (error_0("Failed to create GLFW window"));

	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		return (error_0("Failed to initialize GLAD"));

	glViewport(0, 0, 1280, 720);
	// glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	return 1;
}

void create_vao()
{
	float cell[] = {
		0.0f, 1.0f, // top left
		0.0f, 0.0f, // bottom left
		1.0f, 1.0f, // top right
		1.0f, 0.0f, // bottom right
	};

	uint indices[] = {
		0, 1, 2, // first triangle
		1, 2, 3  // second triangle
	};

	glBindVertexArray(vao);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(cell), cell, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void *)0);
	glEnableVertexAttribArray(0);

	glBindVertexArray(0);
}

int start(void)
{
	if (!create_program(&program, "shaders/shader.vert", "shaders/shader.frag"))
		return (0);
	return (1);
}

int main(void)
{
	// setbuf(stdout, NULL);
	if (!init())
		return (1);

	return (!start());
}
