#include "../headers/general_header.h"

string generateBigString(const int& times, const string customInitialString) {
	int repeat = times;
	string bigStr = "";
	while (repeat--) {
		bigStr += customInitialString;
	}
	return bigStr;
}

HugeInt power(HugeInt number, int times) {
	HugeInt result = number;
	
	while (times-- && result.getNumber().length() < 777) {
		result = result * number;
  	}
	if (result.getNumber().length() >= 777 || times) {
		print("TODO: optimize for big numbers.");
		print("Result is too big...\n");
	}
	print("len = %\n", result.getNumber().length());
	return result;
}