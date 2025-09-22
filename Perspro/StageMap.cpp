#include "StageMap.h"
#include<iostream>

bool StageMap::Iswall(int Mapnum, int x, int y, Way whatWay)
{
	int (*Stage)[30] = nullptr;
	if (Mapnum == 1) { Stage = Stage1; }
	else if (Mapnum == 2) { Stage = Stage2; }
	else if (Mapnum == 3) { Stage = Stage3; }
	else if (Mapnum == 4) { Stage = Stage4; }
	else { return true; }

	switch (whatWay)
	{
	case Way::Up:
		if (Stage[x][y+1] == 1)
		{
			return false;
			break;
		}
		else
		{
			return true;
			break;
		}
	case Way::Down:
		if (Stage[x][y - 1] == 1)
		{
			return false;
			break;
		}
		else
		{
			return true;
			break;
		}
	case Way::Left:
		if (Stage[x][y - 1] == 1)
		{
			return false;
			break;
		}
		else
		{
			return true;
			break;
		}
	case Way::Right:
		if (Stage[x][y + 1] == 1)
		{
			return false;
			break;
		}
		else
		{
			return true;
			break;
		}
	default:
		return true;
		break;
	}
}

void StageMap::printMap(int Mapnum, int Playerx, int Playery)
{
	int (*Stage)[30] = nullptr;
	if (Mapnum == 1) { Stage = Stage1; }
	else if (Mapnum == 2) { Stage = Stage2; }
	else if (Mapnum == 3) { Stage = Stage3; }
	else if (Mapnum == 4) { Stage = Stage4; }
	else { return; }

	for (size_t i = 0; i < 10; i++)
	{
		for (size_t k = 0; k < 30; k++)
		{
			Composition t = static_cast<Composition>(Stage[i][k]);
			if (Playerx==k && Playery==i)
			{
				printf("P");
			}
			else if (t == Composition::Ground)
			{
				printf(".");
			}
			else if (t == Composition::Wall)
			{
				printf("#");
			}
			else if(t == Composition::Potal)
			{
				printf("T");
			}
		}
		printf("\n");
	}
}
