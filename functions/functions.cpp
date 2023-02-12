#include "../headers/general_header.h"

vector<string> Split(const string &str, int splitLength) {
	vector<string> ret;
	int headSize = splitLength - str.length() % splitLength;
	string head = concatString("0", headSize);
	string firstPart = head + str.substr(0, splitLength - headSize);
	auto i = 0;
	
	if (headSize != splitLength) {
		ret.push_back(firstPart);
		i += (splitLength - headSize);
	}
	for (; i < str.size(); i += splitLength) {
		ret.push_back(str.substr(i, splitLength));
	}
	return ret;
}

string repeatSumDigitsTime(const string& str, const int& times, const int& baseTen) {
	string result = str;
	string tail = concatString("0", baseTen);

	if (times == 0) {
		return "0";
	}
	
	for (int i = 1; i < times; ++i) {
		result = sumTwoPositiveNumericStrings(result, str);
	}
	return result + tail;
}

HugeInt normalOperation(const int& firstNumber, const int& secondNumber, string (*function)(const string&, const string&), bool isSum) {
	if (firstNumber == 0 || secondNumber == 0) {
		if (isSum) {
			return HugeInt(firstNumber + secondNumber);
		} else {
			return HugeInt(firstNumber * secondNumber);
		}
    } else if (firstNumber > 0 && secondNumber > 0) {		
		if (isSum) {			
			if (secondNumber >= (MAX - firstNumber)) {
				string result = function(turn_into_a_string(firstNumber), turn_into_a_string(secondNumber));
				return HugeInt(result);
			} else
				return HugeInt(firstNumber + secondNumber);
		} else {			
			if (secondNumber >= (MAX / firstNumber)) {				
				string result = function(turn_into_a_string(firstNumber), turn_into_a_string(secondNumber));
				return HugeInt(result);
			} else {				
				return HugeInt(firstNumber * secondNumber);
			}
		}
    } else if (firstNumber < 0 && secondNumber < 0) {
		if (isSum) {
			if (secondNumber <= (MIN - firstNumber)) {
				string result = function(turn_into_a_string(firstNumber), turn_into_a_string(secondNumber));
				return HugeInt(result);
			}
			return HugeInt(firstNumber + secondNumber);			
		} else {
			if (secondNumber <= (MAX / firstNumber)) {
				string result = function(turn_into_a_string(firstNumber), turn_into_a_string(secondNumber));
				return HugeInt(result);
			} else
				return HugeInt(firstNumber * secondNumber);
		}
    } else if (firstNumber < 0 || secondNumber < 0) {
		if (isSum) {
	      	return HugeInt(firstNumber + secondNumber);
		} else {
	      	return HugeInt(firstNumber * secondNumber);
		}
    } else {
		print("unexpected operations for | % | %\n", firstNumber, secondNumber);
	}	
	return HugeInt("error");
}