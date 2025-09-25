#include "LastJudge.h"
void LastJudge::UseSkill(Actor* InTarget, Inventory* PInventory)
{
	FireWork(InTarget, PInventory);
}

void LastJudge::FireWork(Actor* InTarget, Inventory* PInventory)
{
	printf("몬스터가 불을 계속 뿜어냅니다.\n");
	if (PInventory->FindItem("용암 종"))
	{
		printf("용암 종이 피해를 감소시킵니다.\n");
		FireDamge = 10;
	}
	if (PInventory->FindItem("페이 깃털"))
	{
		printf("빠른 속도로 피했습니다..\n");
		FireHit = 2;
	}
	for (int i = 0; i < FireHit; i++)
	{
		InTarget->Takedamge(FireDamge);
	}
}