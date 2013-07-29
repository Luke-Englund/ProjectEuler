#include <iostream>
#include "CombMult.h"
using namespace std;

int main(){

	int size;
	cout << "How many turns? ";
	cin >> size;

	// Create array of "Red Disks" by turn
	int nums[100];
	for (int i = 0; i < size; i++) {
		nums[i] = i + 1;
	}

	// Determine the maximum number of failed turns
	int MaxNumFails = size / 2 - 1 + size % 2;

	// Add up all the failing probablities (numerator only).
	long long tot = 0;
	for (int i = 0; i <= MaxNumFails; i++){
		tot += CombMult(nums, size, i);
	}


	cout << tot << " / " << Fact(size + 1) << "\n";
	cout << "So the max payout should be: \n  P = (" << Fact(size + 1) << " / "  << tot << ") - 1 \n  = " << Fact(size + 1) / tot - 1 << "\n";
}

// Return the sum of the product of each combination of size "comb" from an array of size "size."
long long CombMult(int nums[15], int size, int comb){
	long long mult = 0;
	if (comb == 0){
		return 1;
	}else{
		for (int i = 0; i < size - comb + 1; i++) {
			int newNums[15];
			for (int j = 0; j < size - i - 1; j++){
				newNums[j] = nums[i + j + 1];
			}
			mult += nums[i] * CombMult(newNums, size - i - 1, comb - 1);
		}
	}
	return mult;
}

// Factorial function.
long long Fact(int currentNum) {
	if (currentNum == 0) {
		return 1;
	} else {
		return currentNum * Fact(currentNum - 1);
	}
}