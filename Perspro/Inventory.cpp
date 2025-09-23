#include "Inventory.h"
#include<iostream>

void Inventory::PrintInventory()
{
	printf("인벤토리 내역\n");
	printf("==============소모품==============\n");
	for (int i = 0; i < InventoryList.size(); i++)
	{
		cout << "(" << InventoryList[i] << ")" << " ";
	}
	printf("\n==============소지품==============\n");
	for (int i = 0; i < ConsumablesList.size(); i++)
	{
		cout << "(" << ConsumablesList[i] << ")" << " ";
	}
	printf("\n");
}


void Inventory::WhatUse()
{
	string Choise;
	printf("사용할 아이템 선택\n");
	printf("==============소모품==============\n");
	for (int i = 0; i < ConsumablesList.size(); i++)
	{
		cout << "(" << ConsumablesList[i] << ")" << " ";
	}
	printf("\n");
	cin >> Choise;
	if (find(ConsumablesList.begin(), ConsumablesList.end(), Choise) == ConsumablesList.end());
	{
		UseItem(Choise);
	}
}

void Inventory::UseItem(string Choise)
{
	if (Choise == "오브")
	{
		if (player.Getorb() > 0)
		{
			printf("%d 만큼 회복 \n", player.Getorb());
			player.PlayerHealing(player.Getorb());
			player.Sethealorb(0);
			system("pause");
		}
		else
		{
			printf("오브 없음\n");
			system("pause");

		}
	}
	else if (Choise == "부싯깃")
	{
		player.SetDamge(30);//수정필요
	}

}
