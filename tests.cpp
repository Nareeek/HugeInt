#include "./headers/general_header.h"

void generateAllTestCases() {
	sumTest();
	multipliesTest();
	chainingOperationsTest();
}

void sumTest() {
	long long a = 1234567890;
	long long b = 1234567890;
	string c = to_string(a + b);
	HugeInt A(a);
	HugeInt B(b);
	string C = (A + B).getNumber();
	print("c = %, C = %\n\n", c , C);
	print("sum test %", c == C);
}

void multipliesTest() {
}

void chainingOperationsTest() {
}
