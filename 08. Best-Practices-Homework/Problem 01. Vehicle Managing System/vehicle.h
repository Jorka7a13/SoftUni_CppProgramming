#ifndef VEHICLE_H
#define VEHICLE_H
#pragma once

#include "customDate.h"
#include <string>

class Vehicle
{
private:
	std::string typeOfVehicle_;
	std::string registrationNumber_;
	float weightInTonnes_;
	unsigned short int numberOfSeats_;
	std::string chassisNumber_;
	std::string engineNumber_;
	std::string owner_;
	CustomDate dateOfFirstRegistration_;
	CustomDate dateOfRegistrationInCountry_;

public:
	Vehicle();
	Vehicle(std::string typeOfVehicle, std::string registrationNumber, float weightInTonnes,
		unsigned short int numberOfSeats, std::string chassisNumber, std::string engineNumber,
		std::string owner, CustomDate dateOfFirstRegistration, CustomDate dateOfRegistrationInCountry);

	std::string getTypeOfVehicle();
	std::string getRegistrationNumber();
	float getWeightInTonnes();
	unsigned short int getNumberOfSeats();
	std::string getChassisNumber();
	std::string getEngineNumber();
	std::string getOwner();
	CustomDate getDateOfFirstRegistration();
	CustomDate getDateOfRegistrationInCountry();

	void printInformation();
};

#endif