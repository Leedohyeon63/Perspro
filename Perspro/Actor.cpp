#include "Actor.h"
void Actor::AppleyDamge(Battle* InTarget)
{
	int AttackPower = GetATK();
	InTarget->Takedamge(AttackPower);
}
void Actor::Takedamge(int InDamge)
{
	SetHealth(GetHP() - InDamge);

	printf("%s가 %d의 피해를 입었습니다.\n", Name.c_str(), InDamge);
	printf("(%d/%d)\n", GetHP(), MaxHealth);

	if (!IsAlive())
	{
		printf("%s가 죽었습니다.\n", Name.c_str());
	}
}
void Actor::Useskill(Actor* InTarget)
{
	printf("몬스터가 스킬을 사용합니다\n");
}

void Actor::ShowInfo() const
{
	printf("이름 : %s\n", Name.c_str());
	printf("체력 : %d / %d\n", ActorHP, MaxHealth);
	printf("공격력 : %d\n", Actordamge);
	printf("레벨 : %d\n", MonsterLevel);
}


Actor::Actor(const char* InName, int HP, int Dam, int Level)
	:Name(InName), ActorHP(HP), Actordamge(Dam), MaxHealth(HP), MonsterLevel(Level)
{

}
Actor::~Actor() {

}