// Georgi Tachev
// SoftUni username: Jorka7a13

#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <iostream>

std::vector<std::string> splitStringByDelimiter(const std::string &input, char delimiter)
{
	std::vector<std::string> result;

	std::stringstream stringStream(input);
	std::string token;

	while (getline(stringStream, token, delimiter)) {
		result.push_back(token);
	}

	return result;
}

unsigned short findLargestValueInMap(std::map<std::string, unsigned char> &map)
{
	std::map<std::string, unsigned char>::iterator iterator = map.begin();

	unsigned char largestValue = iterator->second;

	for (iterator = map.begin(); iterator != map.end(); iterator++) {
		if (iterator->second > largestValue)
		{
			largestValue = iterator->second;
		}
	}

	return largestValue;
}

std::vector<std::string> getAllKeysByValue(std::map<std::string, unsigned char> & map, unsigned char value)
{
	std::vector<std::string> result;

	std::map<std::string, unsigned char>::iterator iterator = map.begin();

	for (iterator = map.begin(); iterator != map.end(); iterator++) {
		if (iterator->second == value)
		{
			result.push_back(iterator->first);
		}
	}

	return result;
}

unsigned char getLargestElement(std::vector<std::string> vector)
{
	unsigned char largestElement = std::stoi(vector[0]);

	for (int i = 0; i < vector.size(); i++)
	{
		unsigned char currentElement = std::stoi(vector[i]);

		if (currentElement > largestElement)
		{
			largestElement = currentElement;
		}
	}

	return largestElement;
}

int main()
{
	std::string inputString;
	std::getline(std::cin, inputString);
	std::vector<std::string> inputVector = splitStringByDelimiter(inputString, ' ');

	std::map<std::string, unsigned char> countMap; // A collection that will be counting the occurances.

	for (int i = 0; i < inputVector.size(); i++)
	{
		std::string key = inputVector[i];

		if (countMap.count(key)) // Checks wether the key already exists in the map.
		{
			countMap[key]++;
		}
		else
		{
			countMap.insert({ key, 1 }); // Value 1 is set because as of now this new key has 1 occurance.
		}
	}

	unsigned short largestValueInMap = findLargestValueInMap(countMap);
	std::vector<std::string> resultVector = getAllKeysByValue(countMap, largestValueInMap);

	std::cout << (int)getLargestElement(resultVector) << std::endl;

	return 0;
}