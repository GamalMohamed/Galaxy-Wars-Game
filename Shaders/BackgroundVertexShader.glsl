#version 120
attribute vec3 position;
attribute vec3 color;
attribute vec2 texCoord;

varying vec3 ourColor;
varying vec2 TexCoord;

void main()
{
	gl_Position = vec4(position, 1.0f);
	ourColor = color;
	//Swap the y-axis by substracing our coordinates from 1. This is done because most images have the top y-axis inversed with OpenGL's top y-axis.
	//TexCoord = texCoord;
	TexCoord = vec2(texCoord.x, 1.0 - texCoord.y);
}
