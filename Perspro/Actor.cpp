#include "Actor.h"
void Actor::AppleyDamge(Battle* InTarget)
{
	int AttackPower = GetATK();
	InTarget->Takedamge(AttackPower);
}
void Actor::Takedamge(int InDamge)
{
	SetHealth(GetHP() - InDamge);

	printf("%s��(��) %d�� ���ظ� �Ծ����ϴ�.\n", Name.c_str(), InDamge);
	printf("���� ü��(%d/%d)\n", GetHP(), MaxHealth);
	printf("==============================\n");

	if (!IsAlive())
	{
		printf("%s��(��) �׾����ϴ�.\n", Name.c_str());
	}
}
void Actor::UseSkill(Actor* InTarget, Inventory* PInventory)
{
	printf("���Ͱ� ��ų�� ����մϴ�\n");
}

void Actor::UsePattern(Actor* InTarget, Inventory* PInventory, int InPattern)
{
	printf("������ �����մϴ�.\n");
}

void Actor::ShowInfo() const
{
	printf("�̸� : %s\n", Name.c_str());
	printf("ü�� : %d / %d\n", ActorHP, MaxHealth);
	printf("���ݷ� : %d\n", Actordamge);
	printf("���� : %d\n", MonsterLevel);
}

void Actor::ActorEffects()
{
	if (CantHeal)
	{
		HealBlockedTurns--;
		printf("ȸ�� �Ұ� ȿ��: %d�� ����\n", HealBlockedTurns);

		if (HealBlockedTurns <= 0)
		{
			printf(">> ȸ�� �Ұ� ���°� �����Ǿ����ϴ�\n");
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
	printf("ȸ�� �Ұ� ���°� �Ǿ����ϴ� (%d�� ����)\n", turns);
	CantHeal = true;
	HealBlockedTurns = turns;
}

Actor::Actor(const char* InName, int HP, int Dam, int Level)
	:Name(InName), ActorHP(HP), Actordamge(Dam), MaxHealth(HP), MonsterLevel(Level)
{

}
Actor::~Actor() {

}