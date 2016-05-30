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
	glUniformMatrix4fv(glGetUniformLocation(scene->SceneResources->lightingShader->getProgram(), "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	glUniformMatrix4fv(glGetUniformLocation(scene->SceneResources->lightingShader->getProgram(), "view"), 1, GL_FALSE, glm::value_ptr(view));
}


void RenderingSystem::DrawBackground(Scene* scene,int factor)
{
	//Space2D
	glm::mat4 model0;
	model0=glm::scale(model0,glm::vec3(0.2f,0.155f,0.1f));
	model0=glm::rotate(model0, PI/2.f,glm::vec3(1.0f,0.0f,0.0f)); //Remember that angle better to be in RADIANS !!
	model0 = glm::translate(model0, glm::vec3(0.0f, 0.0f, -factor*45.7f)); // Remember that axes are also rotated !!
	glUniformMatrix4fv(glGetUniformLocation(scene->SceneResources->lightingShader->getProgram(), "model"), 1, GL_FALSE, glm::value_ptr(model0));
	scene->Background->Draw(*scene->SceneResources->lightingShader);


}

static int repeat=5;
void RenderingSystem::DrawModels(Scene* scene)
{

	scene->SceneResources->lightingShader->Use();

	this->setTransformationMatrices(scene);



	//Continuously draw background
	for (int i = 0; i < repeat; i++) {
		this->DrawBackground(scene,i);
	}
	repeat++;



	//Render Player
	glUniformMatrix4fv(glGetUniformLocation(scene->SceneResources->lightingShader->getProgram(), "model"), 1, GL_FALSE, glm::value_ptr(scene->player->getModel()->getModelTransformations()));
	scene->player->getModel()->Draw(*scene->SceneResources->lightingShader);

	//Render Enemies
	for(int i=0;i<scene->getEnemiesNo();i++)
	{
		glUniformMatrix4fv(glGetUniformLocation(scene->SceneResources->lightingShader->getProgram(), "model"), 1, GL_FALSE, glm::value_ptr(scene->Enemies[i]->getModel()->getModelTransformations()));
		scene->Enemies[i]->getModel()->Draw(*scene->SceneResources->lightingShader);

	}

}


void RenderingSystem::Render(Scene* scene)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	DrawModels(scene);


	ComputeLight(scene);


	glfwSwapBuffers();
}


