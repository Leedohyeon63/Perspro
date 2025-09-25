#include "CreateMonster.h"

Actor* CreateMonster::SpawnMonster(int stage)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, 6);
    int monsterType = distrib(gen);
    if (stage == 1)
    {
        if (monsterType == 0)
        {
            return new MassiveMossgrub();
        }
        else if(monsterType == 1|| monsterType==3)
        {
            return new Mossmir();
        }
        else
        {
            return new Mossgrub();
        }
    }
    else if (stage == 2)
    {
        if (monsterType == 0)
        {
            return new Flintbeetle();
        }
        else if (monsterType == 1)
        {
            return new Tarmite();
        }
        else
        {
            return new Beastfly(); 
        }
    }
    else if (stage == 3)
    {
        if (monsterType == 0)
        {
            return new LastClaw();
        }
        else if (monsterType == 1 || monsterType == 3)
        {
            return new Lavalug();
        }
        else
        {
            return new Cragglite();
        }
    }
    else if (stage == 4)
    {
        if (monsterType == 0)
        {
            return new LastJudge();
        }
        else if (monsterType == 1 || monsterType == 3)
        {
            return new ElderPilgrim();
        }
        else
        {
            return new PilgrimHulk();
        }
    }
    return new Mossgrub();
}

Actor* CreateMonster::SpawnBoss(int stage)
{
    switch (stage)
    {
    case 1:
        return new Nyleth();
    case 2:
        return new Trobbio();
    case 3:
        return new GroaltheGreat();
    case 4:
        return new MotherSilk();
    case 5:
        return new TheUnravelled();
    default:
        break;
    }
    return nullptr;
}
