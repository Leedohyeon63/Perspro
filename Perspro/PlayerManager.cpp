#include "PlayerManager.h"

void PlayerManager::move(string move, int stage)
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


void PlayerManager::PlayerDmagetaken(int Dam)
{
	SetDamgetaken(Dam);
}

void PlayerManager::PlayerHealing(int Heal)
{
	SetHealing(Heal);
}
void PlayerManager::PlayerGetMoney(int gold)
{
	SetGold(gold);
}
PlayerManager::PlayerManager(const char* InName, int HP, int Dam)
	:Actor(InName, HP, Dam)
{
}
PlayerManager::~PlayerManager()
{
}
