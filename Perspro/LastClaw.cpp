#include "LastClaw.h"

void LastClaw::UseSkill(Actor* InTarget, Inventory* PInventory)
{
	Scratching(InTarget, PInventory);
}

void LastClaw::Scratching(Actor* InTarget, Inventory* PInventory) const
{
	printf("���Ͱ� �������� �ι� �����մϴ�.\n");
	printf("===============================.\n");
	for (int i = 0; i < 2; i++)
	{
		InTarget->Takedamge(ScratchDamge);
	}
}

