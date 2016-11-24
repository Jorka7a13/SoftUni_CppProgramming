// Georgi Tachev
// SoftUni username: Jorka7a13

#include "country.h"
#include "placeForRest.h"

#include <memory>
#include <thread>

int main()
{
	std::shared_ptr<PlaceForRest> arapya(new PlaceForRest("Arapya", 2.52, 3.66, TERRAIN_SAND, WATER_SEA, 4, 6, 5000, 25, 40, 2.5, 4, 3));
	std::shared_ptr<PlaceForRest> boraBora(new PlaceForRest("Bora Bora", 5.51, 4.27, TERRAIN_SAND, WATER_OCEAN, 8, 10, 10000, 1525, 8, 12, 14.5, 11));
	std::shared_ptr<PlaceForRest> liulin(new PlaceForRest("Liulin", 0.0, 0.0, TERRAIN_OTHER, WATER_OTHER, 0, 5, 800000, 150, 2000, 1.5, 2, 1.5));
	std::shared_ptr<PlaceForRest> sandanski(new PlaceForRest("Sandanski", 15.01, 26.77, TERRAIN_SAND, WATER_NONE, 6, 4, 2000, 13, 40, 4, 6.5, 4.5));

	std::shared_ptr<Country> bulgaria(new Country("Bulgaria", "BGN", 1.95719));
	std::shared_ptr<Country> frenchPolynesia(new Country("French Polynesia", "CFP", 0.00838));

	bulgaria->addAPlaceForRest(arapya);
	bulgaria->addAPlaceForRest(liulin);
	bulgaria->addAPlaceForRest(sandanski);
	frenchPolynesia->addAPlaceForRest(boraBora);

	bulgaria->removeAPlaceForRest("Liulin");
	frenchPolynesia->addAPlaceForRest(liulin);

	std::thread bulgariaSearchThread(&Country::searchForAPlaceToRest, bulgaria, TERRAIN_SAND, 5000, 4); // Spawns a new thread to search for places in Bulgaria.
	std::thread frenchPolynesiaSearchThread(&Country::searchForAPlaceToRest, frenchPolynesia, TERRAIN_SAND, 10000, 14.5); // Spawns a new thread to search for places in French Polynesia.

	std::thread bulgariaRemoveThread(&Country::removeAPlaceForRest, bulgaria, "Arapya"); // Spawns a new thread to remove a place from Bulgaria.

	bulgariaSearchThread.join();
	frenchPolynesiaSearchThread.join();

	bulgariaRemoveThread.join();

	return 0;
}