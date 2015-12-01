#ifndef ENVIROMENT_H
#define ENVIROMENT_H

#include"gamewindow.h"
using namespace glm;


class Enviroment
{
private:
    GLuint vertexBufferID;
    GLuint textureBufferID;

public:
    Enviroment();
    ~Enviroment();

    void Render(int view=1);
    void Update();
};

#endif // ENVIROMENT_H
