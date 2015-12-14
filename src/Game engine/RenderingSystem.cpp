/*
 * RenderingSystem.cpp
 *
 *  Created on: Dec 10, 2015
 *      Author: jimmy
 */

#include "RenderingSystem.h"


RenderingSystem::RenderingSystem()
{
	height=screenHeight;
	width=screenWidth;

	glClearColor(0.0f,0.0f,0.4f,0.0f);
	glViewport(0.0f, 0.0f, width, height);
	glEnable(GL_DEPTH_TEST);

}

RenderingSystem::~RenderingSystem()
{

}

void RenderingSystem::set2D()
{
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0,width,0,height);
    glMatrixMode(GL_MODELVIEW);
}

void RenderingSystem::setTransformationMatrices(Scene* scene)
{

	glm::mat4 projection = glm::perspective(scene->SceneCamera->Zoom, (float)screenWidth/(float)screenHeight, 0.1f, 100.0f);
	glm::mat4 view = scene->SceneCamera->GetViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(scene->SceneResources->shader->getProgram(), "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	glUniformMatrix4fv(glGetUniformLocation(scene->SceneResources->shader->getProgram(), "view"), 1, GL_FALSE, glm::value_ptr(view));
}


void RenderingSystem::DrawBackground(Scene* scene,int factor)
{
	//Space2D
	glm::mat4 model0;
	model0=glm::rotate(model0, PI/2.f,glm::vec3(1.0f,0.0f,0.0f)); //Remember that angle better to be in RADIANS !!
	model0 = glm::translate(model0, glm::vec3(0.0f, -33.0f, -factor*45.7f)); // Remember that axes are also rotated !!
	glUniformMatrix4fv(glGetUniformLocation(scene->SceneResources->shader->getProgram(), "model"), 1, GL_FALSE, glm::value_ptr(model0));
	scene->SceneResources->models[0]->Draw(*scene->SceneResources->shader);
}

static int repeat=5;
void RenderingSystem::DrawModels(Scene* scene)
{

	scene->SceneResources->shader->Use();

	this->setTransformationMatrices(scene);

	for (int i = 0; i < repeat; i++) {
		this->DrawBackground(scene,i);
	}
	repeat++;

	//this->DrawBackground(scene,0);


	//Render Player !
	glUniformMatrix4fv(glGetUniformLocation(scene->SceneResources->shader->getProgram(), "model"), 1, GL_FALSE, glm::value_ptr(scene->player->getModel()->getModelTransformations()));
	if(glfwGetKey( GLFW_KEY_SPACE ) != GLFW_PRESS){
		scene->player->getModel()->Draw(*scene->SceneResources->shader);
	}

	/* Other models
	//Asteroid
	glm::mat4 model2;
	model2 = glm::scale(model2, glm::vec3(0.5f,0.5f, 0.5f));
	model2=glm::rotate(model2,-200.0f, glm::vec3(1.0f,0.0f,0.0f));
	model2 = glm::translate(model2, glm::vec3(-18.0f,16.0f,0.0f));
	glUniformMatrix4fv(glGetUniformLocation(scene->SceneResources->shader->getProgram(), "model"), 1, GL_FALSE, glm::value_ptr(model2));
	scene->SceneResources->models[10]->Draw(*scene->SceneResources->shader);

	//Missile
	glm::mat4 model4;
	model4 = glm::scale(model4, glm::vec3(0.5f,0.5f, 0.5f));
	model4=glm::rotate(model4,300.0f, glm::vec3(0.0f,0.0f,1.0f));
	glUniformMatrix4fv(glGetUniformLocation(scene->SceneResources->shader->getProgram(), "model"), 1, GL_FALSE, glm::value_ptr(model4));
	scene->SceneResources->models[11]->Draw(*scene->SceneResources->shader);

	//UFO
	glm::mat4 model5;
	model5 = glm::scale(model5, glm::vec3(0.15f,0.15f, 0.15f));
	model5=glm::rotate(model5,300.0f, glm::vec3(1.0f,0.0f,0.0f));
	model5 = glm::translate(model5, glm::vec3(-90.0f,70.0f,0.0f));
	glUniformMatrix4fv(glGetUniformLocation(scene->SceneResources->shader->getProgram(), "model"), 1, GL_FALSE, glm::value_ptr(model5));
	scene->SceneResources->models[9]->Draw(*scene->SceneResources->shader);

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


void RenderingSystem::Render(Scene* scene)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	DrawModels(scene);

	glfwSwapBuffers();
}







