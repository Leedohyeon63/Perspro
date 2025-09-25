#pragma once
#include "Monster.h"
#include "Inventory.h"
class ElderPilgrim : public Monster
{
public:
    ElderPilgrim()
        :Monster("��� ������", 170, 20, 4)
    {
    }
    void UseSkill(Actor* InTarget, Inventory* PInventory);
    void ElderBreath(Actor* InTarget, Inventory* PInventory);
private:
    int BreathDamge = 30;
};
