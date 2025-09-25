#pragma once
#include "Monster.h"
#include "Inventory.h"
class GroaltheGreat : public Monster
{
public:
    virtual void UsePattern(Actor* InTarget, Inventory* PInventory, int InPattern) override;
    void Rush(Actor* InTarget, Inventory* PInventory);
    void Inhale(Actor* InTarget, Inventory* PInventory);
    void MaggotsTale(Actor* InTarget, Inventory* PInventory);
    void SoulThrow(Actor* InTarget, Inventory* PInventory);
    GroaltheGreat()
        :Monster("위대한 그롤", 1000, 12, 6)
    {
    }
private:
    int RushDamge = 40;
    int InhaleDamge = 20;
    int InhaleHit = 3;
    int MaggotsTaleDamge = 10;
    int Maggotstime = 7;
    int SoulThrowDamge = 15;
    int SoulThrowHit = 2;
    bool IsBerserk() { return GetHP() < 600; }
    bool BerserkeTrigger = true;
};
