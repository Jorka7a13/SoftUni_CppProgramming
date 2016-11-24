#include "cashRegisterController.h"
using namespace std;

CashRegisterController::CashRegisterController(std::vector<Item*> items)
{
	cashRegister_ = CashRegister(items);
}

void CashRegisterController::printReceipt(float payment, double change)
{
	cout << "Receipt" << endl;
	cout << "CandyShop" << endl;
	cout << "BIC:12345678" << endl;
	cout << "Address: Somewhere in the middle of nowhere." << endl;
	cout << "Purchases: " << cashRegister_.getTotal() << "lv." << endl;
	cout << "Given: " << payment << "lv." << endl;
	cout << "Change: " << change << "lv." << endl;
}

void CashRegisterController::runCashRegister()
{
	cout << string(50, '\n'); // Clears the console.
	cout << "Cash Register" << endl << endl;

	bool isCashRegisterRunning = true;

	while (isCashRegisterRunning)
	{
		string input;
		cin >> input;

		if (input == "C" || input == "c")
		{
			cashRegister_.clearTotal();
			cout << "Total: 0.00lv." << endl;
		}
		else if (input == "T" || input == "t")
		{
			cout << "Total: " << cashRegister_.getTotal() << "lv." << endl;
		}
		else if (input == "G" || input == "g")
		{
			float payment;

			cout << "Please enter the amount of money: ";
			cin >> payment;

			double change = cashRegister_.calculateChange(payment);
			if (change >= 0)
			{
				cout << "The change is: " << change << "lv." << endl;
				cout << endl;
				printReceipt(payment, change);
				cashRegister_.clearTotal();
			}
			else
			{
				cerr << "Insufficient payment!" << endl;
			}
				
			isCashRegisterRunning = false;
		}
		else 
		{
			Item* result = cashRegister_.getItemByBarcode(input);

			if (result != nullptr)
			{
				cashRegister_.addToTotal(result->price_);
				cout << "Item purchased: " << result->name_ << " - " << result->price_ << "lv." << endl;
			}
			else
			{
				cerr << "Item cannot be found!" << endl;
			}
		}

		cout << endl;
	}
}

void CashRegisterController::runItemPriceChange()
{
	cout << "Enter item's barcode: ";

	string input;
	cin >> input;
	cout << endl;

	Item* result = cashRegister_.getItemByBarcode(input);
	if (result != nullptr)
	{
		cout << result->name_ << " - " << result->price_ << "lv." << endl;
		cout << "Please enter a new price for this item: ";

		string newPrice;
		cin >> newPrice;
		cout << endl;

		result->price_ = stof(newPrice.c_str());
		cout << "Item price changed! New price: " << result->price_ << "lv." << endl;
	}
	else
	{
		cerr << "Item cannot be found!" << endl;
	}
}

void CashRegisterController::run()
{
	int menuSelection;
	bool isRunning = true;

	cout << "This is a cash register!" << endl << endl;

	while (isRunning)
	{
		cout << "Please choose an option: " << endl;
		cout << "1. Cash Register" << endl;
		cout << "2. Change the price of an item" << endl;
		cout << "0. Exit" << endl << endl;

		cout << "Option: ";
		cin >> menuSelection;

		if (menuSelection != 0 && (menuSelection < 1 || menuSelection > 3))
		{
			cerr << menuSelection << " is an invalid option!" << endl << endl;
		}
		else if (menuSelection == 0)
		{
			isRunning = false;
		}
		else
		{
			switch (menuSelection)
			{
			case 1:
				runCashRegister();
				break;
			case 2:
				runItemPriceChange();
				break;
			}

			cout << endl << endl;
		}
	}
}