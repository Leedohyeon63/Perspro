#pragma once
#include "Monster.h"
#include "Inventory.h"
#include<random>
class MotherSilk : public Monster
{
public:
    virtual void UsePattern(Actor* InTarget, Inventory* PInventory, int InPattern) override;
    virtual void Takedamge(int InDamge) override;
    void Silkspear(Actor* InTarget, Inventory* PInventory);
    void ThreadStorm(Actor* InTarget, Inventory* PInventory);
    void CrossStitch(Actor* InTarget, Inventory* PInventory);
    void RuneRage(Actor* InTarget, Inventory* PInventory);
    void PaleNails(Actor* InTarget, Inventory* PInventory);
    MotherSilk()
        :Monster("위대한 어머니 실크", 1500, 10, 9)
    {
    }
private:
    int SilkspearDamge = 35;
    int ThreadStormDamge = 12;
    int ThreadStormHit = 5;
    int CrossStitchDamge = 40;
    int RuneRageDamge = 20;
    int PaleNailsDamge = 55;
    int PaleNailsCount = 3;
    int PaleNailsHit = 3;
    bool IsDamTaken = false;
    int RuneRageHit = 2;
};
