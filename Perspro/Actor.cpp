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
Actor::Actor(const char* InName, int HP, int Dam)
	:Name(InName), ActorHP(HP), Actordamge(Dam), MaxHealth(HP)
{

}
Actor::~Actor() {

}