#pragma once
#include "Player.h"
#include "Inventory.h"
#include <vector>
struct Item
{
    std::string Name;
    std::string Type;
    std::string Description;
    int Price;
};

class Shop
{
public:
    Shop();
    void OpenShop(Player* player, Inventory* inventory);

private:
    void DisplayItems();
    void SellItem(int itemIndex, Player* player, Inventory* inventory);
    std::vector<Item> ForSaleItems;
};

