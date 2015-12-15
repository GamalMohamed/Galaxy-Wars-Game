#include "Scene.h"

Scene::Scene()
{
	this->player=new Player();

	this->Enemies=new Enemy*[10];


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

	this->player->setModel(this->SceneResources->models[6]);

	this->Enemies[0]->setModel(this->SceneResources->models[9]);
	this->Enemies[1]->setModel(this->SceneResources->models[10]);

}

Player* Scene::getPlayer(){
	return player;
}


void Scene::setPlayer(Player* player) {
	this->player = player;
}
