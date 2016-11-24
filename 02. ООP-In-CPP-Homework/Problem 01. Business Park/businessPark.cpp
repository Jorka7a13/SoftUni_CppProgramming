#include "building.h"
#include <array>
#include <iostream>

template<size_t N>
std::string calculateMostEmployees(std::array<Building, N> input)
{
	Building result = input[0];

	for (int i = 1; i < N; i++)
	{
		if (input[i].getNumberOfEmployees() > result.getNumberOfEmployees())
		{
			result = input[i];
		}
	}

	return result.getName();
}

template<size_t N>
std::string calculateMostFreeWorkingSeats(std::array<Building, N> input)
{
	Building result = input[0];

	for (int i = 1; i < N; i++)
	{
		if (input[i].getNumberOfFreeWorkingSeats() > result.getNumberOfFreeWorkingSeats())
		{
			result = input[i];
		}
	}

	return result.getName();
}

template<size_t N>
std::string calculateHighestCoefficient(std::array<Building, N> input)
{
	Building result = input[0];

	for (int i = 1; i < N; i++)
	{
		double resultCoefficient = (double)result.getNumberOfEmployees() / (result.getNumberOfEmployees() + result.getNumberOfFreeWorkingSeats());
		double currentCoefficient = (double)input[i].getNumberOfEmployees() / (input[i].getNumberOfEmployees() + input[i].getNumberOfFreeWorkingSeats());

		if (currentCoefficient > resultCoefficient)
		{
			result = input[i];
		}
	}

	return result.getName();
}

template<size_t N>
std::string calculateMostPeoplePerFloor(std::array<Building, N> input)
{
	Building result = input[0];

	for (int i = 1; i < N; i++)
	{
		double resultPeoplePerFloor = (double)result.getNumberOfEmployees() / result.getNumberOfFloors();
		double currentPeoplePerFloor = (double)input[i].getNumberOfEmployees() / input[i].getNumberOfFloors();

		if (currentPeoplePerFloor > resultPeoplePerFloor)
		{
			result = input[i];
		}
	}

	return result.getName();
}

template<size_t N>
std::string calculateLeastPeoplePerFloor(std::array<Building, N> input)
{
	Building result = input[0];

	for (int i = 1; i < N; i++)
	{
		double resultPeoplePerFloor = (double)result.getNumberOfEmployees() / result.getNumberOfFloors();
		double currentPeoplePerFloor = (double)input[i].getNumberOfEmployees() / input[i].getNumberOfFloors();

		if (currentPeoplePerFloor < resultPeoplePerFloor)
		{
			result = input[i];
		}
	}

	return result.getName();
}

template<size_t N>
std::string calculateMostOfficesPerFloor(std::array<Building, N> input)
{
	Building result = input[0];

	for (int i = 1; i < N; i++)
	{
		double resultOfficesPerFloor;
		double currentOfficesPerFloor; 
		
		unsigned int resultFloors = result.getNumberOfFloors();
		unsigned int currentFloors = input[i].getNumberOfFloors();

		if (result.hasRestaurant())
		{
			resultFloors--;
		} 

		if (input[i].hasRestaurant())
		{
			currentFloors--;
		}

		resultOfficesPerFloor = (double)result.getNumberOfOffices() / resultFloors;
		currentOfficesPerFloor = (double)input[i].getNumberOfOffices() / currentFloors;

		if (currentOfficesPerFloor > resultOfficesPerFloor)
		{
			result = input[i];
		}
	}

	return result.getName();
}

template<size_t N>
std::string calculateLeastOfficesPerFloor(std::array<Building, N> input)
{
	Building result = input[0];

	for (int i = 1; i < N; i++)
	{
		double resultOfficesPerFloor;
		double currentOfficesPerFloor;

		unsigned int resultFloors = result.getNumberOfFloors();
		unsigned int currentFloors = input[i].getNumberOfFloors();

		if (result.hasRestaurant())
		{
			resultFloors--;
		}

		if (input[i].hasRestaurant())
		{
			currentFloors--;
		}

		resultOfficesPerFloor = (double)result.getNumberOfOffices() / resultFloors;
		currentOfficesPerFloor = (double)input[i].getNumberOfOffices() / currentFloors;

		if (currentOfficesPerFloor < resultOfficesPerFloor)
		{
			result = input[i];
		}
	}

	return result.getName();
}

template<size_t N>
std::string calculateMostPeoplePerOffice(std::array<Building, N> input)
{
	Building result = input[0];

	for (int i = 1; i < N; i++)
	{
		double resultPeoplePerFloor = (double)result.getNumberOfEmployees() / result.getNumberOfOffices();
		double currentPeoplePerFloor = (double)input[i].getNumberOfEmployees() / input[i].getNumberOfOffices();

		if (currentPeoplePerFloor > resultPeoplePerFloor)
		{
			result = input[i];
		}
	}

	return result.getName();
}

template<size_t N>
std::string calculateLeastPeoplePerOffice(std::array<Building, N> input)
{
	Building result = input[0];

	for (int i = 1; i < N; i++)
	{
		double resultPeoplePerFloor = (double)result.getNumberOfEmployees() / result.getNumberOfOffices();
		double currentPeoplePerFloor = (double)input[i].getNumberOfEmployees() / input[i].getNumberOfOffices();

		if (currentPeoplePerFloor < resultPeoplePerFloor)
		{
			result = input[i];
		}
	}

	return result.getName();
}

template<size_t N>
void printBuildingStatistics(std::array<Building, N> buildings)
{
	std::cout << "Most employees: " << calculateMostEmployees(buildings) << std::endl;
	std::cout << "Most free working seats: " << calculateMostFreeWorkingSeats(buildings) << std::endl;
	std::cout << "Highest coefficient employees/(employees + free seats): " << calculateHighestCoefficient(buildings) << std::endl;
	std::cout << "Most people per floor: " << calculateMostPeoplePerFloor(buildings) << std::endl;
	std::cout << "Least people per floor: " << calculateLeastPeoplePerFloor(buildings) << std::endl;
	std::cout << "Most offices per floor: " << calculateMostOfficesPerFloor(buildings) << std::endl;
	std::cout << "Least offices per floor: " << calculateLeastOfficesPerFloor(buildings) << std::endl;
	std::cout << "Most people per office: " << calculateMostPeoplePerOffice(buildings) << std::endl;
	std::cout << "Least people per office: " << calculateLeastPeoplePerOffice(buildings) << std::endl;
	std::cout << std::endl;
}

int main()
{
	Building xyzIndustries = Building("XYZ industries", 6, 127, 600, 196);
	Building rapidDevelopmentCrew = Building("Rapid Development Crew", 8, 210, 822, 85, true);
	Building softUni = Building("SoftUni", 11, 106, 200, 60);

	std::array<Building, 3> businessPark = { xyzIndustries, rapidDevelopmentCrew, softUni };

	printBuildingStatistics(businessPark);

	return 0;
}