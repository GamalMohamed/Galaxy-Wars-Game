#include "gamewindow.h"
#include"enviroment.h"

Enviroment* env;
Shader* shader;
Model* Model1;

//Setup the Camera
Camera camera(glm::vec3(0.0f, 0.0f, 20.0f));

int level=1;
float rotationAngle;


void GameWindow::setRunning(bool newRunning) {
    running = newRunning;
}

bool GameWindow::getRunning() {
    return running;
}

void GameWindow::set2D()
{
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0,width,0,height);
    glMatrixMode(GL_MODELVIEW);
}


GameWindow::GameWindow(bool running):running(running), height(screenHeight), width(screenWidth)
{
    glClearColor(0.0f,0.0f,0.4f,0.0f);
    glViewport(0.0f, 0.0f, width, height);
    glEnable(GL_DEPTH_TEST);

    shader=new Shader("ModelsVertexShader.glsl", "ModelsFragmentShader.glsl");
    Model1=new Model("models/nanosuit/nanosuit.obj");

    env = new Enviroment();

}

void GameWindow::setTransformationMatrices()
{

	glm::mat4 projection = glm::perspective(camera.Zoom, (float)screenWidth/(float)screenHeight, 0.1f, 100.0f);
	glm::mat4 view = camera.GetViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(shader->getProgram(), "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	glUniformMatrix4fv(glGetUniformLocation(shader->getProgram(), "view"), 1, GL_FALSE, glm::value_ptr(view));
}

void GameWindow::DrawModels()
{
	shader->Use();

	setTransformationMatrices();

	// Model transformaions
	rotationAngle +=0.2f;
	glm::mat4 model;
	//model = glm::scale(model, glm::vec3(0.2f, 0.2f, 0.2f));
	model=glm::rotate(model,rotationAngle ,glm::vec3(0.0f,1.0f,0.0f));
	model = glm::translate(model, glm::vec3(0.0f, -9.0f, 0.0f));

	// Actually draw the loaded model
	glUniformMatrix4fv(glGetUniformLocation(shader->getProgram(), "model"), 1, GL_FALSE, glm::value_ptr(model));
	Model1->Draw(*shader);
}

void GameWindow::Render()
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    /*	1- Get key press
     * 	2- launch appropriate enviroemnt
     * 	3- load appropriate models
     */

    if(glfwGetKey( GLFW_KEY_F1 ) == GLFW_PRESS || level==1)
    {
    	level=1;
		env->Render(1);
		env->Update();
		//DrawModels();
    }
    if(glfwGetKey( GLFW_KEY_F2 ) == GLFW_PRESS || level==2)
    {
    	level=2;
		env->Render(2);
		env->Update();
		//DrawModels();

    }
    if(glfwGetKey( GLFW_KEY_F3 ) == GLFW_PRESS || level==3)
    {
    	level=3;
		env->Render(3);
		env->Update();
		//DrawModels();
    }

    DrawModels();

    glfwSwapBuffers();

}


void GameWindow::Update()
{


}


GameWindow::~GameWindow()
{

}
