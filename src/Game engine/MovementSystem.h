#ifndef MOVEMENTSYSTEM_H_
#define MOVEMENTSYSTEM_H_

#include"GameManager.h"
class Scene;

class MovementSystem
{

public:
	MovementSystem();
	~MovementSystem();

	void ModelTransformations(Scene*);

	void PlayerTransformations(Scene*);
	void MovePlayer(float&,float&);

};

#endif /* MOVEMENTSYSTEM_H_ */
