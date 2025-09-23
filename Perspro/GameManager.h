#pragma once
#include "Player.h"
#include "Inventory.h"
class GameManager : public Player
{
public:
	void TextRpg();
	void Nextstage();
	void WhereStege();
	GameManager()=default;
	~GameManager();
private:
	int StageTrigger = 1;
	const int MAxstage = 5;
	string move;
	Player player = Player("플레이어", 100, 20);
	Inventory inven;
};


