/*
 * GameManager.cpp
 *
 *  Created on: Dec 10, 2015
 *      Author: jimmy
 */

#include "GameManager.h"

#define Updates_Per_Second 60.0f

GameManager::GameManager(bool running)
{
	this->running=running;

	this->renderSystem=new RenderingSystem();
	this->resourcesSystem=new ResourcesSystem();

	this->cameraSystem=new Camera(glm::vec3(0.0f, 0.0f, 0.0f));

	this->scene=new Scene();
	this->movementSystem=new MovementSystem();


}


void GameManager::runGameLoop()
{
	/*double lastTime = glfwGetTime();
	double deltaTime = 0.0f;*/

	while (this->running)
	{
		/* frames adjustment suspended for now
		 double currentTime = glfwGetTime();
		deltaTime += (currentTime - lastTime) * Updates_Per_Second;
		lastTime = currentTime;

		while (deltaTime >= 1.0f)
		{
			--deltaTime;
		}
		*/

		this->scene->setSceneResources(this->resourcesSystem);
		this->scene->setSceneCamera(this->cameraSystem);

		this->movementSystem->ModelTransformations(this->scene);

		this->cameraSystem->updatePositionY(0.2f);


		this->renderSystem->Render(this->scene);

		this->running = ((glfwGetWindowParam( GLFW_OPENED )) && (glfwGetKey( GLFW_KEY_ESC ) != GLFW_PRESS));
	}
}

GameManager& GameManager::getGameManager()
{
	static GameManager *gameManager = NULL;

	if (gameManager == NULL)
	{
		//Basic window setup
		 glfwInit();
		 glfwOpenWindowHint(GLFW_FSAA_SAMPLES, 4);
		 glfwOpenWindowHint(GLFW_OPENGL_VERSION_MAJOR, 2);
		 glfwOpenWindowHint(GLFW_OPENGL_VERSION_MINOR, 1);
		 glfwOpenWindow(screenWidth, screenHeight, 8,8,8,8, 0,0, GLFW_WINDOW );
		 glfwEnable( GLFW_STICKY_KEYS );
		 glfwSetWindowTitle( "Galaxy Wars" );

		 glewInit();

		gameManager = new GameManager(true);

		std::cout << "Game Started !" << std::endl;
	}

	    return *gameManager;

}

GameManager::~GameManager()
{


}

void GameManager::destroyGameManager()
{
    GameManager *gameManager = &getGameManager();
    delete gameManager;

    std::cout << "Game Finished !" << std::endl;

    glfwTerminate();

}


