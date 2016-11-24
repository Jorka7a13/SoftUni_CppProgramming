#include "utility.h"
#include <mutex>
#include <iomanip>
#include <ctime>
#include <math.h>
#include <iostream>
using namespace std;

namespace utility
{
	std::mutex mutex;

	void printPrimeNumbers()
	{
		clock_t start;
		double duration;

		unsigned long long i = 2;
		unsigned long long oldPrime = 2;

		mutex.lock();
		cout << fixed << setprecision(1) << "Prime " << 1 << ", " << 0.0 << " ms." << endl;
		mutex.unlock();

		while (true)
		{
			start = clock();
			bool prime = true;

			if (i < oldPrime)
			{
				mutex.lock();
				cout << "Output for prime numbers is too large!" << endl;
				mutex.unlock();
				break;
			}

			for (unsigned long long j = 2; j * j <= i; j++)
			{
				if (i % j == 0)
				{
					prime = false;
					break;
				}
			}

			if (prime)
			{
				duration = (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000);
				mutex.lock();
				cout << "Prime " << i << ", " << duration << " ms." << endl;
				mutex.unlock();
				
				oldPrime = i;
			}

			i++;
		}
	}

	void printFibonacciNumbers()
	{
		clock_t start;
		double duration;

		unsigned long long firstTerm = 1;
		unsigned long long secondTerm = 1;
		unsigned long long nextTerm = firstTerm;
		unsigned long long oldNextTerm = nextTerm;

		mutex.lock();
		cout << fixed << setprecision(1) << "Fibonacci " << nextTerm << ", " << 0.0 << " ms." << endl;
		mutex.unlock();

		while (true)
		{
			start = clock();

			nextTerm = firstTerm + secondTerm;
			firstTerm = secondTerm;
			secondTerm = nextTerm;

			if (nextTerm < oldNextTerm)
			{
				mutex.lock();
				cout << "Output for fibonacci numbers is too large!" << endl;
				mutex.unlock();
				break;
			}

			oldNextTerm = nextTerm;

			duration = (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000);
			mutex.lock();
			cout << "Fibonacci " << nextTerm << ", " << duration << " ms." << endl;
			mutex.unlock();
		}
	}
}