#pragma once
#include "Monster.h"
#include "Inventory.h"
class Nyleth : public Monster
{
public:
    virtual void UsePattern(Actor* InTarget, Inventory* PInventory, int InPattern) override;
    void BladeSurge(Actor* InTarget, Inventory* PInventory);
    void ThrowSeed(Actor* InTarget, Inventory* PInventory);
    void Bloom(Actor* InTarget, Inventory* PInventory);
    Nyleth()
        :Monster("나이레스", 300, 6, 4)
    {
    }
private:
    int BladeDamge = 7;
    int BladeHit = 2;
    const int SeedDamge = 4;
    int SeedHit = 5;
    const int BloomDamge = 30;
};
