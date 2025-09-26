#pragma once
#include"Monster.h"
#include"Inventory.h"
class TheUnravelled : public Monster
{
public:
    virtual void UsePattern(Actor* InTarget, Inventory* PInventory, int InPattern) override;
    virtual void Takedamge(int InDamge) override;
    void UnravelledRush(Actor* InTarget, Inventory* PInventory);
    void SpearThrow(Actor* InTarget, Inventory* PInventory);
    void Judge(Actor* InTarget, Inventory* PInventory);
    void Voltvessels(Actor* InTarget, Inventory* PInventory);
    void RosaryShoot(Actor* InTarget, Inventory* PInventory);
    void LightBeam(Actor* InTarget, Inventory* PInventory);
    void Purgatorium(Actor* InTarget, Inventory* PInventory);
    TheUnravelled()
        :Monster("풀려난 자", 2200, 30, 11)
    {
    }
    virtual ~TheUnravelled() noexcept override = default;
private:
    int UnravelledRushDamge = 40;
    int SpearThrowDamge = 70;
    int JudgeDamge = 120;
    int VoltvesselsDamge = 50;
    int VoltvesselsHit = 3;
    int RosaryShootDamge = 20;
    int LightBeamDamge = 150;
    int MaxCount = 10;
    int LightBeamcount = MaxCount;
    int PurgatoriumDamge = 200;
    bool IsBerserk() { return GetHP() < 1000; }
    bool IsDamTaken = false;
    bool IsRage = true;
};

