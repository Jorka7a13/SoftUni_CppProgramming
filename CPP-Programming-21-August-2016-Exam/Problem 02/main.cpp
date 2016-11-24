// Georgi Tachev
// SoftUni username: Jorka7a13

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <math.h>

struct Roots
{
	float x1;
	float x2;
};

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

Roots solveQuadraticEquation(int a, int b, int c)
{
	Roots roots;

	float determinant = b*b - 4 * a*c;

	if (determinant > 0)
	{
		roots.x1 = (-b + std::sqrt(determinant)) / (2 * a);
		roots.x2 = (-b - std::sqrt(determinant)) / (2 * a);
	}
	else if (determinant == 0)
	{
		roots.x1 = roots.x2 = (-b + sqrt(determinant)) / (2 * a);
	}
	else
	{
		roots.x1 = roots.x2 = NAN;
	}

	return roots;
};

int main()
{
	//std::string inputString;
	//std::getline(std::cin, inputString);
	//std::vector<std::string> inputVector = splitStringByDelimiter(inputString, ' ');

	//int a = stoi(inputVector[0]);
	//int b = stoi(inputVector[1]);
	//int c = stoi(inputVector[2]);

	//Roots result = solveQuadraticEquation(a, b, c);

	//if (result.x1 != result.x1) // Check if roots are NAN.
	//{
	//	std::cout << "nan,nan" << std::endl; // Format output for NAN values.
	//}
	//else
	//{
	//	printf("%0.2f,%0.2f\n", result.x1, result.x2);
	//}

	//return 0;
}