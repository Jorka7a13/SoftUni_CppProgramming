// Georgi Tachev
// SoftUni username: Jorka7a13

#include "country.h"

#include <memory>
#include <mutex>
std::mutex mtx;

Country::Country()
{}

Country::Country(std::string name, std::string currency, double exchangeRate)
	: name(name), currency(currency), exchangeRate(exchangeRate)
{}

void Country::addAPlaceForRest(std::shared_ptr<PlaceForRest> placeForRest)
{
	mtx.lock(); // Prevent threads from adding a place for rest while searching.

	this->beaches.push_back(std::move(placeForRest));

	mtx.unlock();
}

void Country::removeAPlaceForRest(std::string name)
{
	mtx.lock(); // Prevent threads from removing a place for rest while searching.

	std::vector<std::shared_ptr<PlaceForRest>>::iterator iterator = this->beaches.begin();

	for (iterator; iterator != this->beaches.end(); iterator++)
	{
		if (iterator->get()->name == name)
		{
			iterator = this->beaches.erase(iterator);
		}
	}

	mtx.unlock();
}

void Country::searchForAPlaceToRest(TerrainType terrainType, unsigned int numberOfVisitors, float priceOfMojito)
{
	std::vector<std::shared_ptr<PlaceForRest>>::iterator iterator = this->beaches.begin();
	
	for (iterator; iterator != this->beaches.end(); iterator++)
	{
		if (iterator->get()->terrainType == terrainType
			&& iterator->get()->numberOfVisitors == numberOfVisitors
			&& iterator->get()->priceOfMojito == priceOfMojito)
		{
			mtx.lock(); // Prevent other threads from writing on the console.

			iterator->get()->printInformation(this->currency);

			mtx.unlock();
		}
	}
}