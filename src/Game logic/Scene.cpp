#include "Scene.h"


/*static float Asteroids[6]={-50.f,-75.f,-100.f,-125.f,-150.f};
static float UFOs[6]={400.f,550.f,700.f,850.f,1000.f};*/
Scene::Scene()
{
	this->player=new Player();

	EnemiesNo=10;
	this->Enemies=new Enemy*[EnemiesNo];

	float Initials[2]={-50.f,400.f};
	float Displacements[2]={-25.f,150.f};
	for(int i=0;i<EnemiesNo;i++)
	{
		if(i<5)
		{
			this->Enemies[i]=new Enemy("Asteroid");
			this->Enemies[i]->setInitialPosition(Initials[0]);
			Initials[0]+= Displacements[0];
		}
		else
		{
			this->Enemies[i]=new Enemy("UFO");
			this->Enemies[i]->setInitialPosition(Initials[1]);
			Initials[1]+= Displacements[1];
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
