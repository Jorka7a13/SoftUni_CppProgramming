#include "building.h"
#include <iostream>

Building::Building(std::string name, unsigned int numberOfFloors, unsigned int numberOfOffices,
	unsigned int numberOfEmployees, unsigned int numberOfFreeWorkingSeats, bool hasRestaurant)
	: name_(name), 
	numberOfFloors_(numberOfFloors), 
	numberOfOffices_ (numberOfOffices), 
	numberOfEmployees_(numberOfEmployees), 
	numberOfFreeWorkingSeats_ (numberOfFreeWorkingSeats), 
	hasRestaurant_ (hasRestaurant)
{}

Building::~Building()
{}

std::string Building::getName() const
{
	return this->name_;
}

unsigned int Building::getNumberOfFloors() const
{
	return this->numberOfFloors_;
}

unsigned int Building::getNumberOfOffices() const
{
	return this->numberOfOffices_;
}

unsigned int Building::getNumberOfEmployees() const
{
	return this->numberOfEmployees_;
}

unsigned int Building::getNumberOfFreeWorkingSeats() const
{
	return this->numberOfFreeWorkingSeats_;
}

bool Building::hasRestaurant() const
{
	return this->hasRestaurant_;
}