#include "customDate.h"
#include <sstream>

CustomDate::CustomDate()
{
	day_ = 0;
	month_ = 0;
	year_ = 0;
}

CustomDate::CustomDate(unsigned short int day, unsigned short int month, unsigned short int year)
{
	unsigned short int numberOfDaysByMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (isYearLeap(year))
	{
		numberOfDaysByMonth[1] = 29;
	}

	year_ = year;

	if (month <= 12)
	{
		month_ = month;
	}
	else
	{
		month_ = 0;
	}

	if (day <= numberOfDaysByMonth[month - 1] && month <= 12)
	{
		day_ = day;
	}
	else
	{
		day_ = 0;
	}
}

CustomDate::CustomDate(std::string date)
{
	unsigned short int day = 0;
	unsigned short int month = 0;
	unsigned short int year = 0;

	std::vector<std::string> input = splitStringByDelimeter(date, '.');

	if (std::stoi(input[0]) < std::numeric_limits<unsigned short int>::max())
	{
		day = std::stoi(input[0]);
	}

	if (std::stoi(input[1]) < std::numeric_limits<unsigned short int>::max())
	{
		month = std::stoi(input[1]);
	}

	if (std::stoi(input[2]) < std::numeric_limits<unsigned short int>::max())
	{
		year = std::stoi(input[2]);
	}

	unsigned short int numberOfDaysByMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (isYearLeap(year))
	{
		numberOfDaysByMonth[1] = 29;
	}

	year_ = year;

	if (month <= 12)
	{
		month_ = month;
	}
	else
	{
		month_ = 0;
	}

	if (day <= numberOfDaysByMonth[month - 1] && month <= 12)
	{
		day_ = day;
	}
	else
	{
		day_ = 0;
	}
}

std::string CustomDate::getDate()
{
	std::string day = std::to_string(day_);
	std::string month = std::to_string(month_);
	std::string year = std::to_string(year_);

	if (day_ < 10)
	{
		day = "0" + day;
	} 

	if (month_ < 10)
	{
		month = "0" + month;
	}

	if (year_ < 10)
	{
		year = "0" + year;
	}

	return day + "." + month + "." + year;
}

std::vector<std::string> CustomDate::splitStringByDelimeter(std::string input, char delimeter)
{
	std::stringstream inputStringStream(input);
	std::string segment;
	std::vector<std::string> result;

	while (std::getline(inputStringStream, segment, delimeter))
	{
		result.push_back(segment);
	}

	return result;
}

bool CustomDate::isYearLeap(unsigned short int year)
{
	if (year % 400 == 0)
	{
		return true;
	}
	else if (year % 100 == 0)
	{
		return false;
	}
	else if (year % 4 == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}