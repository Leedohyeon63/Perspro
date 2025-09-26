#include "Shop.h"
#include <iostream>
//상점을 관리하는 클래스
Shop::Shop()
{

}

void Shop::LoadItem(int stage, Inventory* playerInventory)
{
	ForSaleItems.clear();
	switch (stage)
	{
	case 1:
		ForSaleItems.push_back({ "회복물약", "전투", "체력을 50 회복합니다.", 100, false });
		ForSaleItems.push_back({ "고급물약", "전투", "체력을 100 회복합니다.", 150, false });
		if (!playerInventory->RecordUniqueItem("부싯깃")) {
			ForSaleItems.push_back({ "부싯깃", "전투", "공격력이 4턴동안 30만큼 증가합니다.", 50, true });
		}
		if (!playerInventory->RecordUniqueItem("꽃가림막")) {
			ForSaleItems.push_back({ "꽃가림막","소지품", "무언가 막을 수 있을 것 같습니다..", 100 , true });
		}
		if (!playerInventory->RecordUniqueItem("뼈방패")) {
			ForSaleItems.push_back({ "뼈방패","소지품", "무언가 막을 수 있을 것 같습니다..", 100, true });
		}
		break;

	case 2:
		ForSaleItems.push_back({ "회복물약","전투", "체력을 50 회복합니다.", 100 , false });
		ForSaleItems.push_back({ "고급물약","전투", "체력을 100 회복합니다.",150 , false });
		ForSaleItems.push_back({ "벼룩주","전투", "체력을 150 회복합니다.", 200 , false });
		if (!playerInventory->RecordUniqueItem("부싯깃")) {
			ForSaleItems.push_back({ "부싯깃", "전투", "공격력이 4턴동안 30만큼 증가합니다.", 50, true });
		}
		if (!playerInventory->RecordUniqueItem("용암의종")) {
			ForSaleItems.push_back({ "용암의종","소지품", "화염으로부터 착용자를 보호합니다.", 350 , true });
		}
		if (!playerInventory->RecordUniqueItem("페이깃털")) {
			ForSaleItems.push_back({ "페이깃털","소지품", "몸이 가벼워 집니다.", 350 , true });
		}
		break;
	case 3:
		ForSaleItems.push_back({ "벼룩주","전투", "체력을 150 회복합니다.", 200 , false });
		ForSaleItems.push_back({ "재생의부적","전투", "5턴 동안 20의 체력 재생을 얻습니다.", 250 , false });
		if (!playerInventory->RecordUniqueItem("낡은심장")) {
			ForSaleItems.push_back({ "낡은심장","소모품", "최대체력이 50 늘어납니다.", 400 , true });
		}
		if (!playerInventory->RecordUniqueItem("순수의화환")) {
			ForSaleItems.push_back({ "순수의화환","소지품", "더러운 것으로부터 플레이어를 막아줍니다.", 400 , true });
		}
		break;
	case 4:
		ForSaleItems.push_back({ "벼룩주","전투", "체력을 150 회복합니다.", 200 , false });
		ForSaleItems.push_back({ "재생의부적","전투", "5턴 동안 20의 체력 재생을 얻습니다.", 250 , false });
		if (!playerInventory->RecordUniqueItem("기사의심장")) {
			ForSaleItems.push_back({ "기사의심장","전투", "20턴동안 공격력이 40 증가합니다.", 350 , true });
		}
		if (!playerInventory->RecordUniqueItem("용의심장")) {
			ForSaleItems.push_back({ "용의심장","소모품", "최대체력이 70, 공격력이 10 늘어납니다.", 500 , true });
		}
		break;
	default:
		break;
	}
}
void Shop::OpenShop(Player* player, Inventory* inventory)//상점 메인화면
{
	int Choice = 0;
	while (true)
	{
		system("cls");
		printf("==================상점==================\n");
		printf("소지금: %d Gold\n\n", player->GetGold());
		DisplayItems();
		printf("========================================\n");
		printf("구매할 아이템의 번호를 입력하세요 (나가려면 0번): ");
		std::cin >> Choice;

		if (Choice == 0) {
			break;
		}
		if (Choice > 0 && Choice <= ForSaleItems.size()) {
			SellItem(Choice - 1, player, inventory);
		}
		else {
			printf("잘못된 번호입니다.\n");
		}
		system("pause");
	}
}


void Shop::DisplayItems()//상점에서 파는 아이템을 출력하는 메소드
{
	if (ForSaleItems.empty()) {
		printf("모든 상품이 판매되었습니다.\n");
		return;
	}
	for (int i = 0; i < ForSaleItems.size(); ++i)
	{
		const auto& Item = ForSaleItems[i];
		printf("%d. %s, %d 원\n : %s\n", i + 1, Item.Name.c_str(), Item.Price, Item.Description.c_str());
	}
}

void Shop::SellItem(int itemIndex, Player* player, Inventory* inventory)//상점에서 파는 아이템을 구매하는 메소드
{
	const Item& ItemBuy = ForSaleItems[itemIndex];

	if (player->GetGold() >= ItemBuy.Price)
	{
		player->PlayerGetMoney(player->GetGold() - ItemBuy.Price);
		inventory->PushItem(ItemBuy.Name.c_str(), ItemBuy.Type);
		printf("\n%s을(를) 구매했습니다..\n", ItemBuy.Name.c_str());
		if (ItemBuy.CantReSell) // 재구매 불가 상품이면
		{
			inventory->RecordItem(ItemBuy.Name);
		}
		if (ItemBuy.CantReSell)//재구매 불가 상품이면 상점에서 삭제
		{
			ForSaleItems.erase(ForSaleItems.begin() + itemIndex);
		}

	}
	else
	{
		printf("\n골드가 부족합니다..\n");
	}
}
