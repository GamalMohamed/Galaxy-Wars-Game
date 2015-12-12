#ifndef ENTITY_H_
#define ENTITY_H_

#include"../Game loaders/model.h"


//BASE class for all objects in game
class Entity
{
protected:
	glm::vec3 position;
	Model* model;
	bool Active;
	float velocity;
	//hitbox property ?!

public:
	Entity();
	virtual ~Entity();

	virtual void Attack()=0;

	bool IsActive() const;


	void setActive(bool);


	Model*& getModel();


	void setModel(Model*& );


	const glm::vec3& getPosition() const;


	void setPosition(const glm::vec3&);


	float getVelocity() const;


	void setVelocity(float);


};

#endif /* ENTITY_H_ */
