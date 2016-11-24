#include "utility.h"
#include "character.h"
#include "environment.h"

#include <iostream>
using namespace std;

int main()
{
	string result;

	Character neil = Character(2, "Neil Armstrong", 80, 12);
	Environment theMoon = Environment(2, "the Moon", 1.63);

	cout << neil.getName() << " jumps at height of ";
	printf("%.2f meters", utility::calculateMaxJumpHeight(neil, theMoon));
	printf(" for %.2f", utility::calculateJumpTime(neil, theMoon));
	cout << " seconds on " << theMoon.getName() << "." << endl;
	cout << endl;

	Character sam = Character(1, "Samwise", 150, 10); // "Stupid fat hobbit!"
	Environment middleEarth = Environment(1, "Middle Earth", 9.81);

	cout << sam.getName() << " jumps at height of ";
	printf("%.2f meters", utility::calculateMaxJumpHeight(sam, middleEarth));
	printf(" for %.2f", utility::calculateJumpTime(sam, middleEarth)); 
	cout << " seconds in " << middleEarth.getName() << "." << endl;
	cout << endl;

	cout << "Can " << sam.getName() << " jump over a 1 meter high rock? - ";
	if (utility::canCharacterJump(sam, middleEarth, 1))
	{
		result = "Yes";
	} 
	else
	{
		result = "No";
	}
	cout << result << "." << endl;
	cout << endl;

	cout << "Can " << sam.getName() << " jump over a 2 meter high bush? - ";
	if (utility::canCharacterJump(sam, middleEarth, 2))
	{
		result = "Yes";
	}
	else
	{
		result = "No";
	}
	cout << result << "." << endl;
	cout << endl;

	return 0;
}