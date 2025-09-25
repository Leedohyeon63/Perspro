#include "ElderPilgrim.h"
void ElderPilgrim::UseSkill(Actor* InTarget, Inventory* PInventory)
{
	ElderBreath(InTarget, PInventory);
}

void ElderPilgrim::ElderBreath(Actor* InTarget, Inventory* PInventory)
{
	printf("순례자가 브레스를 발사합니다..\n");
	if (InTarget->GetHP()<80)
	{
		printf("브레스가 이상합니다..\n");
		BreathDamge = 1000;
	}
	InTarget->Takedamge(BreathDamge);

}
