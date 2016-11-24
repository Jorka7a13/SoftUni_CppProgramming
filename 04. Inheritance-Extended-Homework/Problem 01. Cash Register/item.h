#ifndef ITEM_H
#define ITEM_H
#pragma once

#include <string>

class Item
{
public:
	std::string name_;
	float price_;
	std::string barcode_;

	Item();
	Item(std::string name, float price, std::string barcode);

	Item(const Item &item);
	void operator=(const Item &item);

	void changePrice(float price);
};

#endif