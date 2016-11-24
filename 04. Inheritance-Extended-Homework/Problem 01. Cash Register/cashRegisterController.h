#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H
#pragma once

#include "cashRegister.h"
#include <iostream>

class CashRegisterController
{
private:
	CashRegister cashRegister_;

	void printReceipt(float payment, double change);
	void runCashRegister();
	void runItemPriceChange();

public:
	CashRegisterController(std::vector<Item*> items);
	void run();
};

#endif