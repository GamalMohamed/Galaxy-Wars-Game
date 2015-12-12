/*
 * Player.cpp
 *
 *  Created on: Dec 10, 2015
 *      Author: jimmy
 */

#include "Player.h"

Player::Player()
{
	this->Active=true;
	this->lifepoints=1000;
	this->score=0;
	//this->weapons={'Missile','laser','Bullet'};


}

void Player::Attack()
{

}



int Player::getLifepoints() const {
	return lifepoints;
}

void Player::setLifepoints(int lifepoints) {
	this->lifepoints = lifepoints;
}

int Player::getScore() const {
	return score;
}

void Player::setScore(int score) {
	this->score = score;
}

string* Player::getWeapons(){
	return weapons;
}

Player::~Player()
{

}


