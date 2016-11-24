#include "vehicleManager.h"
#include "vehicle.h"
#include <vector>
#include <algorithm>
#include <future>

VehicleManager::VehicleManager()
{
	cars_ = std::vector<Vehicle>();
	motorcycles_ = std::vector<Vehicle>();
	trucks_ = std::vector<Vehicle>();
}

void VehicleManager::addVehicle(Vehicle vehicle)
{
	if (vehicle.getTypeOfVehicle() == "Car" || vehicle.getTypeOfVehicle() == "car")
	{
		cars_.push_back(vehicle);
	} 
	else if (vehicle.getTypeOfVehicle() == "Motorcycle" || vehicle.getTypeOfVehicle() == "motorcycle")
	{
		motorcycles_.push_back(vehicle);
	}
	else if (vehicle.getTypeOfVehicle() == "Truck" || vehicle.getTypeOfVehicle() == "truck")
	{
		trucks_.push_back(vehicle);
	}
}

void VehicleManager::searchVehiclesByRegistrationNumber(std::string registrationNumber, std::function<void(Vehicle*)> callback)
{
	std::future<Vehicle*> searchCars = std::async(std::launch::async, &VehicleManager::searchContainerForVehicle, this, registrationNumber, cars_);
	std::future<Vehicle*> searchMotorcycles = std::async(std::launch::async, &VehicleManager::searchContainerForVehicle, this, registrationNumber, motorcycles_);
	std::future<Vehicle*> searchTrucks = std::async(std::launch::async, &VehicleManager::searchContainerForVehicle, this, registrationNumber, trucks_);

	Vehicle* carsResult = searchCars.get();
	Vehicle* motorcyclesResult = searchMotorcycles.get();
	Vehicle* trucksResult = searchTrucks.get();

	Vehicle* result = NULL;

	if (carsResult)
	{
		result = carsResult;
	}
	else if(motorcyclesResult)
	{
		result = motorcyclesResult;
	}
	else if (trucksResult)
	{
		result = trucksResult;
	}
	 
	callback(result);
}

Vehicle* VehicleManager::searchContainerForVehicle(std::string registrationNumber, std::vector<Vehicle> &container)
{
	Vehicle *result = NULL;

	std::for_each(container.begin(), container.end(), [&](Vehicle &currentVehicle)
	{
		if (currentVehicle.getRegistrationNumber() == registrationNumber)
		{
			result = &currentVehicle;
		}
	});

	return result;
}