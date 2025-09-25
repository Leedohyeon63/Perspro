#include "Actor.h"
void Actor::AppleyDamge(Battle* InTarget)
{
	int AttackPower = GetATK();
	InTarget->Takedamge(AttackPower);
}
void Actor::Takedamge(int InDamge)
{
	SetHealth(GetHP() - InDamge);

	printf("%s이(가) %d의 피해를 입었습니다.\n", Name.c_str(), InDamge);
	printf("남은 체력(%d/%d)\n", GetHP(), MaxHealth);
	printf("==============================\n");

	if (!IsAlive())
	{
		printf("%s이(가) 죽었습니다.\n", Name.c_str());
	}
}
void Actor::UseSkill(Actor* InTarget, Inventory* PInventory)
{
	printf("몬스터가 스킬을 사용합니다\n");
}

void Actor::UsePattern(Actor* InTarget, Inventory* PInventory, int InPattern)
{
	printf("보스가 공격합니다.\n");
}

void Actor::ShowInfo() const
{
	printf("이름 : %s\n", Name.c_str());
	printf("체력 : %d / %d\n", ActorHP, MaxHealth);
	printf("공격력 : %d\n", Actordamge);
	printf("레벨 : %d\n", MonsterLevel);
}

void Actor::ActorEffects()
{
	if (CantHeal)
	{
		HealBlockedTurns--;
		printf("회복 불가 효과: %d턴 남음\n", HealBlockedTurns);

		if (HealBlockedTurns <= 0)
		{
			printf(">> 회복 불가 상태가 해제되었습니다\n");
			CantHeal = false;
		}
	}
}

bool Actor::IsHealBlocked() const
{
	return CantHeal;
}

void Actor::ActorHealBlock(int turns)
{
	printf("회복 불가 상태가 되었습니다 (%d턴 지속)\n", turns);
	CantHeal = true;
	HealBlockedTurns = turns;
}

Actor::Actor(const char* InName, int HP, int Dam, int Level)
	:Name(InName), ActorHP(HP), Actordamge(Dam), MaxHealth(HP), MonsterLevel(Level)
{

}
Actor::~Actor() {

}