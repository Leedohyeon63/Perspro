#pragma once
#include "Monster.h"
#include "Inventory.h"

class PilgrimHulk : public Monster
{
public:
    void UseSkill(Actor* InTarget, Inventory* PInventory);
    void Rolling(Actor* InTarget, Inventory* PInventory);
    PilgrimHulk()
        :Monster("¼ø·ÊÀÚ µ¢Ä¡", 130, 17, 4)
    {
    }

private:
    const int RollingDamge = 16;
    int RollingHit = 3;
};
