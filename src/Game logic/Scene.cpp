#include "Scene.h"

Scene::Scene()
{
	this->player=new Player();



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

}

Player* Scene::getPlayer(){
	return player;
}

void Scene::setPlayer(Player* player) {
	this->player = player;
}
