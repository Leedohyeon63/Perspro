#include "Inventory.h"//�κ��丮�� �κ��丮 ���� ��� �۾��� �����ϴ� Ŭ����
#include<iostream>

void Inventory::PrintInventory()//�κ��丮 ���
{
	printf("�κ��丮 ����\n");
	printf("\n==============������==============\n");
	for (int i = 0; i < EquipList.size(); i++)
	{
		cout << "(" << EquipList[i] << ")" << " ";
	}
	printf("\n==============����ǰ==============\n");
	for (int i = 0; i < InventoryList.size(); i++)
	{
		cout << "(" << InventoryList[i] << ")" << " ";
	}
	printf("\n==============�Ҹ�ǰ==============\n");
	for (int i = 0; i < ConsumablesList.size(); i++)
	{
		cout << "(" << ConsumablesList[i] << ")" << " ";
	}
	printf("\n==============��������==============\n");
	for (int i = 0; i < BattleList.size(); i++)
	{
		cout << "(" << BattleList[i] << ")" << " ";
	}
	printf("\n");
}


void Inventory::WhatUse(Player& player)//������ ����ϴ� �޼ҵ� �Ҹ�ǰ�� �������� �ΰ����� �����Ѵ�.
{
	string Choise;
	printf("����� ������ ����\n");
	printf("==============�Ҹ�ǰ==============\n");
	for (int i = 0; i < ConsumablesList.size(); i++)
	{
		cout << "(" << ConsumablesList[i] << ")" << " ";
	}
	printf("\n");
	printf("\n==============��������==============\n");
	for (int i = 0; i < BattleList.size(); i++)
	{
		cout << "(" << BattleList[i] << ")" << " ";
	}
	printf("\n");
	cin >> Choise;

	if (find(ConsumablesList.begin(), ConsumablesList.end(), Choise) != ConsumablesList.end())//�Ҹ�ǰ�� ���� ���� �迭�� ���鼭 ������ �ִ��� Ȯ��
	{
		UseItem(Choise, player);
	}
	else if (find(BattleList.begin(), BattleList.end(), Choise) != BattleList.end())
	{
		UseItem(Choise, player);
	}
	else
	{
		cout << "'" << Choise << "'��(��) ����� �� ���� �������Դϴ�." << endl;
	}
	return;
}
void Inventory::BattleUse(Player& player)//���� �����ÿ��� ���������� ��� �����ѵ� �׶� ����ϴ� �޼ҵ�
{
	string Choise;
	printf("����� ������ ����\n");
	printf("==============��������=============\n");
	for (int i = 0; i < BattleList.size(); i++)
	{
		cout << "(" << BattleList[i] << ")" << " ";
	}
	printf("\n");
	cin >> Choise;
	if (find(BattleList.begin(), BattleList.end(), Choise) != BattleList.end())
	{
		UseItem(Choise, player);
	}
	return;
}

void Inventory::BossReward(Actor* Boss)//������ ���� ������ �����ϴ� �޼ҵ�
{
	if (Boss->GetName()=="�丣���")
	{
		InventoryList.push_back("ȭ���� ����");
		ConsumablesList.push_back("ȭ���ѱ���");
	}
	else if (Boss->GetName() == "���̷���")
	{
		InventoryList.push_back("���� ����");
		ConsumablesList.push_back("�ڿ�������");
	}
	else if (Boss->GetName() == "������ �׷�")
	{
		InventoryList.push_back("���ܿ� ����");
		ConsumablesList.push_back("��ȥ�ָӴ�");
	}
	else if (Boss->GetName() == "������ ��Ӵ� ��ũ")
	{
		InventoryList.push_back("�Ƿ� ���� ����");
		ConsumablesList.push_back("â���ѹ�������");
	}
	else if (Boss->GetName() == "Ǯ���� ��")
	{
		InventoryList.push_back("���ֺ�");
	}
}

