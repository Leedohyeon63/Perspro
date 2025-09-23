#pragma once
#include "Shop.h"
#include "header.h"
#include "Player.h"
#include<vector>

class Inventory : public Shop
{
public:
	void PrintInventory();
	void UseItem(string Choise);
	void WhatUse();
protected:
	Player player;
	int Maxinven = 10;
	std::vector<string> InventoryList = {"埔带飘", "措给"};
	std::vector<string> ConsumablesList = { "坷宏", "何剿标"};

};

