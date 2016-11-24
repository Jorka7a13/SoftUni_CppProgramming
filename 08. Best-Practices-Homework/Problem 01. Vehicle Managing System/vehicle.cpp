#include "vehicle.h"
#include <iostream>

Vehicle::Vehicle()
{
	typeOfVehicle_ = "";
	registrationNumber_ = "";
	weightInTonnes_ = 0;
	numberOfSeats_ = 0;
	chassisNumber_ = "0";
	engineNumber_ = "0";
	owner_ = "";
	dateOfFirstRegistration_ = CustomDate();
	dateOfRegistrationInCountry_ = CustomDate();
}

Vehicle::Vehicle(std::string typeOfVehicle, std::string registrationNumber, float weightInTonnes,
	unsigned short int numberOfSeats, std::string chassisNumber, std::string engineNumber,
	std::string owner, CustomDate dateOfFirstRegistration, CustomDate dateOfRegistrationInCountry)
{
	typeOfVehicle_ = typeOfVehicle;
	registrationNumber_ = registrationNumber;
	weightInTonnes_ = weightInTonnes;
	numberOfSeats_ = numberOfSeats;
	chassisNumber_ = chassisNumber;
	engineNumber_ = engineNumber;
	owner_ = owner;
	dateOfFirstRegistration_ = dateOfFirstRegistration;
	dateOfRegistrationInCountry_ = dateOfRegistrationInCountry;
}

std::string Vehicle::getTypeOfVehicle()
{
	return this->typeOfVehicle_;
}

std::string Vehicle::getRegistrationNumber() 
{
	return this->registrationNumber_;
}

float Vehicle::getWeightInTonnes()
{
	return this->weightInTonnes_;
}

unsigned short int Vehicle::getNumberOfSeats()
{
	return this->numberOfSeats_;
}

std::string Vehicle::getChassisNumber()
{
	return this->chassisNumber_;
}

std::string Vehicle::getEngineNumber()
{
	return this->engineNumber_;
}

std::string Vehicle::getOwner()
{
	return this->owner_;
}

CustomDate Vehicle::getDateOfFirstRegistration()
{
	return this->dateOfFirstRegistration_;
}

CustomDate Vehicle::getDateOfRegistrationInCountry()
{
	return this->dateOfRegistrationInCountry_;
}

void Vehicle::printInformation()
{
	std::cout << "Registration number: " << getRegistrationNumber() << std::endl;
	std::cout << "Weight: " << getWeightInTonnes() << " t" << std::endl;
	std::cout << "Number of seats: " << getNumberOfSeats() << std::endl;
	std::cout << "Chassis number: " << getChassisNumber() << std::endl;
	std::cout << "Engine number: " << getEngineNumber() << std::endl;
	std::cout << "Owner: " << getOwner() << std::endl;
	std::cout << "Date of first registration: " << getDateOfFirstRegistration().getDate() << std::endl;
	std::cout << "Date of registration in country: " << getDateOfRegistrationInCountry().getDate() << std::endl;
}