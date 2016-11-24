#include "cashRegisterController.h"

int main()
{
	std::vector<Item*> items;
	items.push_back(new Item("Milk", 1.5, "1111111111"));
	items.push_back(new Item("Eggs", 2, "1111111112"));
	items.push_back(new Item("Bread", 1, "1111111113"));
	items.push_back(new Item("Coca-Cola", 2.5, "1111111114"));

	CashRegisterController cashRegisterController = CashRegisterController(items);
	cashRegisterController.run();

	return 0;
}