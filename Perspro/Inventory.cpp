#include "Inventory.h"
#include<iostream>

void Inventory::PrintInventory()
{
	printf("�κ��丮 ����\n");
	printf("==============�Ҹ�ǰ==============\n");
	for (int i = 0; i < InventoryList.size(); i++)
	{
		cout << "(" << InventoryList[i] << ")" << " ";
	}
	printf("\n==============����ǰ==============\n");
	for (int i = 0; i < ConsumablesList.size(); i++)
	{
		cout << "(" << ConsumablesList[i] << ")" << " ";
	}
	printf("\n");
}


void Inventory::WhatUse()
{
	string Choise;
	printf("����� ������ ����\n");
	printf("==============�Ҹ�ǰ==============\n");
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
	if (Choise == "����")
	{
		if (player.Getorb() > 0)
		{
			printf("%d ��ŭ ȸ�� \n", player.Getorb());
			player.PlayerHealing(player.Getorb());
			player.Sethealorb(0);
			system("pause");
		}
		else
		{
			printf("���� ����\n");
			system("pause");

		}
	}
	else if (Choise == "�ν˱�")
	{
		player.SetDamge(30);//�����ʿ�
	}

}
