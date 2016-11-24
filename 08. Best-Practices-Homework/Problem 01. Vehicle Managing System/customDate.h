#ifndef CUSTOM_DATE_H
#define CUSTOM_DATE_H
#pragma once

#include <string>
#include <vector>

class CustomDate 
{
private:
	unsigned short int day_;
	unsigned short int month_;
	unsigned short int year_;

	std::vector<std::string> splitStringByDelimeter(std::string input, char delimeter);
	bool isYearLeap(unsigned short int year);
public:
	CustomDate();
	CustomDate(unsigned short int day, unsigned short int month, unsigned short int year);
	CustomDate(std::string date);
	
	std::string getDate();
};

#endif