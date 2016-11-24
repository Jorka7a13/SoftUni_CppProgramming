#ifndef VEHICLE_MANAGER_H
#define VEHICLE_MANAGER_H
#pragma once

#include "vehicle.h"
#include <vector>
#include <string>
#include <functional>

class VehicleManager
{
private:
	std::vector<Vehicle> cars_;
	std::vector<Vehicle> motorcycles_;
	std::vector<Vehicle> trucks_;

	Vehicle* searchContainerForVehicle(std::string registrationNumber, std::vector<Vehicle> &container);

public:
	VehicleManager();

	void addVehicle(Vehicle vehicle);
	void searchVehiclesByRegistrationNumber(std::string registrationNumber, std::function<void(Vehicle*)> callback);
};

#endif