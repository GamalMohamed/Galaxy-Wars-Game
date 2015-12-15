#include "MovementSystem.h"


MovementSystem::MovementSystem()
{
	this->HorizontalMotion=0.f;
	this->VerticalMotion=850.f;
}

MovementSystem::~MovementSystem()
{

}

float MovementSystem::getVerticalMotion(){
	return VerticalMotion;
}


static float WrathInitialZ= -200.f; //WrathSpeed=CamSpeed*100.f
static float UFOInitialZ= 300.0f; //UFOSpeed=CamSpeed*500.f
static float AsteroidInitialZ= -50.0f; //AsteroidSpeed=CamSpeed*100.f
void MovementSystem::ModelTransformations(Scene* scene)
{
	//Player transformations
	glm::mat4 PlayerModel;
	PlayerModel = glm::scale(PlayerModel, glm::vec3(0.01f,0.01f, 0.01f));
	PlayerModel = glm::rotate(PlayerModel,-PI/2.0f, glm::vec3(1.0f,0.0f,0.0f));
	PlayerModel = glm::translate(PlayerModel, glm::vec3(HorizontalMotion,VerticalMotion,WrathInitialZ+=20.f));
	scene->getPlayer()->getModel()->setModelTransformations(PlayerModel);

	if(glfwGetKey( GLFW_KEY_RIGHT ) == GLFW_PRESS){
		this->HorizontalMotion+=7.5f;
	}

	if(glfwGetKey( GLFW_KEY_LEFT ) == GLFW_PRESS){
		this->HorizontalMotion-=7.5f;
	}

	if(glfwGetKey( GLFW_KEY_UP ) == GLFW_PRESS){
		this->VerticalMotion+=7.5f;
	}

	if(glfwGetKey( GLFW_KEY_DOWN) == GLFW_PRESS){
		this->VerticalMotion-=7.5f;
	}


	glm::mat4 UFOModel;
	UFOModel = glm::scale(UFOModel, glm::vec3(0.002f,0.002f, 0.002f));
	UFOModel=glm::rotate(UFOModel,-PI/2.f, glm::vec3(1.0f,0.0f,0.0f));
	UFOModel = glm::translate(UFOModel, glm::vec3(-55.0f,150.0f,UFOInitialZ+=99.5f));
	scene->Enemies[0]->getModel()->setModelTransformations(UFOModel);


	glm::mat4 AsteroidModel;
	AsteroidModel = glm::scale(AsteroidModel, glm::vec3(0.01f,0.01f, 0.01f));
	AsteroidModel=glm::rotate(AsteroidModel,PI/2.f, glm::vec3(1.0f,0.0f,0.0f));
	AsteroidModel = glm::translate(AsteroidModel, glm::vec3(10.0f,-20.0f,AsteroidInitialZ-=19.8f));
	scene->Enemies[1]->getModel()->setModelTransformations(AsteroidModel);

}
