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

    Model** models;
    Shader* shader;

    void set2D(); //Set a 2D scene !

    //Setting MVPs
	void setTransformationMatrices();

	//Compute transformations on models
	glm::mat4 ModelTransformations(float,float,float,float,float,float,float,float,float,float);

	//Actually draws models appropriately !
	void DrawModels();

public:
    GameWindow(bool running);
    ~GameWindow();

    void setRunning(bool);
    bool getRunning();

    void Render();
    void Update();

};

#endif
