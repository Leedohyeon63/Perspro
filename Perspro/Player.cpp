#include "Player.h"
//플레이어의 행동과 상태를 관리하는 클래스
void Player::move(string move, int stage)//이동을 담당하는 메소드
{
	if ((move == "d" || move == "D")&&stagemap.Iswall(stage, PlayerPosx, PlayerPosy, Way::Right))//플레이어 좌표와 이동 방향을 받아 앞이 벽인지 판단
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



//플레이어의 상태(스탯)를 관리하는 메소드
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
