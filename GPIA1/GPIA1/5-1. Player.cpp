#include "5-1. Player.h"

void Player::Attack()
{
	cout << "Attack" << endl;
}

void Player::Die()
{
	cout << "Die" << endl;
}

void Player::HealMe(int value)
{
	hp += value;
}