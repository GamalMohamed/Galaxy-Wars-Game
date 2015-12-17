#ifndef PLAYER_H_
#define PLAYER_H_

#include "Entity.h"

class Player: public Entity
{
private:
	int score;
	int lifepoints;
	string weapons[3];


public:
	Player();
	~Player();

	void Attack();

	string* getWeapons();

	int getLifepoints() const;
	void setLifepoints(int lifepoints);

	int getScore() const;
	void setScore(int score);


};

#endif /* PLAYER_H_ */
