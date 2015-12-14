#ifndef MOVEMENTSYSTEM_H_
#define MOVEMENTSYSTEM_H_

#include"GameManager.h"
class Scene;

class MovementSystem
{
	float HorizontalMotion; //X-axis displacement
	float VerticalMotion;	//Y-axis displacement

public:
	MovementSystem();
	~MovementSystem();

	void ModelTransformations(Scene*);

	float getVerticalMotion();
};

#endif /* MOVEMENTSYSTEM_H_ */
