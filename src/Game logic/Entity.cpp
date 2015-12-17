#include "Entity.h"

Entity::Entity()
{

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


float& Entity::getHorizontalMotion(){
	return HorizontalMotion;
}

void Entity::setHorizontalMotion(float horizontalMotion) {
	HorizontalMotion = horizontalMotion;
}

float& Entity::getVerticalMotion(){
	return VerticalMotion;
}

void Entity::setVerticalMotion(float verticalMotion) {
	VerticalMotion = verticalMotion;
}

float& Entity::getInitialPosition(){
	return InitialPosition;
}

void Entity::setInitialPosition(float initialPosition) {
	InitialPosition = initialPosition;
}
