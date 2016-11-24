#include "vehicleManager.h"
#include "vehicle.h"
#include "customDate.h"
#include <functional>
#include <iostream>

void runAddVehicleMenu(VehicleManager &vehicleManager)
{
	std::string type;
	std::string registrationNumber;
	float weight;
	unsigned short int numberOfSeats;
	std::string chassisNumber;
	std::string engineNumber;
	std::string owner;
	std::string dateOfFirstRegistration;
	std::string dateOfRegistrationInCountry;

	std::cout << "Add Vehicle Menu" << std::endl;
	std::cout << std::endl;
	std::cout << "Type of vehicle: ";
	std::cin >> type;
	std::cout << "Registration number: ";
	std::cin >> registrationNumber;
	std::cout << "Weight (in tonnes): ";
	std::cin >> weight;
	std::cout << "Number of seats: ";
	std::cin >> numberOfSeats;
	std::cout << "Chassis number: ";
	std::cin >> chassisNumber;
	std::cout << "Engine number: ";
	std::cin >> engineNumber;
	std::cout << "Owner: ";
	std::cin.ignore(256, '\n');
	std::getline(std::cin, owner);
	std::cout << "Date of first registration (DD.MM.YYYY): ";
	std::cin >> dateOfFirstRegistration;
	std::cout << "Date of registration in country (DD.MM.YYYY): ";
	std::cin >> dateOfRegistrationInCountry;
	std::cout << std::endl;
	std::cout << std::endl;

	Vehicle vehicle = Vehicle(type, registrationNumber, weight, numberOfSeats, 
		chassisNumber, engineNumber, owner, CustomDate(dateOfFirstRegistration), CustomDate(dateOfRegistrationInCountry));

	vehicleManager.addVehicle(vehicle);
}

void runSearchVehicleMenu(VehicleManager &vehicleManager, std::function<void(Vehicle*)> callback)
{
	std::string registrationNumber;

	std::cout << "Search Menu" << std::endl;
	std::cout << std::endl;
	
	std::cout << "Please enter a registration number: ";
	std::cin >> registrationNumber;
	std::cout << std::endl;

	vehicleManager.searchVehiclesByRegistrationNumber(registrationNumber, callback);
}

int main()
{
	std::function<void(Vehicle*)> printVehicleInformation = [](Vehicle* vehicle)
	{
		if (vehicle == NULL)
		{
			std::cout << "No matches for this registration number." << std::endl;
			std::cout << std::endl;
		}
		else
		{
			std::cout << "Type of vehicle: " << vehicle->getTypeOfVehicle() << std::endl;
			std::cout << "Registration number: " << vehicle->getRegistrationNumber() << std::endl;
			std::cout << "Weight: " << vehicle->getWeightInTonnes() << " t" << std::endl;
			std::cout << "Number of seats: " << vehicle->getNumberOfSeats() << std::endl;
			std::cout << "Chassis number: " << vehicle->getChassisNumber() << std::endl;
			std::cout << "Engine number: " << vehicle->getEngineNumber() << std::endl;
			std::cout << "Owner: " << vehicle->getOwner() << std::endl;
			std::cout << "Date of first registration: " << vehicle->getDateOfFirstRegistration().getDate() << std::endl;
			std::cout << "Date of registration in country: " << vehicle->getDateOfRegistrationInCountry().getDate() << std::endl;
			std::cout << std::endl;
		}
	};

	VehicleManager vehicleManager = VehicleManager();

	int menuSelection;
	bool isRunning = true;

	std::cout << "Vehicle Managing System" << std::endl;
	std::cout << std::endl;

	while (isRunning)
	{
		std::cout << "Please choose an option: " << std::endl;
		std::cout << "1. Add Vehicle" << std::endl;
		std::cout << "2. Search For Vehicle" << std::endl;
		std::cout << "0. Exit" << std::endl << std::endl;

		std::cout << "Option: ";
		std::cin >> menuSelection;
		std::cout << std::endl;

		if (menuSelection != 0 && (menuSelection < 1 || menuSelection > 2))
		{
			std::cerr << menuSelection << " is an invalid option!" << std::endl;
			std::cout << std::endl;
		}
		else if (menuSelection == 0)
		{
			isRunning = false;
		}
		else
		{
			switch (menuSelection)
			{
			case 1:
				runAddVehicleMenu(vehicleManager);
				break;
			case 2:
				runSearchVehicleMenu(vehicleManager, printVehicleInformation);
				break;
			}
		}
	}

	return 0;
}