#ifndef RESOURCESSYSTEM_H_
#define RESOURCESSYSTEM_H_

#include"../Defs.h"
#include "../Game loaders/model.h"

class PhysicsSystem;

class ResourcesSystem
{
	friend class Scene;
	friend class RenderingSystem;
	friend class MovementSystem;
	Model** models;
	Shader* ModelShader;
	Shader* lightingShader;

public:
	ResourcesSystem(PhysicsSystem* physicsSystem);
	~ResourcesSystem();


};

#endif /* RESOURCESSYSTEM_H_ */
