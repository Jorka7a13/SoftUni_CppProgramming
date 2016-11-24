// Georgi Tachev
// SoftUni username: Jorka7a13

#include "placeForRest.h"

#include <iostream>

PlaceForRest::PlaceForRest()
{}

PlaceForRest::PlaceForRest(
	std::string name,
	double latitude,
	double longitude,
	TerrainType terrainType,
	WaterbodyType waterbodyType,
	unsigned char cleanlinessOfTerrain,
	unsigned char cleanlinessOfWaterbody,
	unsigned int numberOfVisitors,
	float pricePerDay,
	unsigned long long numberOfBars,
	float priceOfRaspberryDaiquiri,
	float priceOfMojito,
	float priceOfOrangeJuice)
	: name(name), terrainType(terrainType), waterbodyType(waterbodyType), numberOfVisitors(numberOfVisitors), pricePerDay(pricePerDay),
	numberOfBars(numberOfBars), priceOfRaspberryDaiquiri(priceOfRaspberryDaiquiri), priceOfMojito(priceOfMojito), priceOfOrangeJuice(priceOfOrangeJuice)
{
	Coordinates coordinates;
	coordinates.longitude = longitude;
	coordinates.latitude = latitude;

	this->coordinates = coordinates;

	this->setCleanlinessOfTerrain(cleanlinessOfTerrain);
	this->setCleanlinessOfWaterbody(cleanlinessOfWaterbody);
}

void PlaceForRest::setCleanlinessOfTerrain(unsigned char rating)
{
	if (rating < 0 || rating > 10)
	{
		std::cerr << "Rating for cleanliness of terrain must be between 0 and 10! Rating automatically set to 0!" << std::endl;
		this->cleanlinessOfTerrain_ = 0;
	}

	this->cleanlinessOfTerrain_ = rating;
}

unsigned char PlaceForRest::getCleanlinessOfTerrain() const
{
	return this->cleanlinessOfTerrain_;
}

void PlaceForRest::setCleanlinessOfWaterbody(unsigned char rating)
{
	if (rating < 0 || rating > 10)
	{
		std::cerr << "Rating for cleanliness of bodywater must be between 0 and 10! Rating automatically set to 0!" << std::endl;
		cleanlinessOfWaterbody_ = 0;
	}

	this->cleanlinessOfWaterbody_ = rating;
}

unsigned char PlaceForRest::getCleanlinessOfBodywater() const
{
	return this->cleanlinessOfWaterbody_;
}

void PlaceForRest::printInformation(std::string currency) const
{
	std::string valueTerrainArray[] = { "Sand", "Rocks", "Tiles", "Asphalt", "Mixed", "Other" }; // Used to print the value of the enum.
	std::string valueWaterbodyArray[] = { "Sea", "Ocean", "Pool", "Puddle", "None", "Other" };

	std::cout << "Name: " << this->name << std::endl;
	std::cout << "Coordinates: " << this->coordinates.latitude << ", " << this->coordinates.longitude << std::endl;
	std::cout << "Terrain type: " << valueTerrainArray[terrainType] << std::endl;
	std::cout << "Waterbody type: " << valueWaterbodyArray[waterbodyType] << std::endl;
	std::cout << "Cleanliness of terrain: " << (int)this->getCleanlinessOfTerrain() << std::endl;
	std::cout << "Cleanliness of waterbody: " << (int)this->getCleanlinessOfBodywater() << std::endl;
	std::cout << "Number of visitors: " << this->numberOfVisitors << std::endl;
	std::cout << "Price per day: " << this->pricePerDay << " " << currency << std::endl;
	std::cout << "Number of bars: " << this->numberOfBars << std::endl;
	std::cout << "Price of Raspberry Daiquiri: " << this->priceOfRaspberryDaiquiri << " " << currency << std::endl;
	std::cout << "Price of Mojito: " << this->priceOfMojito << " " << currency << std::endl;
	std::cout << "Price of Orange juice: " << this->priceOfOrangeJuice << " " << currency << std::endl;
	std::cout << std::endl;
}