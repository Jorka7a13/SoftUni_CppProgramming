#include "cashRegister.h"

CashRegister::CashRegister()
	: total_(0)
{
	items_ = std::vector<Item*>();
}

CashRegister::CashRegister(std::vector<Item*> items)
	: items_(items), total_(0)
{}

CashRegister& CashRegister::operator+=(Item& item)
{
	this->items_.push_back(&item);
	this->total_ += item.price_;

	return *this;
}

void CashRegister::addToTotal(double amount)
{
	total_ += amount;
}

void CashRegister::clearTotal()
{
	total_ = 0;
}

double CashRegister::getTotal()
{
	return total_;
}

double CashRegister::calculateChange(float payment)
{
	return payment - total_;
}

Item* CashRegister::getItemByBarcode(std::string barcode)
{
	for (Item* item : items_)
	{
		if (item->barcode_ == barcode)
		{
			return item;
		}
	}

	return nullptr;
}