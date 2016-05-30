#include "Enemy.h"



Enemy::Enemy(string type)
{
	this->type=type;
	if(this->type=="Asteroid")
	{
		this->HorizontalMotion = -10+(rand() % 20);
		this->velocity=0.05f;
	}
	else if(this->type=="UFO")
	{
		this->HorizontalMotion = -55+(rand() % 110);
		this->velocity= 0.05f;
	}
	this->VerticalMotion=0.f;
	//this->HorizontalMotion = 0.f;
}


void Enemy::Attack()
{

}


int Enemy::getHarmPower() const
{
	return HarmPower;
}

void Enemy::setHarmPower(int harmPower)
{
	HarmPower = harmPower;
}

const string& Enemy::getType() const
{
	return type;
}

void Enemy::setType(const string& type)
{
	this->type = type;
}

Enemy::~Enemy()
{

}

