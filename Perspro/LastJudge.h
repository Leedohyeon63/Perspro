#pragma once
#include "Monster.h"
#include "Inventory.h"

class LastJudge : public Monster
{
public:
    LastJudge()
        :Monster("마지막 심판", 230, 23, 4)
    {
    }
    void UseSkill(Actor* InTarget, Inventory* PInventory);
    void FireWork(Actor* InTarget, Inventory* PInventory);
private:
    int FireDamge = 30;
    int FireHit = 4;
};

