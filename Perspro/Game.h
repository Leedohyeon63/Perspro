#pragma once
#include "PlayerManager.h"
#include "Inventory.h"
class Game : public PlayerManager, public Inventory
{
public:
	void TextRpg();
	void Nextstage();
	void WhereStege();
	Game()=default;
	~Game();
private:
	int StageTrigger = 1;
	const int MAxstage = 5;
	string move;
	PlayerManager player = PlayerManager("플레이어", 100, 20);
	Inventory inven;
};


