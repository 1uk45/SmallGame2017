#version 420


in vec2 vertex_position;


void main()
{
	gl_Position = vec4(vertex_position, 0.5, 1.0);

}