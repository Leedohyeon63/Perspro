#pragma once
#include "Actor.h"
#include "Mosterlist.h"
#include <random> 
//몬스터를 스폰시키는 클래스
class CreateMonster
{
public:
    static Actor* SpawnMonster(int stage);
    static Actor* SpawnBoss(int stage);
};