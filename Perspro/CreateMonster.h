#pragma once
#include "Actor.h"
#include "Mosterlist.h"
#include <random> 
//���͸� ������Ű�� Ŭ����
class CreateMonster
{
public:
    static Actor* SpawnMonster(int stage);
    static Actor* SpawnBoss(int stage);
};