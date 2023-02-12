#include "./headers/general_header.h"

string sumTwoNumericStirng(const string &str1, const string &str2) {
	// if one or both are 0
	if (str1 == "0" || str2 == "0") {
		if (str1 == "0")
			return str2;
		else
			return str1;
	}
	// if two are positive
	if (str1[0] != '-' && str2[0] != '-') {
		return sumTwoPositiveNumericStrings(str1, str2);
  	}
	// if two are negative
	if (str1[0] == '-' && str2[0] == '-') {
		return "-" + sumTwoPositiveNumericStrings(str1.substr(1), str2.substr(1));
  	}

	// first -> positive, second -> negative
	if (str1[0] != '-' && str2[0] == '-') {
		return subtractTwoPositiveNumericStrings(str1, str2.substr(1));
	}

	// first -> negative, second -> positive
	if (str1[0] == '-' && str2[0] != '-') {
		return subtractTwoPositiveNumericStrings(str2, str1.substr(1));
	}
	return "+error+";
}

string multipliesTwoNumericStirng(const string &str1, const string &str2) {
	// one or both are 0
	if (str1 == "0" || str2 == "0")
		return "0";
	
	// two positive
	if (str1[0] != '-' && str2[0] != '-') {
		return multiplyTwoNumericStrings(str1, str2);
	}

	// two are negative
	if (str1[0] == '-' && str2[0] == '-') {
		return multiplyTwoNumericStrings(str1.substr(1), str2.substr(1));
	}
	
	// first -> positive, second -> negative
	if (str1[0] != '-' && str2[0] == '-') {
		return "-" + multiplyTwoNumericStrings(str1, str2.substr(1));
	}

	// first -> negative, second -> positive
	if (str1[0] == '-' && str2[0] != '-') {
		return "-" + multiplyTwoNumericStrings(str1.substr(1), str2);
	}
	return "*error*";
}