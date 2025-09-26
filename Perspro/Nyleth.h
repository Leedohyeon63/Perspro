#pragma once
#include "Monster.h"
#include "Inventory.h"
class Nyleth : public Monster
{
public:
    virtual void UsePattern(Actor* InTarget, Inventory* PInventory, int InPattern) override;//보스 패턴 오버라이드
    void BladeSurge(Actor* InTarget, Inventory* PInventory);//보스가 사용할 스킬
    void ThrowSeed(Actor* InTarget, Inventory* PInventory);
    void Bloom(Actor* InTarget, Inventory* PInventory);
    Nyleth()
        :Monster("나이레스", 300, 6, 4)
    {
    }
private://보스 스킬의 데미지와 히트수
    int BladeDamge = 7;
    int BladeHit = 2;
    const int SeedDamge = 4;
    int SeedHit = 5;
    const int BloomDamge = 20;
    const int BloomPoison = 5;
    const int BloomPoisonHit = 2; 
};
