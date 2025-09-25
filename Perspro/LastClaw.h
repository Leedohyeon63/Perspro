#pragma once
#include "Monster.h"

class LastClaw : public Monster
{
public:
    virtual void UseSkill(Actor* InTarget, Inventory* PInventory) override;
    void Scratching(Actor* InTarget, Inventory* PInventory) const;
    LastClaw()
        :Monster("마지박 발톱", 200, 15, 4)
    {
    }
private:
    const int ScratchDamge = 10;

};