void RenderingSystem::ComputeLight(Scene* scene)
{
	scene->SceneResources->lightingShader->Use();

	float Xs[4]={0.7f,2.3f,-4.0f,0.0f};
	float Ys[4]={0.2f,-3.3f,2.0f,0.0f};
	float Zs[4]={2.0f,-4.0f,-12.0f,-3.0f};

	glm::vec3 pointLightPositions[] = {
		glm::vec3( Xs[0],  Ys[0],  Zs[0]),
		glm::vec3( Xs[1],  Ys[1],  Zs[1]),
		glm::vec3( Xs[2],  Ys[2],  Zs[2]),
		glm::vec3( Xs[3],  Ys[3],  Zs[3])
	};

	glUniform1i(glGetUniformLocation(scene->SceneResources->lightingShader->getProgram(), "material.diffuse"),  0);
	glUniform1i(glGetUniformLocation(scene->SceneResources->lightingShader->getProgram(), "material.specular"), 1);
	glUniform1f(glGetUniformLocation(scene->SceneResources->lightingShader->getProgram(), "material.shininess"), 32.0f);


	GLint viewPosLoc = glGetUniformLocation(scene->SceneResources->lightingShader->getProgram(), "viewPos");
	glUniform3f(viewPosLoc, scene->getSceneCamera()->Position.x, scene->getSceneCamera()->Position.y, scene->getSceneCamera()->Position.z);


	// Directional light
	glUniform3f(glGetUniformLocation(scene->SceneResources->lightingShader->getProgram(), "dirLight.direction"), -0.2f, -1.0f, -0.3f);
	glUniform3f(glGetUniformLocation(scene->SceneResources->lightingShader->getProgram(), "dirLight.ambient"), 0.05f, 0.05f, 0.05f);
	glUniform3f(glGetUniformLocation(scene->SceneResources->lightingShader->getProgram(), "dirLight.diffuse"), 0.4f, 0.4f, 0.4f);
	glUniform3f(glGetUniformLocation(scene->SceneResources->lightingShader->getProgram(), "dirLight.specular"), 0.5f, 0.5f, 0.5f);

	// Point light 1
	glUniform3f(glGetUniformLocation(scene->SceneResources->lightingShader->getProgram(), "pointLights[0].position"), pointLightPositions[0].x, pointLightPositions[0].y, pointLightPositions[0].z);
	glUniform3f(glGetUniformLocation(scene->SceneResources->lightingShader->getProgram(), "pointLights[0].ambient"), 0.05f, 0.05f, 0.05f);
	glUniform3f(glGetUniformLocation(scene->SceneResources->lightingShader->getProgram(), "pointLights[0].diffuse"), 0.8f, 0.8f, 0.8f);
	glUniform3f(glGetUniformLocation(scene->SceneResources->lightingShader->getProgram(), "pointLights[0].specular"), 1.0f, 1.0f, 1.0f);
	glUniform1f(glGetUniformLocation(scene->SceneResources->lightingShader->getProgram(), "pointLights[0].constant"), 1.0f);
	glUniform1f(glGetUniformLocation(scene->SceneResources->lightingShader->getProgram(), "pointLights[0].linear"), 0.09);
	glUniform1f(glGetUniformLocation(scene->SceneResources->lightingShader->getProgram(), "pointLights[0].quadratic"), 0.032);

	// Point light 2
	glUniform3f(glGetUniformLocation(scene->SceneResources->lightingShader->getProgram(), "pointLights[1].position"), pointLightPositions[1].x, pointLightPositions[1].y, pointLightPositions[1].z);
	glUniform3f(glGetUniformLocation(scene->SceneResources->lightingShader->getProgram(), "pointLights[1].ambient"), 0.05f, 0.05f, 0.05f);
	glUniform3f(glGetUniformLocation(scene->SceneResources->lightingShader->getProgram(), "pointLights[1].diffuse"), 0.8f, 0.8f, 0.8f);
	glUniform3f(glGetUniformLocation(scene->SceneResources->lightingShader->getProgram(), "pointLights[1].specular"), 1.0f, 1.0f, 1.0f);
	glUniform1f(glGetUniformLocation(scene->SceneResources->lightingShader->getProgram(), "pointLights[1].constant"), 1.0f);
	glUniform1f(glGetUniformLocation(scene->SceneResources->lightingShader->getProgram(), "pointLights[1].linear"), 0.09);
	glUniform1f(glGetUniformLocation(scene->SceneResources->lightingShader->getProgram(), "pointLights[1].quadratic"), 0.032);

	// Point light 3
	glUniform3f(glGetUniformLocation(scene->SceneResources->lightingShader->getProgram(), "pointLights[2].position"), pointLightPositions[2].x, pointLightPositions[2].y, pointLightPositions[2].z);
	glUniform3f(glGetUniformLocation(scene->SceneResources->lightingShader->getProgram(), "pointLights[2].ambient"), 0.05f, 0.05f, 0.05f);
	glUniform3f(glGetUniformLocation(scene->SceneResources->lightingShader->getProgram(), "pointLights[2].diffuse"), 0.8f, 0.8f, 0.8f);
	glUniform3f(glGetUniformLocation(scene->SceneResources->lightingShader->getProgram(), "pointLights[2].specular"), 1.0f, 1.0f, 1.0f);
	glUniform1f(glGetUniformLocation(scene->SceneResources->lightingShader->getProgram(), "pointLights[2].constant"), 1.0f);
	glUniform1f(glGetUniformLocation(scene->SceneResources->lightingShader->getProgram(), "pointLights[2].linear"), 0.09);
	glUniform1f(glGetUniformLocation(scene->SceneResources->lightingShader->getProgram(), "pointLights[2].quadratic"), 0.032);

	// Point light 4
	glUniform3f(glGetUniformLocation(scene->SceneResources->lightingShader->getProgram(), "pointLights[3].position"), pointLightPositions[3].x, pointLightPositions[3].y, pointLightPositions[3].z);
	glUniform3f(glGetUniformLocation(scene->SceneResources->lightingShader->getProgram(), "pointLights[3].ambient"), 0.05f, 0.05f, 0.05f);
	glUniform3f(glGetUniformLocation(scene->SceneResources->lightingShader->getProgram(), "pointLights[3].diffuse"), 0.8f, 0.8f, 0.8f);
	glUniform3f(glGetUniformLocation(scene->SceneResources->lightingShader->getProgram(), "pointLights[3].specular"), 1.0f, 1.0f, 1.0f);
	glUniform1f(glGetUniformLocation(scene->SceneResources->lightingShader->getProgram(), "pointLights[3].constant"), 1.0f);
	glUniform1f(glGetUniformLocation(scene->SceneResources->lightingShader->getProgram(), "pointLights[3].linear"), 0.09);
	glUniform1f(glGetUniformLocation(scene->SceneResources->lightingShader->getProgram(), "pointLights[3].quadratic"), 0.032);

	// SpotLight
	glUniform3f(glGetUniformLocation(scene->SceneResources->lightingShader->getProgram(), "spotLight.position"), scene->getSceneCamera()->Position.x, scene->getSceneCamera()->Position.y, scene->getSceneCamera()->Position.z);
	glUniform3f(glGetUniformLocation(scene->SceneResources->lightingShader->getProgram(), "spotLight.direction"), scene->getSceneCamera()->Front.x, scene->getSceneCamera()->Front.y, scene->getSceneCamera()->Front.z);
	glUniform3f(glGetUniformLocation(scene->SceneResources->lightingShader->getProgram(), "spotLight.ambient"), 0.0f, 0.0f, 0.0f);
	glUniform3f(glGetUniformLocation(scene->SceneResources->lightingShader->getProgram(), "spotLight.diffuse"), 1.0f, 1.0f, 1.0f);
	glUniform3f(glGetUniformLocation(scene->SceneResources->lightingShader->getProgram(), "spotLight.specular"), 1.0f, 1.0f, 1.0f);
	glUniform1f(glGetUniformLocation(scene->SceneResources->lightingShader->getProgram(), "spotLight.constant"), 1.0f);
	glUniform1f(glGetUniformLocation(scene->SceneResources->lightingShader->getProgram(), "spotLight.linear"), 0.09);
	glUniform1f(glGetUniformLocation(scene->SceneResources->lightingShader->getProgram(), "spotLight.quadratic"), 0.032);
	glUniform1f(glGetUniformLocation(scene->SceneResources->lightingShader->getProgram(), "spotLight.cutOff"), glm::cos(glm::radians(12.5f)));
	glUniform1f(glGetUniformLocation(scene->SceneResources->lightingShader->getProgram(), "spotLight.outerCutOff"), glm::cos(glm::radians(15.0f)));

}
