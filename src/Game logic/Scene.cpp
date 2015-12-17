#include "Scene.h"

Scene::Scene()
{
	this->player=new Player();

	EnemiesNo=10;
	this->Enemies=new Enemy*[EnemiesNo];

	for(int i=0;i<10;i++){
		this->Enemies[i]=new Enemy();
	}




}

Scene::~Scene()
{

}

Camera* Scene::getSceneCamera(){
	return SceneCamera;
}

void Scene::setSceneCamera(Camera* sceneCamera) {
	SceneCamera = sceneCamera;
}

ResourcesSystem* Scene::getSceneResources(){
	return SceneResources;
}

void Scene::setSceneResources(ResourcesSystem* sceneModels)
{
	SceneResources = sceneModels;

	this->player->setModel(this->SceneResources->models[1]);
	this->Background=this->SceneResources->models[0];

	//float trackers[2]={-50.f,400.f};
	for(int i=0; i<EnemiesNo; i++)
	{
		if(i<5)
		{
			this->Enemies[i]->setModel(this->SceneResources->models[i+2]);
			this->Enemies[i]->setType("Asteroid");
			//this->Enemies[i]->setInitialPosition(trackers[0]-=25.f);

		}
		else
		{
			this->Enemies[i]->setModel(this->SceneResources->models[i+2]);
			this->Enemies[i]->setType("UFO");
			//this->Enemies[i]->setInitialPosition(trackers[1]+=150.f);

		}

	}

}

Player* Scene::getPlayer(){
	return player;
}


void Scene::setPlayer(Player* player) {
	this->player = player;
}

int Scene::getEnemiesNo(){
	return EnemiesNo;
}

void Scene::setEnemiesNo(int enemiesNo) {
	EnemiesNo = enemiesNo;
}
