#include "Player.h"

void Player::move(int x, int y)
{
	PlayerPosx = x;
	PlayerPosy = y;
}


void Player::PlayerDmagetaken(int Dam)
{
	SetDamgetaken(Dam);
}

void Player::Healing(int Heal)
{
	SetHealing(Heal);
}

Player::Player(const char* InName, int HP, int Dam)
	:Actor(InName, HP, Dam)
{
}

Player::~Player()
{
}
