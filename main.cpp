#include "./headers/general_header.h"

/*
Implement a class which enables us to store and make arithmetic operations (+, *) upon
integers of huge sizes (several hundreds of digits long).
*/
int main() {
	// generateAllTestCases();
	string bigStr = generateBigString(9, "1234567890");
	HugeInt A;
	HugeInt B(MAX);
	HugeInt C(MIN);
	HugeInt D(bigStr);
    // HugeInt E("text");

	// cin >> A;
	// A = power(A, times);
	// B = power(B, times);
	// cout << "b = " << B << endl;

	cout.precision(5);

	cout << operationTime(B, C, '*') << endl;
	cout << operationTime(B, D, '+') << endl;
	cout << operationTime(B, bigStr, '*') << endl;
}