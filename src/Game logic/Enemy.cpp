#include "Enemy.h"



Enemy::Enemy(string type)
{
	this->type=type;
	if(this->type=="Asteroid")
	{
		this->HorizontalMotion = -10+(rand() % 20);
		this->VerticalMotion= -20.0f ;
		this->velocity=-19.8f; //AsteroidSpeed=CamSpeed*100.f
	}
	else if(this->type=="UFO")
	{
		this->HorizontalMotion = -55+(rand() % 110);
		this->VerticalMotion= 150.0f;
		this->velocity= 99.0f; //UFOSpeed=CamSpeed*500.f
	}

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

