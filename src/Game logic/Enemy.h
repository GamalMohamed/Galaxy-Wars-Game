#ifndef ENEMY_H_
#define ENEMY_H_

#include "Entity.h"

class Enemy: public Entity
{
	int HarmPower;
	string type;


public:
	Enemy(string);
	~Enemy();

	void Attack();

	int getHarmPower() const;
	void setHarmPower(int harmPower);

	const string& getType() const;
	void setType(const string& type);



};

#endif /* ENEMY_H_ */
