#ifndef MOVEMENTSYSTEM_H_
#define MOVEMENTSYSTEM_H_

#include"GameManager.h"
class Scene;

class MovementSystem
{
private:
	void PlayerTransformations(Scene*);
	void MovePlayer(float&,float&);
	void EnemiesTransformations(Scene*);

public:
	MovementSystem();
	~MovementSystem();

	void ModelTransformations(Scene*);



};

#endif /* MOVEMENTSYSTEM_H_ */
