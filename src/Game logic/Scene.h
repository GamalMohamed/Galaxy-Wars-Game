#ifndef SCENE_H_
#define SCENE_H_

#include "../Defs.h"
#include "Player.h"
#include "Enemy.h"
#include "../Game engine/GameManager.h"

class Scene
{
	friend class RenderingSystem;
	friend class MovementSystem;
private:
	Camera* SceneCamera;
	ResourcesSystem* SceneResources;

	Player* player;
	Model* Background;
	Enemy** Enemies;

	int EnemiesNo; //no. of enemies in current level


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

	int getEnemiesNo();
	void setEnemiesNo(int enemiesNo);

};

#endif /* SCENE_H_ */
