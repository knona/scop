#version 330 core
layout(location = 0) in vec3 pos;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

flat out int vertex_index;

void main()
{
	gl_Position = projection * view * model * vec4(pos, 1.0);
	vertex_index = gl_VertexID;
}
