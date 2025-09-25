#include "StageMap.h"
#include<iostream>

bool StageMap::Iswall(int Mapnum, int x, int y, Way whatWay)
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

bool StageMap::IsShop(int Mapnum, int x, int y)
{
	int (*Stage)[30] = nullptr;
	Stage = Whereis(Mapnum);
	if (Stage[y][x] == static_cast<int>(Composition::Shop))
	{
		return true;
	}
	return false;
}

bool StageMap::IsPotal(int Mapnum, int x, int y)
{
	int (*Stage)[30] = nullptr;
	Stage = Whereis(Mapnum);
	if (Stage[y][x]==static_cast<int>(Composition::Potal))
	{
		return true;
	}
	return false;
}

bool StageMap::IsBoss(int Mapnum, int x, int y)
{
	int (*Stage)[30] = nullptr;
	Stage = Whereis(Mapnum);
	if (Stage[y][x] == static_cast<int>(Composition::Boss))
	{
		return true;
	}
	return false;
}

bool StageMap::IsHidden(int Mapnum, int x, int y)
{
	int (*Stage)[30] = nullptr;
	Stage = Whereis(Mapnum);
	if (Stage[y][x] == static_cast<int>(Composition::HiddenPotal))
	{
		return true;
	}
	return false;
}

int(*StageMap::Whereis(int Mapnum))[30]
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
	default:
		break;
	}
	return nullptr;
}


void StageMap::printMap(int Mapnum, int Playerx, int Playery)
{
	int (*Stage)[30] = nullptr;
	Stage = Whereis(Mapnum);


	for (size_t i = 0; i < 10; i++)
	{
		for (size_t k = 0; k < 30; k++)
		{
			Composition t = static_cast<Composition>(Stage[i][k]);
			if (Playerx==k && Playery==i)
			{
				printf("P ");
			}
			else if (t == Composition::Ground)
			{
				printf(". ");
			}
			else if (t == Composition::Wall)
			{
				printf("# ");
			}
			else if(t == Composition::Potal)
			{
				printf("T ");
			}
			else if (t == Composition::Boss)
			{
				printf("B ");
			}
		}
		printf("\n");
	}
}
