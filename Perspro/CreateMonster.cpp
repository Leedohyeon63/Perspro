#include "CreateMonster.h"
#include "Mosterlist.h"
#include <random> 
Actor* CreateMonster::SpawnMonster(int stage)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, 4);
    int monsterType = distrib(gen);
    if (stage == 1)
    {
        if (monsterType == 0)
        {
            return new MassiveMossgrub();
        }
        else if(monsterType == 1)
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
        else if (monsterType == 1)
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
            return new ElderPilgrim();
        }
        else
        {
            return new PilgrimHulk();
        }
    }
    return new Mossgrub();
}