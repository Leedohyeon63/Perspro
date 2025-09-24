#include "Monster.h"

Monster::Monster(const char* InName, int HP, int Dam,int Level)
	:Actor(InName, HP, Dam, Level)
{

}


void Monster::Attack()
{

}

void Monster::DamgeTaken(int Dam)
{
	SetDamgetaken(Dam);
}

void Monster::ShowInfo() const
{
    printf("===== 몬스터 정보 =====\n");
    Actor::ShowInfo();
    printf("=====================\n");
}