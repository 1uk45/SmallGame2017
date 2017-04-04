#version 420

out vec4 Colour;

uniform vec3 color;

void main()
{
	
	Colour = vec4(color, 1.0);
	
}