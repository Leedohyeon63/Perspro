#include "CreateMonster.h"
//스테이지와 가중치에 따라 몬스터를 생성하는 클래스
Actor* CreateMonster::SpawnMonster(int stage)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, 6);//0부터 5까지 랜덤
    int monsterType = distrib(gen);
    if (stage == 1)
    {
        if (monsterType == 0)//모든 스테이지에서 엘리트 몬스터는 0일때만
        {
            return new MassiveMossgrub();
        }
        else if(monsterType == 1|| monsterType==3)//중간 파워 몬스터는 1일때만 or 1이나 3일때만
        {
            return new Mossmir();
        }
        else//나머지는 기본 몬스터
        {
            return new Mossgrub();
        }
    }
    else if (stage == 2)//이하 동문
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
{//스테이지별 보스 생성하는 메소드
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
