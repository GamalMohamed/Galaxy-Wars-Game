/*
 * Enemy.cpp
 *
 *  Created on: Dec 10, 2015
 *      Author: jimmy
 */

#include "Enemy.h"

Enemy::Enemy()
{

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

