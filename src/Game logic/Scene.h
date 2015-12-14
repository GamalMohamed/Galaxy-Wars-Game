#ifndef SCENE_H_
#define SCENE_H_

#include "../Defs.h"
#include "Player.h"
#include "Enemy.h"
#include "../Game engine/GameManager.h"

class Scene
{
	friend class RenderingSystem;
private:
	Camera* SceneCamera;
	ResourcesSystem* SceneResources;

	Player* player;
	std::vector<Enemy*> Enemies;


public:
    Scene();
    ~Scene();

    //void AddEnemiesToScene();
    //void CreateEnemiesOfLevel();

	Camera* getSceneCamera();
	void setSceneCamera(Camera*);
	ResourcesSystem* getSceneResources();
	void setSceneResources(ResourcesSystem*);
	Player* getPlayer();
	void setPlayer(Player* player);
};

#endif /* SCENE_H_ */
