#ifndef BUILDING_H
#define BUILDING_H
#pragma once

#include <string>

class Building
{
private:
	std::string name_;
	unsigned int numberOfFloors_;
	unsigned int numberOfOffices_;
	unsigned int numberOfEmployees_;
	unsigned int numberOfFreeWorkingSeats_;
	bool hasRestaurant_;

public:
	Building(std::string name, unsigned int numberOfFloors, unsigned int numberOfOffices, 
		unsigned int numberOfEmployees, unsigned int numberOfFreeWorkingSeats, bool hasRestaurant = false);
	~Building();

	std::string getName() const;
	unsigned int getNumberOfFloors() const;
	unsigned int getNumberOfOffices() const;
	unsigned int getNumberOfEmployees() const;
	unsigned int getNumberOfFreeWorkingSeats() const;
	bool hasRestaurant() const;
};

#endif