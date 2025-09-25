#include "Player.h"

void Player::move(string move, int stage)
{
	if ((move == "d" || move == "D")&&stagemap.Iswall(stage, PlayerPosx, PlayerPosy, Way::Right))
	{
		PlayerPosx++;
	}
	else if ((move == "a" || move == "A") && stagemap.Iswall(stage, PlayerPosx, PlayerPosy, Way::Left))
	{
		PlayerPosx--;
	}
	else if ((move == "w" || move == "W") && stagemap.Iswall(stage, PlayerPosx, PlayerPosy, Way::Up))
	{
		PlayerPosy--;
	}
	else if ((move == "s" || move == "S") && stagemap.Iswall(stage, PlayerPosx, PlayerPosy, Way::Down))
	{
		PlayerPosy++;
	}
	else
	{
		return;
	}
}




void Player::PlayerDmagetaken(int Dam)
{
	SetDamgetaken(Dam);
}

void Player::PlayerHealing(int Heal)
{
	SetHealing(Heal);
}
void Player::PlayerGetMoney(int gold)
{
	SetGold(gold);
}
void Player::PlayerDmageSet(int Atk)
{
	SetDamge(Atk);
}
Player::Player(const char* InName, int HP, int Dam, int Level)
	:Actor(InName, HP, Dam, Level)
{
}
Player::~Player()
{
}
