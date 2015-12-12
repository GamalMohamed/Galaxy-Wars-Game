#ifndef SHADER_H
#define SHADER_H
#include"../Defs.h"

class Shader
{

private:
    GLuint Program;


public:
    Shader(const GLchar* vertexPath, const GLchar* fragmentPath);

    void Use();
    GLuint getProgram();

};

#endif // SHADER_H
