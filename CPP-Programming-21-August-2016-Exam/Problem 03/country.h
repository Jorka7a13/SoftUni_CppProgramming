// Georgi Tachev
// SoftUni username: Jorka7a13

#ifndef COUNTRY_H
#define COUNTRY_H
#pragma once

#include "placeForRest.h"

#include <string>
#include <vector>
#include <memory>

class Country
{
public:
	std::string name;
	std::vector<std::shared_ptr<PlaceForRest>> beaches;
	std::string currency;
	double exchangeRate;

	Country();
	Country(std::string name, std::string currency, double exchangeRate);

	void addAPlaceForRest(std::shared_ptr<PlaceForRest> placeForRest);
	void removeAPlaceForRest(std::string name);

	void searchForAPlaceToRest(TerrainType terrainType, unsigned int numberOfVisitors, float priceOfMojito);
};

#endif