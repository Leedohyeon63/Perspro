#pragma once
#include "Monster.h"
#include "Inventory.h"

class Lavalug : public Monster
{
public:
    void UseSkill(Actor* InTarget, Inventory* PInventory);
    void LavaAttack(Actor* InTarget, Inventory* PInventory);
    Lavalug()
        :Monster("��ϴ�����", 100, 13, 3)
    {
    }
private:
    int LavaDamge = 35;
};
