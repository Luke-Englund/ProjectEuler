#include <iostream>;
#include "CircularPrimes.h";
using namespace std;



void main()
{
	// Create and initiallize array containing primes under BOUND.
	int primesBelowMillion[SIZE];
	int numPrimes = initPrimes(primesBelowMillion);
	

	for (int i = 0; i < numPrimes; i++) {
		cout << primesBelowMillion[i] << "\n";
	}


	// Find the number of Circualr Primes.
	int circularPrimesBelowMillion[SIZE];
	int numCircularPrimes = findNumCircularPrimes(circularPrimesBelowMillion, primesBelowMillion, numPrimes);
	cout << numCircularPrimes << "\n";
}

int initPrimes (int primesBelowMillion[SIZE]) {
	for (int i = 0; i < SIZE; i++){
		primesBelowMillion[i] = 0;
	}

	int numPrimes = 0;
	for (int i = 0; i < BOUND - 2; i++) {
		if ( IsPrime(i+2, primesBelowMillion, numPrimes) ){
			primesBelowMillion[numPrimes] = i + 2;
			numPrimes++;
		}
	}
	return numPrimes;
}

bool IsPrime(int test, int primesBelowMillion[SIZE], int numPrimes) {
	for (int i = 0; i < numPrimes; i++) {
		if (test % primesBelowMillion[i] == 0) return false;
	}
	return true;
}

int findNumCircularPrimes (int circularPrimesBelowMillion[SIZE], int primesBelowMillion[SIZE], int numPrimes) {
	// Initiallization stuff
	for (int i = 0; i < SIZE; i ++) {
		circularPrimesBelowMillion[i] = 0;
	}
	int numCircularPrimes = 0;
	bool primeIsCircular;

	// determine
	for (int i = 0; i < numPrimes; i++) {
		primeIsCircular = true;
		int testNum = primesBelowMillion[i];

		int digits = numDigits(testNum);
		for (int j = 0; j < digits; j++) {
			int temp = testNum % 10;
			for (int k = 1; k < digits; k++) {
				temp = temp * 10;
			}
			testNum = temp + testNum / 10;
			if (!binarySearch(primesBelowMillion, numPrimes, testNum)) {
				primeIsCircular = false;
			}
			cout << testNum << ", ";
		}
		cout << primeIsCircular << "\n";
		if (primeIsCircular) {
			circularPrimesBelowMillion[numCircularPrimes] = primesBelowMillion[i];
			numCircularPrimes++;
		}
	}

	return numCircularPrimes;
}

bool binarySearch (int searchArray[SIZE], int size, int testNumber) {
	int low = 0, high = size - 1, mid = size / 2;
	if ((testNumber == searchArray[low]) || (testNumber == searchArray[high])) return true;
	while ( (mid != low) && (mid != high) ) {
		if (testNumber > searchArray[mid]) {
			low = mid;
		} else if (testNumber < searchArray[mid]) {
			high = mid;
		} else return true;
		mid = (low + high) / 2;
	}
	return false;
}

int numDigits (int num) {
	int digits = 1;
	int modder = 10;
	while ((num / modder) != 0) {
		modder = modder*10;
		digits++;
	}
	return digits;
}