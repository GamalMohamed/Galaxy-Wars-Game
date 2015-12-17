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
	float HorizontalMotion; //X-axis displacement
	float VerticalMotion;	//Z-axis displacement
	float InitialPosition; //Initial Z-coordinate of model


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


	float& getHorizontalMotion();
	void setHorizontalMotion(float horizontalMotion);

	float& getVerticalMotion();
	void setVerticalMotion(float verticalMotion);

	float& getInitialPosition();
	void setInitialPosition(float initialPosition);

};

#endif /* ENTITY_H_ */
