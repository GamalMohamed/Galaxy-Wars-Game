#include "gamewindow.h"
#include "enviroment.h"

Enviroment* env;
int level = 1;

//Setup the Camera
Camera camera(glm::vec3(0.0f, 0.0f, 20.0f));

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


	this->shader=new Shader("Shaders/ModelsVertexShader.glsl", "Shaders/ModelsFragmentShader.glsl");

	models=new Model*[numOfModels];

	//models[0]=new Model("Models/Others/Ocean/Ocean.obj");

	/*
	models[1]=new Model("Models/SpaceShips/Arc-170/obj 2/Arc170.obj");
	models[2]=new Model("Models/SpaceShips/CombatShip/CombatShip.obj");
	models[3]=new Model("Models/SpaceShips/MRX22 Recon Flyer/MRX22 Recon Flyer.obj");
	models[7]=new Model("Models/SpaceShips/X-17 Viper/X-17 Viper flying.obj");

	models[8]=new Model("Models/UFOs/Flying Disk/flying Disk flying.obj");

	models[13]=new Model("Models/Others/Moon/moon.obj");
	*/

	models[5]=new Model("Models/SpaceShips/starcruiser military/Starcruiser military.obj");
	models[6]=new Model("Models/SpaceShips/Wraith Raider Starship/Wraith Raider Starship.obj");
	models[4]=new Model("Models/SpaceShips/SpaceTrident/SpaceTrident.obj");

	models[9]=new Model("Models/UFOs/ufo/UFO.obj");

	models[10]=new Model("Models/Obstacles/Asteroid/Asteroid.obj");
	models[11]=new Model("Models/Obstacles/Missile/missile.obj");
	models[12]=new Model("Models/Obstacles/Rock/rock.obj");


    env = new Enviroment();


}


void GameWindow::setTransformationMatrices()
{

	glm::mat4 projection = glm::perspective(camera.Zoom, (float)screenWidth/(float)screenHeight, 0.1f, 100.0f);
	glm::mat4 view = camera.GetViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(shader->getProgram(), "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	glUniformMatrix4fv(glGetUniformLocation(shader->getProgram(), "view"), 1, GL_FALSE, glm::value_ptr(view));
}

glm::mat4 GameWindow::ModelTransformations(float Sx,float Sy,float Sz, float Rx,float Ry,float Rz,float rotationAngle, float Tx,float Ty,float Tz)
{
	glm::mat4 model;
	model = glm::scale(model, glm::vec3(Sx,Sy, Sz));
	model=glm::rotate(model,rotationAngle ,glm::vec3(Rx,Ry,Rz));
	model = glm::translate(model, glm::vec3(Tx, Ty, Tz));
	return model;
}

void GameWindow::DrawModels()
{
	this->shader->Use();

	this->setTransformationMatrices();

	/*
	//Ocean
	glm::mat4 model1= ModelTransformations(8.0f,7.2f, 0.0f,1.0f,0.0f,0.0f,-200.0f,0.0f,0.0f,0.0f);
	glUniformMatrix4fv(glGetUniformLocation(shader->getProgram(), "model"), 1, GL_FALSE, glm::value_ptr(model1));
	models[0]->Draw(*shader);
	*/

	//Asteroid
	glm::mat4 model2= ModelTransformations(0.5f,0.5f, 0.5f, 1.0f,0.0f,0.0f,-200.0f, -18.0f, 16.0f, 0.0f);
	glUniformMatrix4fv(glGetUniformLocation(shader->getProgram(), "model"), 1, GL_FALSE, glm::value_ptr(model2));
	models[10]->Draw(*shader);

	//Rock
	glm::mat4 model3; //= ModelTransformations(1.0f,1.0f, 1.0f, 0.0f,0.0f,1.0f,-200.0f, 30.0f,7.0f,0.0f);
	model3 = glm::scale(model3, glm::vec3(0.4f,0.4f, 0.4f));
	model3 = glm::translate(model3, glm::vec3(25.0f,20.0f,0.0f));
	glUniformMatrix4fv(glGetUniformLocation(shader->getProgram(), "model"), 1, GL_FALSE, glm::value_ptr(model3));
	models[12]->Draw(*shader);

	//Missile
	glm::mat4 model4= ModelTransformations(0.5f,0.5f, 0.5f, 0.0f,0.0f,1.0f,300.0f, 0.0f,0.0f,0.0f);
	glUniformMatrix4fv(glGetUniformLocation(shader->getProgram(), "model"), 1, GL_FALSE, glm::value_ptr(model4));
	models[11]->Draw(*shader);

	//UFO
	glm::mat4 model5= ModelTransformations(0.15f,0.15f, 0.15f, 1.0f,0.0f,0.0f,300.0f, -90.0f,70.0f,0.0f);
	glUniformMatrix4fv(glGetUniformLocation(shader->getProgram(), "model"), 1, GL_FALSE, glm::value_ptr(model5));
	models[9]->Draw(*shader);


	//Wrath raider
	glm::mat4 model6; //= ModelTransformations(0.05f,0.05f, 0.05f, 0.0f,0.0f,1.0f,300.0f, 0.0f,-20.0f,0.0f);
	model6 = glm::scale(model6, glm::vec3(0.05f,0.05f, 0.05f));
	model6=glm::rotate(model6,-90.0f, glm::vec3(1.0f,0.0f,0.0f));
	model6 = glm::translate(model6, glm::vec3(0.0f,800.0f,0.0f));
	glUniformMatrix4fv(glGetUniformLocation(shader->getProgram(), "model"), 1, GL_FALSE, glm::value_ptr(model6));
	models[6]->Draw(*shader);

	//Starcruiser military
	glm::mat4 model7; //= ModelTransformations(0.03f,0.03f, 0.03f, 0.0f,0.0f,1.0f,300.0f, 0.0f,60.0f,0.0f);
	model7 = glm::scale(model7, glm::vec3(0.05f,0.05f, 0.05f));
	model7=glm::rotate(model7,90.0f, glm::vec3(1.0f,0.0f,0.0f));
	model7 = glm::translate(model7, glm::vec3(0.0f,-1500.0f,0.0f));
	glUniformMatrix4fv(glGetUniformLocation(shader->getProgram(), "model"), 1, GL_FALSE, glm::value_ptr(model7));
	models[5]->Draw(*shader);

	//SpaceTrident
	glm::mat4 model8;
	model8 = glm::scale(model8, glm::vec3(1.25f,1.25f, 1.25f));
	model8=glm::rotate(model8,90.0f, glm::vec3(1.0f,0.0f,0.0f));
	model8 = glm::translate(model8, glm::vec3(11.0f,-3.0f,0.0f));
	glUniformMatrix4fv(glGetUniformLocation(shader->getProgram(), "model"), 1, GL_FALSE, glm::value_ptr(model8));
	models[4]->Draw(*shader);

}


void GameWindow::Render()
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    /*
     1- Get key press to detect level
     2- launch appropriate environment
     3- load appropriate models with corresponding transformations
    */

    if(level==1)
    {
    	level=1;
		env->Render(1);
		DrawModels();
    }


    glfwSwapBuffers();

}

void GameWindow::Update()
{


}


GameWindow::~GameWindow()
{

}
