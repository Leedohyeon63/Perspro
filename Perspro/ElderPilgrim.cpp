#include "ElderPilgrim.h"
void ElderPilgrim::UseSkill(Actor* InTarget, Inventory* PInventory)
{
	ElderBreath(InTarget, PInventory);
}

void ElderPilgrim::ElderBreath(Actor* InTarget, Inventory* PInventory)
{
	printf("�����ڰ� �극���� �߻��մϴ�..\n");
	if (InTarget->GetHP()<80)
	{
		printf("�극���� �̻��մϴ�..\n");
		BreathDamge = 1000;
	}
	InTarget->Takedamge(BreathDamge);

}
