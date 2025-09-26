#include "StageMap.h"
#include<iostream>
//플레이할 맵을 관리하는 클래스
bool StageMap::Iswall(int Mapnum, int x, int y, Way whatWay)//벽인지 확인하는 메소드
{
	int (*Stage)[30] = nullptr;
	Stage = Whereis(Mapnum);
	switch (whatWay)
	{
	case Way::Up:
		if (Stage[y-1][x] == 1)
		{
			return false;
		}
		else
		{
			return true;
		}
	case Way::Down:
		if (Stage[y+1][x] == 1)
		{
			return false;
		}
		else
		{
			return true;
		}
	case Way::Left:
		if (Stage[y][x-1] == 1)
		{
			return false;
		}
		else
		{
			return true;
		}
	case Way::Right:
		if (Stage[y][x+1] == 1)
		{
			return false;
		}
		else
		{
			return true;
		}
	default:
		return true;
	}
}

bool StageMap::IsShop(int Mapnum, int x, int y)//상점인지 확인하는 메소드
{
	int (*Stage)[30] = nullptr;
	Stage = Whereis(Mapnum);
	if (Stage[y][x] == static_cast<int>(Composition::Shop))
	{
		return true;
	}
	return false;
}

bool StageMap::IsPotal(int Mapnum, int x, int y)//포탈인지 확인하는 메소드
{
	int (*Stage)[30] = nullptr;
	Stage = Whereis(Mapnum);
	if (Stage[y][x]==static_cast<int>(Composition::Potal))
	{
		return true;
	}
	return false;
}

bool StageMap::IsBoss(int Mapnum, int x, int y)//보스인지 확인하는 메소드
{
	int (*Stage)[30] = nullptr;
	Stage = Whereis(Mapnum);
	if (Stage[y][x] == static_cast<int>(Composition::Boss))
	{
		return true;
	}
	return false;
}

bool StageMap::IsAlter(int Mapnum, int x, int y,Inventory &inven)//엔딩전용
{
	int (*Stage)[30] = nullptr;
	Stage = Whereis(Mapnum);
	if (Stage[y][x] == static_cast<int>(Composition::Alter))
	{
		return true;
	}
	return false;
}
int(*StageMap::Whereis(int Mapnum))[30]//플레이어가 몇 스테이지에 있나 검사하고 리턴하는 메소드
{
	switch (Mapnum)
	{
	case 1:
		return Stage1;
	case 2:
		return Stage2;
	case 3:
		return Stage3; 
	case 4:
		return Stage4;
	case 5:
		return Stage5;
	case 6:
		return Stage6;
	default:
		break;
	}
	return nullptr;
}


void StageMap::printMap(int Mapnum, int Playerx, int Playery)//맵 출력
{
	int (*Stage)[30] = nullptr;
	Stage = Whereis(Mapnum);


	for (size_t i = 0; i < 15; i++)
	{
		for (size_t k = 0; k < 30; k++)
		{
			Composition t = static_cast<Composition>(Stage[i][k]);
			if (Playerx==k && Playery==i)
			{
				printf("P ");
			}
			else if (t == Composition::Ground)//땅
			{
				printf(". ");
			}
			else if (t == Composition::Wall)//벽
			{
				printf("# ");
			}
			else if(t == Composition::Potal)//포탈
			{
				printf("T ");
			}
			else if (t == Composition::Boss)//보스
			{
				printf("B ");
			}
			else if (t == Composition::Void)//빈공간
			{
				printf("  ");
			}
			else if (t == Composition::Shop)//상점
			{
				printf("S ");
			}
			else if (t == Composition::Alter)//상점
			{
				printf("ㅁ ");
			}
			else if (t == Composition::Water)//상점
			{
				printf("~ ");
			}
		}
		printf("\n");
	}
}
