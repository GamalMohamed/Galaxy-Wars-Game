#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include "Defs.h"
#include"camera.h"
#include"model.h"
using namespace glm;
using namespace std;


class GameWindow
{
private:
    bool running;
    GLfloat height;
    GLfloat width;



public:
    GameWindow(bool running);
    ~GameWindow();

    void setRunning(bool);
    bool getRunning();

    void set2D();
    void setTransformationMatrices();
    void DrawModels();

    void Render();
    void Update();

};

#endif
