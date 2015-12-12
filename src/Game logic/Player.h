/*
 * Player.h
 *
 *  Created on: Dec 10, 2015
 *      Author: jimmy
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include "Entity.h"

class Player: public Entity
{
	int score;
	int lifepoints;
	string weapons[3];

public:
	Player();
	~Player();

	void Attack();

	int getLifepoints() const;
	void setLifepoints(int lifepoints);
	int getScore() const;
	void setScore(int score);
	string* getWeapons();
};

#endif /* PLAYER_H_ */
