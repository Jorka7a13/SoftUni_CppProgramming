#ifndef CASH_REGISTER_H
#define CASH_REGISTER_H
#pragma once

#include "item.h"
#include <vector>

class CashRegister
{
private:
	double total_;
	std::vector<Item*> items_;

public:
	CashRegister();
	CashRegister(std::vector<Item*> items);

	CashRegister& operator+=(Item& item);

	void addToTotal(double amount);
	void clearTotal();
	double getTotal();
	double calculateChange(float payment);
	Item* getItemByBarcode(std::string barcode);
};

#endif