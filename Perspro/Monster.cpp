#include "Monster.h"
//엑터 중 몬스터들을 관리하는 클래스
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

void Monster::ShowInfo() const//몬스터 정보 출력
{
    printf("===== 몬스터 정보 =====\n");
    Actor::ShowInfo();
    printf("=====================\n");
}