#include "Flintbeetle.h"

void Flintbeetle::UseSkill(Actor* InTarget, Inventory* PInventory)
{
	FlintAttack(InTarget, PInventory);
}

void Flintbeetle::FlintAttack(Actor* InTarget, Inventory* PInventory)
{
	printf("몬스터 머리의 부싯돌이 빛납니다..\n");
	if (PInventory->IsEquip("용암의종"))
	{
		printf("용암 종이 피해를 감소시킵니다.\n");
		flintDamge = 10;
	}
	InTarget->Takedamge(flintDamge);
}
