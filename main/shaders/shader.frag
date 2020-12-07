#version 400 core
flat in int vertex_index;
in vec2     tex_coord;

out vec4 out_frag;

uniform sampler2D texture1;

void main()
{
	vec4 color;

	switch (vertex_index % 5)
	{
	case 0:
		color = vec4(0.84314f, 0.85882f, 0.86666f, 1.0f);
		break;
	case 1:
		color = vec4(0.74118f, 0.76471f, 0.78039f, 1.0f);
		break;
	case 2:
		color = vec4(0.56471f, 0.58039f, 0.59216f, 1.0f);
		break;
	case 3:
		color = vec4(0.38431f, 0.39608f, 0.40392f, 1.0f);
		break;
	case 4:
		color = vec4(0.25882f, 0.25882f, 0.25882f, 1.0f);
		break;
	}
	out_frag = color;
	// out_frag = texture(texture1, tex_coord);
}
