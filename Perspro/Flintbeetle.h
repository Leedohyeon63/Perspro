#pragma once
#include "Monster.h"
#include "Inventory.h"

class Flintbeetle : public Monster
{
public:
    virtual void UseSkill(Actor* InTarget, Inventory* PInventory) override;
    void  FlintAttack(Actor* InTarget, Inventory* PInventory);
    Flintbeetle()
        :Monster("ºÎ½ËµüÁ¤¹ú·¹", 120, 16, 3)
    {
    }
private:
    int flintDamge = 25;
};
