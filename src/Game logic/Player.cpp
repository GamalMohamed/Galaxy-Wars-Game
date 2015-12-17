#include "Player.h"

Player::Player()
{
	this->Active=true;
	this->lifepoints=1000;
	this->score=0;

	this->HorizontalMotion=0.f;
	this->VerticalMotion=850.f;

	this->InitialPosition= -200.f;
	this->velocity=20.0f; //WrathSpeed=CamSpeed*100.f


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


