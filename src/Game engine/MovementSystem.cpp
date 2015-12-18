#include "MovementSystem.h"


MovementSystem::MovementSystem()
{

}

MovementSystem::~MovementSystem()
{

}


void MovementSystem::PlayerTransformations(Scene* scene)
{
	glm::mat4 PlayerModel;
	PlayerModel = glm::scale(PlayerModel, glm::vec3(0.01f,0.01f, 0.01f));
	PlayerModel = glm::rotate(PlayerModel,-PI/2.0f, glm::vec3(1.0f,0.0f,0.0f));
	PlayerModel = glm::translate(PlayerModel, glm::vec3(scene->getPlayer()->getHorizontalMotion(), scene->getPlayer()->getVerticalMotion(), scene->getPlayer()->getInitialPosition()+=scene->getPlayer()->getVelocity()));
	scene->getPlayer()->getModel()->setModelTransformations(PlayerModel);

	MovePlayer(scene->getPlayer()->getHorizontalMotion(),scene->getPlayer()->getVerticalMotion());

}

void MovementSystem::MovePlayer(float &horizontal, float &vertical)
{
	if(glfwGetKey( GLFW_KEY_RIGHT ) == GLFW_PRESS){
		horizontal+=7.5f;
	}

	if(glfwGetKey( GLFW_KEY_LEFT ) == GLFW_PRESS){
		horizontal-=7.5f;
	}

	if(glfwGetKey( GLFW_KEY_UP ) == GLFW_PRESS){
		vertical+=7.5f;
	}

	if(glfwGetKey( GLFW_KEY_DOWN) == GLFW_PRESS){
		vertical-=7.5f;
	}
}

void MovementSystem::EnemiesTransformations(Scene* scene)
{
	for (int i = 0; i <5; i++)
	{
		glm::mat4 AsteroidModel;
		AsteroidModel = glm::scale(AsteroidModel, glm::vec3(0.01f,0.01f, 0.01f));
		AsteroidModel=glm::rotate(AsteroidModel,PI/2.f, glm::vec3(1.0f,0.0f,0.0f));
		AsteroidModel = glm::translate(AsteroidModel, glm::vec3(scene->Enemies[i]->getHorizontalMotion(),scene->Enemies[i]->getVerticalMotion(),scene->Enemies[i]->getInitialPosition()+= scene->Enemies[i]->getVelocity()));
		scene->Enemies[i]->getModel()->setModelTransformations(AsteroidModel);
	}

	for (int i = 5; i <= 9; i++)
	{
		glm::mat4 UFOModel;
		UFOModel = glm::scale(UFOModel, glm::vec3(0.002f,0.002f, 0.002f));
		UFOModel=glm::rotate(UFOModel,-PI/2.f, glm::vec3(1.0f,0.0f,0.0f));
		UFOModel = glm::translate(UFOModel, glm::vec3(scene->Enemies[i]->getHorizontalMotion(),scene->Enemies[i]->getVerticalMotion(),scene->Enemies[i]->getInitialPosition()+= scene->Enemies[i]->getVelocity()));
		scene->Enemies[i]->getModel()->setModelTransformations(UFOModel);
	}


	/* Other models
	//Missile
	glm::mat4 model4;
	model4 = glm::scale(model4, glm::vec3(0.5f,0.5f, 0.5f));
	model4=glm::rotate(model4,300.0f, glm::vec3(0.0f,0.0f,1.0f));
	glUniformMatrix4fv(glGetUniformLocation(scene->SceneResources->shader->getProgram(), "model"), 1, GL_FALSE, glm::value_ptr(model4));
	scene->SceneResources->models[11]->Draw(*scene->SceneResources->shader);

	//Rock
	glm::mat4 model3;
	model3 = glm::scale(model3, glm::vec3(0.4f,0.4f, 0.4f));
	model3 = glm::translate(model3, glm::vec3(25.0f,20.0f,0.0f));
	glUniformMatrix4fv(glGetUniformLocation(scene->SceneResources->shader->getProgram(), "model"), 1, GL_FALSE, glm::value_ptr(model3));
	scene->SceneResources->models[12]->Draw(*scene->SceneResources->shader);

	//Starcruiser military
	glm::mat4 model7;
	model7 = glm::scale(model7, glm::vec3(0.05f,0.05f, 0.05f));
	model7=glm::rotate(model7,90.0f, glm::vec3(1.0f,0.0f,0.0f));
	model7 = glm::translate(model7, glm::vec3(0.0f,-1500.0f,0.0f));
	glUniformMatrix4fv(glGetUniformLocation(scene->SceneResources->shader->getProgram(), "model"), 1, GL_FALSE, glm::value_ptr(model7));
	scene->SceneResources->models[5]->Draw(*scene->SceneResources->shader);

	//SpaceTrident
	glm::mat4 model8;
	model8 = glm::scale(model8, glm::vec3(1.25f,1.25f, 1.25f));
	model8=glm::rotate(model8,90.0f, glm::vec3(1.0f,0.0f,0.0f));
	model8 = glm::translate(model8, glm::vec3(11.0f,-3.0f,0.0f));
	glUniformMatrix4fv(glGetUniformLocation(scene->SceneResources->shader->getProgram(), "model"), 1, GL_FALSE, glm::value_ptr(model8));
	scene->SceneResources->models[4]->Draw(*scene->SceneResources->shader);
	*/

}


void MovementSystem::ModelTransformations(Scene* scene)
{
	PlayerTransformations(scene);

	EnemiesTransformations(scene);
}
