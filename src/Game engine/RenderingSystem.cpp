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
	scene->Background->Draw(*scene->SceneResources->shader);
}

static int repeat=5;
void RenderingSystem::DrawModels(Scene* scene)
{

	scene->SceneResources->shader->Use();

	this->setTransformationMatrices(scene);

	//Continuously draw background
	for (int i = 0; i < repeat; i++) {
		this->DrawBackground(scene,i);
	}
	repeat++;


	//Render Player
	glUniformMatrix4fv(glGetUniformLocation(scene->SceneResources->shader->getProgram(), "model"), 1, GL_FALSE, glm::value_ptr(scene->player->getModel()->getModelTransformations()));
	scene->player->getModel()->Draw(*scene->SceneResources->shader);

	//Render Enemies
	for(int i=0;i<scene->getEnemiesNo();i++)
	{
		glUniformMatrix4fv(glGetUniformLocation(scene->SceneResources->shader->getProgram(), "model"), 1, GL_FALSE, glm::value_ptr(scene->Enemies[i]->getModel()->getModelTransformations()));
		scene->Enemies[i]->getModel()->Draw(*scene->SceneResources->shader);
	}

}


void RenderingSystem::Render(Scene* scene)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	DrawModels(scene);

	glfwSwapBuffers();
}







