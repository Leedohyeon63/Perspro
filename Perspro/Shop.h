#pragma once
#include "Player.h"
#include "Inventory.h"
#include <vector>
//�÷��̾� �κ��丮 ���� �۾� �����ϴ� Ŭ����
struct Item
{//������ ���� ����ü �̸�, Ÿ��, ����, ����, �籸�� ����
    std::string Name;
    std::string Type;
    std::string Description;
    int Price;
    bool CantReSell;

};

class Shop
{
public:
    Shop();
    bool NotVisit = true;
    void OpenShop(Player* player, Inventory* inventory);
    void LoadItem(int stage, Inventory* playerInventory);
private:
    void DisplayItems();
    void SellItem(int itemIndex, Player* player, Inventory* inventory);
    std::vector<Item> ForSaleItems;
};

