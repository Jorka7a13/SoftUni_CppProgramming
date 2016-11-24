#include "utility.h"
#include <thread>  

int main()
{
	std::thread primeThread(utility::printPrimeNumbers);
	std::thread fibonacciThread(utility::printFibonacciNumbers);
	
	primeThread.join();
	fibonacciThread.join();

	return 0;
}