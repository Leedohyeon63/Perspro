#include "Lavalug.h"

void Lavalug::UseSkill(Actor* InTarget, Inventory* PInventory)
{
	LavaAttack(InTarget, PInventory);
}

void Lavalug::LavaAttack(Actor* InTarget, Inventory* PInventory)
{
	printf("몬스터가 용암을 발사합니다.\n");
	if (PInventory->FindItem("용암 종"))
	{
		printf("용암 종이 피해를 감소시킵니다.\n");
		LavaDamge = 5;
	}
	InTarget->Takedamge(LavaDamge);
}
