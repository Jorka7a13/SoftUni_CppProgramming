// Georgi Tachev
// SoftUni username: Jorka7a13

#ifndef PLACE_FOR_REST_H
#define PLACE_FOR_REST_H
#pragma once

#include <string>

enum TerrainType { TERRAIN_SAND, TERRAIN_ROCKS, TERRAIN_TILES, TERRAIN_ASPHALT_OR_WHATS_LEFT_OF_IT, TERRAIN_MIXED, TERRAIN_OTHER };
enum WaterbodyType { WATER_SEA, WATER_OCEAN, WATER_POOL, WATER_PUDDLE, WATER_NONE, WATER_OTHER };

struct Coordinates
{
	double latitude;
	double longitude;
};

class PlaceForRest
{
private:
	unsigned char cleanlinessOfTerrain_;
	unsigned char cleanlinessOfWaterbody_;

public:
	std::string name;
	Coordinates coordinates;
	TerrainType terrainType;
	WaterbodyType waterbodyType;
	unsigned int numberOfVisitors;
	float pricePerDay;
	unsigned long long numberOfBars; // There might be maaaaany bars!
	float priceOfRaspberryDaiquiri;
	float priceOfMojito;
	float priceOfOrangeJuice;

	PlaceForRest();
	PlaceForRest(
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
		float priceOfOrangeJuice);

	void setCleanlinessOfTerrain(unsigned char rating);
	unsigned char getCleanlinessOfTerrain() const;

	void setCleanlinessOfWaterbody(unsigned char rating);
	unsigned char getCleanlinessOfBodywater() const;

	void printInformation(std::string currency) const;
};

#endif