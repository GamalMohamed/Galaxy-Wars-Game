#include "Entity.h"

Entity::Entity()
{
	this->velocity=10.0f;
}

Entity::~Entity()
{

}

bool Entity::IsActive() const
{
		return Active;
}

void Entity::setActive(bool active)
{
	Active = active;
}

Model*& Entity::getModel()
{
	return model;
}

void Entity::setModel(Model*& model)
{
	this->model = model;
}

const glm::vec3& Entity::getPosition() const
{
	return position;
}

void Entity::setPosition(const glm::vec3& position)
{
	this->position = position;
}

float Entity::getVelocity() const
{
	return velocity;
}

void Entity::setVelocity(float velocity)
{
	this->velocity = velocity;
}
