#version 120
varying vec3 ourColor;
varying vec2 TexCoord;


// Texture samplers
uniform sampler2D ourTexture1;


void main()
{
	gl_FragColor = texture2D(ourTexture1, TexCoord);
}
