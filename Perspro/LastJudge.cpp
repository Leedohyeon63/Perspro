#include "LastJudge.h"
void LastJudge::UseSkill(Actor* InTarget, Inventory* PInventory)
{
	FireWork(InTarget, PInventory);
}

void LastJudge::FireWork(Actor* InTarget, Inventory* PInventory)
{
	printf("���Ͱ� ���� ��� �վ���ϴ�.\n");
	if (PInventory->IsEquip("�������"))
	{
		printf("��� ���� ���ظ� ���ҽ�ŵ�ϴ�.\n");
		FireDamge = 10;
	}
	if (PInventory->IsEquip("���̱���"))
	{
		printf("���� �ӵ��� ���߽��ϴ�..\n");
		FireHit = 2;
	}
	for (int i = 0; i < FireHit; i++)
	{
		InTarget->Takedamge(FireDamge);
	}
}