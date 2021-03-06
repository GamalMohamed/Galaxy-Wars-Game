#version 120
attribute vec3 position;
attribute vec3 normal;
attribute vec2 texCoords;

varying vec3 Normal;
varying vec3 FragPos;
varying vec2 TexCoords;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    gl_Position = projection * view *  model * vec4(position, 1.0f);
    FragPos = vec3(model * vec4(position, 1.0f));
    Normal = mat3(transpose(inverse(model))) * normal;  
    TexCoords = texCoords;
} 
