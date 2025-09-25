#pragma once
#include "Monster.h"
#include "Inventory.h"
class Trobbio : public Monster
{
public:
    virtual void UsePattern(Actor* InTarget, Inventory* PInventory, int InPattern) override;
    void Firebomb(Actor* InTarget, Inventory* PInventory);
    void Tornado(Actor* InTarget, Inventory* PInventory);
    void FireWork(Actor* InTarget, Inventory* PInventory);
    void FirecrackerAttack(Actor* InTarget, Inventory* PInventory);
    Trobbio()
        :Monster("토르비오", 600, 12, 7)
    {
    }
private:
    int bombDamge = 25;
    int TornadoDamge = 10;
    int TornadoHit = 5;
    int FireWorkDamge = 30;
    int FirecrackerCount = 0;
    int FirecrackerDamge = 70;
};
