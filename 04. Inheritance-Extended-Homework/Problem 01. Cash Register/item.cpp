#include "item.h"

Item::Item() 
	: name_(""), price_(0.0)
{}

Item::Item(std::string name = "", float price = 0.0, std::string barcode = "1111111111")
	: name_(name), price_(price), barcode_(barcode)
{}

Item::Item(const Item &item)
{
	this->name_ = item.name_;
	this->price_ = item.price_;
	this->barcode_ = item.barcode_;
}

void Item::operator=(const Item &item)
{
	this->name_ = item.name_;
	this->price_ = item.price_;
	this->barcode_ = item.barcode_;
}

void Item::changePrice(float price)
{
	this->price_ = price;
}