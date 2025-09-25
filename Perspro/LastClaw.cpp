#include "LastClaw.h"

void LastClaw::UseSkill(Actor* InTarget, Inventory* PInventory)
{
	Scratching(InTarget, PInventory);
}

void LastClaw::Scratching(Actor* InTarget, Inventory* PInventory) const
{
	printf("몬스터가 발톱으로 두번 공격합니다.\n");
	printf("===============================.\n");
	for (int i = 0; i < 2; i++)
	{
		InTarget->Takedamge(ScratchDamge);
	}
}

