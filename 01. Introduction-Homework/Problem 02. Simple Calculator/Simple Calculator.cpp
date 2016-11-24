// Make	a program that demonstrates	all	the	functions learned in lecture 1.

#include "stdafx.h"
#include <iostream>
using namespace std;

int add(int a, int b) 
{
	return a + b;
}

int subtract(int a, int b) 
{
	return a - b;
}

int multiply(int a, int b) 
{
	return a * b;
}

float divide(int a, int b) 
{
	return (float)a / b;
}

int main()
{
	int menuSelection;
	int a, b;
	bool isRunning = true;

	cout << "This is a simple calculator!" << endl << endl;

	while (isRunning)
	{
		cout << "Please choose an option: " << endl;
		cout << "1. Addititon (+)" << endl;
		cout << "2. Subtraction (-)" << endl;
		cout << "3. Multiplication (*)" << endl;
		cout << "4. Division (/)" << endl;
		cout << "0. Exit" << endl << endl;

		cout << "Option: ";
		cin >> menuSelection;

		if (menuSelection != 0 && (menuSelection < 1 || menuSelection > 4))
		{
			cerr << menuSelection << " is an invalid option!" << endl;
		}
		else if (menuSelection == 0) 
		{
			isRunning = false;
		}
		else
		{
			cout << "Please enter two integer operands: " << endl;
			cout << "A = ";
			cin >> a;
			cout << "B = ";
			cin >> b;
			cout << endl;

			cout << "The result is ";
			switch (menuSelection)
			{
			case 1:
				cout << add(a, b) << endl;
				break;
			case 2:
				cout << subtract(a, b) << endl;
				break;
			case 3:
				cout << multiply(a, b) << endl;
				break;
			case 4:
				cout << divide(a, b) << endl;
				break;
			}

			cout << endl << endl;
		}
	}

    return 0;
}