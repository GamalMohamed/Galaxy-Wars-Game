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


static float WrathInitialZ=-200.f;
static float WrathdispZ=150.f;
void MovementSystem::ModelTransformations(Scene* scene)
{
	//Player transformations
	glm::mat4 PlayerModel;
	PlayerModel = glm::scale(PlayerModel, glm::vec3(0.01f,0.01f, 0.01f));
	PlayerModel = glm::rotate(PlayerModel,-PI/2.0f, glm::vec3(1.0f,0.0f,0.0f));
	PlayerModel = glm::translate(PlayerModel, glm::vec3(this->HorizontalMotion,VerticalMotion,WrathInitialZ+=WrathdispZ));
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

}
