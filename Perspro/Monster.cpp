#include "Monster.h"
//���� �� ���͵��� �����ϴ� Ŭ����
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

void Monster::ShowInfo() const//���� ���� ���
{
    printf("===== ���� ���� =====\n");
    Actor::ShowInfo();
    printf("=====================\n");
}