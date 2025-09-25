#include "PilgrimHulk.h"
void PilgrimHulk::UseSkill(Actor* InTarget, Inventory* PInventory)
{
	Rolling(InTarget, PInventory);
}

void PilgrimHulk::Rolling(Actor* InTarget, Inventory* PInventory)
{
	printf("순례자 덩치가 구릅니다.\n");
	printf("===============================.\n");
	if (PInventory->FindItem("페이 깃털"))
	{
		printf("빠른 속도로 피했습니다..\n");
		RollingHit = 1;
	}
	for (int i = 0; i < RollingHit; i++)
	{
		InTarget->Takedamge(RollingDamge);
	}
}