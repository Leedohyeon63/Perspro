#include "PilgrimHulk.h"
void PilgrimHulk::UseSkill(Actor* InTarget, Inventory* PInventory)
{
	Rolling(InTarget, PInventory);
}

void PilgrimHulk::Rolling(Actor* InTarget, Inventory* PInventory)
{
	printf("������ ��ġ�� �����ϴ�.\n");
	printf("===============================.\n");
	if (PInventory->FindItem("���� ����"))
	{
		printf("���� �ӵ��� ���߽��ϴ�..\n");
		RollingHit = 1;
	}
	for (int i = 0; i < RollingHit; i++)
	{
		InTarget->Takedamge(RollingDamge);
	}
}