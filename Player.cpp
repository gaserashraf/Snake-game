#include "Player.h"

Player::Player()
{
	score = 0;
	lose = 0;
}

void Player::setScore(int s)
{
	score = s;
}

void Player::setLose(bool s)
{
	lose = s;
}

int Player::getScore()
{
	return score;
}

bool Player::getLose()
{
	return lose;
}
