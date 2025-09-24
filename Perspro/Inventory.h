#pragma once
#include "Shop.h"
#include "header.h"
#include "Player.h"

#include<vector>

class Inventory
{
public:
	void PrintInventory();
	void UseItem(string Choise, Player& player);
	void PushItem(string item);
	void DeleteItem(string item);
	void PushConsumablesItem(string item);
	void DeleteConsumablesItem(string item);
	void WhatUse(Player& player);
protected:
	int Maxinven = 10;
	std::vector<string> InventoryList = {"�Ҵ�Ʈ", "���"};
	std::vector<string> ConsumablesList = {"�ν˱�"};

};

