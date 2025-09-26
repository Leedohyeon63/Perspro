#include "Actor.h"
void Actor::AppleyDamge(Battle* InTarget)//몬스터, 보스, 플레이어 전반을 담당하는 클래스
{
	int AttackPower = GetATK();
	InTarget->Takedamge(AttackPower);
}
void Actor::Takedamge(int InDamge)//데미지 처리를 하는 메소드
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
void Actor::UseSkill(Actor* InTarget, Inventory* PInventory)//일반 몬스터의 스킬
{
	printf("몬스터가 스킬을 사용합니다\n");
}

void Actor::UsePattern(Actor* InTarget, Inventory* PInventory, int InPattern)//보스 몬스터의 스킬(패턴)
{
	printf("보스가 공격합니다.\n");
}

void Actor::ShowInfo() const//엑터의 정보
{
	printf("이름 : %s\n", Name.c_str());
	printf("체력 : %d / %d\n", ActorHP, MaxHealth);
	printf("공격력 : %d\n", Actordamge);
	printf("레벨 : %d\n", MonsterLevel);
}

void Actor::ActorEffects()//엑터(일반적으로는 플레이어)의 상태 이상 효과 힐밴, 독, 공격력 버프, 재생 4가지 구현
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
	if (Poisoned)
	{
		printf("독 데미지를 입었다\n");
		Takedamge(PoisonDamagePerTurn);
		PoisonTurns--;
		if (PoisonTurns <= 0) {
			printf(">> %s의 독이 해제되었습니다.\n", Name.c_str());
			Poisoned = false;
		}
	}

	if (DamageBuffed)
	{
		DamageBuffTurns--;
		if (DamageBuffTurns <= 0) {
			printf("의 공격력 증가 효과가 사라졌습니다.\n");
			Actordamge -= DamageBuffAmount;
			DamageBuffed = false;
		}
	}

	if (Regenerating)
	{
		printf("체력을 재생합니다.\n");
		SetHealing(HealthRegenAmount); 
		HealthRegenTurns--;
		if (HealthRegenTurns <= 0) {
			printf("체력 재생 종료.\n");
			Regenerating = false;
		}
	}
}

bool Actor::IsHealBlocked() const//힐이 가능한 상태인지 확인하는 메소드
{
	return CantHeal;
}

void Actor::ActorHealBlock(int turns)
{//힐밴을 처리하는 메소드, 힐밴 상태면 지속시간 갱신X, 힐밴이 끝나야 다시 힐밴이 걸림
	if (!CantHeal)
	{
		printf("회복 불가 상태가 되었습니다.. (%d턴 지속)\n", turns);
		CantHeal = true;
		HealBlockedTurns = turns;
	}
}

void Actor::ActorPoison(int turns, int DamagePerTurn)
{//중독 상태를 처리하는 메소드
	printf("독에 중독되었습니다.. (%d턴 지속)\n", turns);
	Poisoned = true;
	PoisonTurns = turns;
	PoisonDamagePerTurn = DamagePerTurn;
}

void Actor::ActorDamgeBuff(int turns, int BuffAmount)
{//공격력 버프를 주는 메소드
	printf("공격력이 %d증가합니다(%d턴 지속)\n", BuffAmount, turns);
	if (DamageBuffed) {
		Actordamge -= DamageBuffAmount;
	}
	DamageBuffed = true;
	DamageBuffTurns = turns;
	DamageBuffAmount = BuffAmount;
	Actordamge += DamageBuffAmount; 
}

void Actor::ActorHealthRegen(int turns, int RegenPerTurn)
{//재생 버프를 주는 메소드
	printf("체력을 재생합니다.. (%d턴 지속)\n",turns);
	Regenerating = true;
	HealthRegenTurns = turns;
	HealthRegenAmount = RegenPerTurn;
}

Actor::Actor(const char* InName, int HP, int Dam, int Level)
//생성자, 이름, hp, 데미지, 최대체력, 레벨(플레이어는 레벨 사용X)
	:Name(InName), ActorHP(HP), Actordamge(Dam), MaxHealth(HP), MonsterLevel(Level)
{

}
Actor::~Actor() {

}