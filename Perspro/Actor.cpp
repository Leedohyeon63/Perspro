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
	if (Poisoned)
	{
		printf("�� �������� �Ծ���\n");
		Takedamge(PoisonDamagePerTurn);
		PoisonTurns--;
		if (PoisonTurns <= 0) {
			printf(">> %s�� ���� �����Ǿ����ϴ�.\n", Name.c_str());
			Poisoned = false;
		}
	}

	if (DamageBuffed)
	{
		DamageBuffTurns--;
		if (DamageBuffTurns <= 0) {
			printf("�� ���ݷ� ���� ȿ���� ��������ϴ�.\n");
			Actordamge -= DamageBuffAmount;
			DamageBuffed = false;
		}
	}

	if (Regenerating)
	{
		printf("ü���� ����մϴ�.\n");
		SetHealing(HealthRegenAmount); 
		HealthRegenTurns--;
		if (HealthRegenTurns <= 0) {
			printf("ü�� ��� ����.\n");
			Regenerating = false;
		}
	}
}

bool Actor::IsHealBlocked() const
{
	return CantHeal;
}

void Actor::ActorHealBlock(int turns)
{
	printf("ȸ�� �Ұ� ���°� �Ǿ����ϴ�.. (%d�� ����)\n", turns);
	CantHeal = true;
	HealBlockedTurns = turns;
}

void Actor::ActorPoison(int turns, int DamagePerTurn)
{
	printf("���� �ߵ��Ǿ����ϴ�.. (%d�� ����)\n", turns);
	Poisoned = true;
	PoisonTurns = turns;
	PoisonDamagePerTurn = DamagePerTurn;
}

void Actor::ActorDamgeBuff(int turns, int BuffAmount)
{
	printf(">> %s (��)�� ���ݷ��� �����մϴ�! (%d�� ����)\n", Name.c_str(), turns);
	if (DamageBuffed) {
		Actordamge -= DamageBuffAmount;
	}
	DamageBuffed = true;
	DamageBuffTurns = turns;
	DamageBuffAmount = BuffAmount;
	Actordamge += DamageBuffAmount; 
}

void Actor::ActorHealthRegen(int turns, int RegenPerTurn)
{
	printf("ü���� ����մϴ�.. (%d�� ����)\n",turns);
	Regenerating = true;
	HealthRegenTurns = turns;
	HealthRegenAmount = RegenPerTurn;
}

Actor::Actor(const char* InName, int HP, int Dam, int Level)
	:Name(InName), ActorHP(HP), Actordamge(Dam), MaxHealth(HP), MonsterLevel(Level)
{

}
Actor::~Actor() {

}