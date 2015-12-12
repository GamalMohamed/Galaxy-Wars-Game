/*
 * GameManager.h
 *
 *  Created on: Dec 10, 2015
 *      Author: jimmy
 */

#ifndef GAMEMANAGER_H_
#define GAMEMANAGER_H_

#include "../Defs.h"
#include "ResourcesSystem.h"
#include "CameraSystem.h"
#include "RenderingSystem.h"
#include "MovementSystem.h"
#include "../Game logic/Scene.h"

class Shader;
class Scene;
class RenderingSystem;
class MovementSystem;
class ResourcesSystem;
class Camera;

class GameManager
{
private:
	bool running;
	RenderingSystem *renderSystem;
	ResourcesSystem *resourcesSystem;
	MovementSystem *movementSystem;
	Camera* cameraSystem;
	Scene* scene;

	GameManager(bool running);
	~GameManager();


public:
	void runGameLoop();

	static GameManager& getGameManager();
	static void destroyGameManager();

};

#endif /* GAMEMANAGER_H_ */
