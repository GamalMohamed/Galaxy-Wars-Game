#include "Scene.h"


Scene::Scene()
{
	this->player=new Player();

	EnemiesNo=10;
	this->Enemies=new Enemy*[EnemiesNo];

	float YInitials[2]={40.f,50.f};
	float Displacements[2]={125.f,25.f};
	for(int i=0;i<EnemiesNo;i++)
	{
		if(i<5)
		{
			this->Enemies[i]=new Enemy("Asteroid");
			this->Enemies[i]->setInitialYPosition(YInitials[0]);
			YInitials[0]+= Displacements[0];
		}
		else
		{
			this->Enemies[i]=new Enemy("UFO");
			this->Enemies[i]->setInitialYPosition(YInitials[1]);
			YInitials[1]+= Displacements[1];
		}

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

	for(int i=0; i<EnemiesNo; i++)
	{
		if(i<5)
		{
			this->Enemies[i]->setModel(this->SceneResources->models[i+2]);
		}
		else
		{
			this->Enemies[i]->setModel(this->SceneResources->models[i+2]);
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
