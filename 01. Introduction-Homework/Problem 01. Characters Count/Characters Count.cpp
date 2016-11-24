// Make	a program that reads a line from the keyboard and checks how many upper	and
// lower case letters and other characters are available in	the	string.

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

int main() 
{
	int upperCaseCount = 0;
	int lowerCaseCount = 0;
	int otherCount = 0;

	string input;
	cout << "Please enter a line: ";
	getline(cin, input);

	for (char& c : input) 
	{
		if (c > 64 && c < 91)
		{
			upperCaseCount++;
		}
		else if (c > 96 && c < 123)
		{
			lowerCaseCount++;
		}
		else 
		{
			otherCount++;
		}
	}

	cout << "\nResult: " << endl; 
	cout << "Upper case letters: " << upperCaseCount << endl;
	cout << "Lower case letters: " << lowerCaseCount << endl;
	cout << "Other characters: " << otherCount << endl << endl;

    return 0;
}