void Inventory::EquipItem()//�������� �����ϴ� �޼ҵ�. ������ �����ۿ� ���� Ư�� ������ ������ �������� ũ�� ���ϼ� �ִ�
{
	string Choise;
	printf("\n==============����ǰ==============\n");
	for (int i = 0; i < InventoryList.size(); i++)
	{
		cout << "(" << InventoryList[i] << ")" << " ";
	}
	printf("\n������ ���� ���� : ");
	cin >> Choise;
	auto iter = find(InventoryList.begin(), InventoryList.end(), Choise);
	if (iter != InventoryList.end())
	{
		EquipList.push_back(*iter);
		InventoryList.erase(iter);
		printf("�������� �����մϴ�..\n");
	}
	else
	{
		printf("�������� �����ϴ�..\n");
	}
}
void Inventory::UnEquipItem()//�������� �����ϴ� �޼ҵ�
{
	string Choise;
	printf("\n������ ���� ����\n");
	printf("\n==============������==============\n");
	for (int i = 0; i < EquipList.size(); i++)
	{
		cout << "(" << EquipList[i] << ")" << " ";
	}
	cin >> Choise;
	auto iter = find(EquipList.begin(), EquipList.end(), Choise);
	if (iter != EquipList.end())
	{
		InventoryList.push_back(*iter);
		EquipList.erase(iter);
		printf("�������� �����մϴ�..\n");
	}
	else
	{
		printf("�������� �������� �ʾҽ��ϴ�..\n");
	}
}
void Inventory::UseItem(string Choise, Player& player)//�������� ����ϴ� �޼ҵ�
{
	if (Choise == "ȭ���ѱ���")
	{
		player.PlayerDmageSet(player.GetATK() + FeatherATk);
		player.PlayerHealing(300);
		DeleteConsumablesItem(Choise);
	}
	else if (Choise == "�ڿ�������")
	{
		player.SetMaxHealth(player.GetMaxHealth() + NatureHealth);
		player.PlayerDmageSet(player.GetATK() + FeatherATk/2);
		player.PlayerHealing(1000);
		DeleteConsumablesItem(Choise);
	}
	else if (Choise == "��ȥ�ָӴ�")
	{
		player.SetMaxHealth(player.GetMaxHealth() + SoulHealth);
		player.PlayerHealing(1000);
		DeleteConsumablesItem(Choise);
	}
	else if (Choise == "â���ѹ�������")
	{
		player.PlayerDmageSet(player.GetATK() + SilkATK);
		player.SetMaxHealth(player.GetMaxHealth() + SilkHealth);
		player.PlayerHealing(1000);
		DeleteConsumablesItem(Choise);
	}
	else if (Choise == "ȸ������")
	{
		player.PlayerHealing(50);
		DeleteBattleItem(Choise);
	}
	else if (Choise == "��޹���")
	{
		player.PlayerHealing(70);
		DeleteBattleItem(Choise);
	}
	else if (Choise == "������")
	{
		player.PlayerHealing(150);
		DeleteBattleItem(Choise);
	}
	else if (Choise == "�ν˱�")
	{
		player.ActorDamgeBuff(4, 30);
		DeleteBattleItem(Choise);
	}
	else if (Choise == "����Ǻ���")
	{
		player.ActorHealthRegen(5, 40);
		DeleteBattleItem(Choise);
	}
	else if (Choise == "����ǽ���")
	{
		player.ActorDamgeBuff(20, 20);
		DeleteBattleItem(Choise);
	}
	else if (Choise == "��������")
	{
		player.SetMaxHealth(player.GetMaxHealth() + 50);
		player.PlayerHealing(100);
		DeleteConsumablesItem(Choise);
	}
	else if (Choise == "���ǽ���")
	{
		player.PlayerDmageSet(player.GetATK() + 10);
		player.SetMaxHealth(player.GetMaxHealth() + 70);
		player.PlayerHealing(100);
		DeleteConsumablesItem(Choise);
	}
	return;
}

void Inventory::PushItem(string item, string type)//�������� �з��� ���� ���Ϳ� �ִ� �޼ҵ�
{
	if (type == "����")
	{
		BattleList.push_back(item);
		return;
	}
	else if (type == "����ǰ")
	{
		InventoryList.push_back(item);
		return;
	}
	else if (type == "�Ҹ�ǰ")
	{
		ConsumablesList.push_back(item);
		return;
	}
	
}
bool Inventory::FindListItem(string item)//����ǰ ���� ������ Ȯ���ϴ� �޼ҵ�
{
	for (vector<string>::iterator iter = InventoryList.begin(); iter != InventoryList.end(); iter++)
	{
		if (*iter == item)
		{
			return true;
		}
	}
	return false;
}
bool Inventory::IsEquip(string item)//���� ������ Ȯ���ϴ� �޼ҵ�
{
	for (vector<string>::iterator iter = EquipList.begin(); iter != EquipList.end(); iter++)
	{
		if (*iter == item)
		{
			return true;
		}
	}
	return false;
}

void Inventory::DeleteItem(string item)//����ǰ �����ϴ� �޼ҵ�
{
	for (vector<string>::iterator iter = InventoryList.begin(); iter != InventoryList.end(); iter++)
	{
		if (*iter == item)
		{
			InventoryList.erase(iter);
			return;
		}
	}
	return;
}

void Inventory::DeleteConsumablesItem(string item)//�Ҹ�ǰ �����ϴ� �޼ҵ�
{
	for (vector<string>::iterator iter = ConsumablesList.begin(); iter != ConsumablesList.end(); iter++)
	{
		if (*iter == item)
		{
			ConsumablesList.erase(iter);
			return;
		}
	}
}
void Inventory::DeleteBattleItem(string item)//�������� �����ϴ� �޼ҵ�
{
	for (vector<string>::iterator iter = BattleList.begin(); iter != BattleList.end(); iter++)
	{
		if (*iter == item)
		{
			BattleList.erase(iter);
			return;
		}
	}
}

void Inventory::RecordItem(const std::string& itemName)
{
	if (!RecordUniqueItem(itemName)) {
		UniqueItems.push_back(itemName);
	}
}

bool Inventory::RecordUniqueItem(const std::string& itemName) const
{
	auto iter = std::find(UniqueItems.begin(), UniqueItems.end(), itemName);
	return iter != UniqueItems.end();
}