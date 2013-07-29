#include <iostream>
#include "RobotWalk.h"

using namespace std;

void main()
{
	int posCircle[5];
	int negCircle[5];
	for (int i = 0; i < 5; i++) {
		posCircle[i] = 0;
		negCircle[i] = 0;
	}
	int seq[SIZE];
	int total = 0;
	long long count = 0;

	int toggle = 2;
	for (int posCap = 0; posCap <= SIZE / 10; posCap ++) {
		if ((SIZE % 10 == 0) && (posCap == SIZE / 10)) toggle = 1;
		count += toggle*allSequences(posCircle, negCircle, total, SIZE, posCap);
		cout << count << "\n";
	}
	cout << count << "\n";
}

// Not needed for this method, but elegant.
/*
long long choose (long long n, long long m) {
	return (factorial(n) * factorial(n - m)) / factorial(m);
}

long long factorial (long long n) {
	if (n == 0) return 1;
	else return n * factorial (n - 1);
}
*/

long long allSequences (int posCircle[5], int negCircle[5], int total, int place, int posCap) {
	long long count = 0;
	
	if (place == 1) {
		posCircle[(total + 1 + 70) % 5]++;
		if (allElementsEqual(posCircle) && allElementsEqual(negCircle)) { 
			count++;
		}
		posCircle[(total + 1 + 70) % 5]--;

		negCircle[(total - 1 + 70) % 5]++;
		if (allElementsEqual(posCircle) && allElementsEqual(negCircle)) {
			count++;
		}
		negCircle[(total - 1 + 70) % 5]--;

		return count;
	} else {
		posCircle[(total + 1 + 70) % 5]++;
		if (!unrecoverable(posCircle, negCircle, place - 1, posCap)) {
			count += allSequences(posCircle, negCircle, total + 1, place -1, posCap);
		}
		posCircle[(total + 1 + 70) % 5]--;

		negCircle[(total - 1 + 70) % 5]++;
		if (!unrecoverable(posCircle, negCircle, place - 1, posCap)) {
			count += allSequences(posCircle, negCircle, total - 1, place -1, posCap);
		}
		negCircle[(total - 1 + 70) % 5]--;

		return count;
	}
}

bool allElementsEqual(int arr[5]) {
	for (int i = 1; i < 5; i ++) {
		if (arr[i] != arr[0]) return false;
	}
	return true;
}

bool unrecoverable(int posCircle[5], int negCircle[5], int place, int posCap) {
	for (int i = 0; i < 5; i++) {
		if (posCap < posCircle[i]) return true;
	}
	int posSum = 0;
	for (int i = 0; i < 5; i++) {
		posSum += (posCap - posCircle[i]);
	}

	int maxNeg = negCircle[0];
	for (int i = 1; i < 5; i++) {
		if (negCircle[i] > maxNeg) maxNeg = negCircle[i];
	}
	int negSum = 0;
	for (int i = 0; i < 5; i++) {
		negSum += (maxNeg - negCircle[i]);
	}

	if (((posCap + maxNeg) > SIZE / 5)) return true;
	if ((place - (posSum + negSum)) % 5 != 0) return true;
	else return false;
}