#include "Player.h"

Player::Player()
{
	this->Active=true;
	this->lifepoints=1000;
	this->score=0;

	this->HorizontalMotion=0.f;
	this->VerticalMotion=0.f;

	this->InitialYPosition= -0.5f;
	this->velocity=0.32f; //WrathSpeed=CamSpeed*100.f


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


