#pragma once
#include "Actor.h"
#include "Mosterlist.h"
#include <random> 
class CreateMonster
{
public:
    static Actor* SpawnMonster(int stage);
    static Actor* SpawnBoss(int stage);
};