const int BOUND = 1000000;
const int SIZE = 78500;

bool IsPrime(int test, int primesBelowMillion[1000000 - 1], int numPrimes);
int initPrimes (int primesBelowMillion[SIZE]);
bool binarySearch (int searchArray[SIZE], int size, int testNumber);
int numDigits (int num);
int findNumCircularPrimes (int circularPrimesBelowMillion[SIZE], int primesBelowMillion[SIZE], int numPrimes);