#include "../headers/general_header.h"


bool isNumeric(const string &str) {
	string checkedString = str;
	if (str == "")
		return false;
	else if (str[0] == '-')
		checkedString = str.substr(1);
	for (char const &c : checkedString)
		if (isdigit(c) == 0)
			return false;
	return true;
}

bool isNormalInteger(const string &str) {
	try {
		if (!isNumeric(str))
			throw runtime_error("Not a number!");
		stoi(str);
	} catch (const out_of_range &oor) {
		// print("out of range exception | % | %", str, oor.what());
		return false;
	} catch (const invalid_argument &ia) {
		print("other exception... | % | % |", str, ia.what());
		return false;
	} catch (exception &e) {
		// print("Exception %", e.what());
		return false;
	} catch (...) {
		cerr << "Caught unknown exception." << endl;
		return false;
	}
	return true;
}

HugeInt checkingNumbers(const int& firstNumber, const int& secondNumber) {
	// print("either(both) isn't a number");
	if (firstNumber == FAILURE_INT && secondNumber == FAILURE_INT)
		return HugeInt(0);
	else if (firstNumber == FAILURE_INT && secondNumber != FAILURE_INT)
		return HugeInt(secondNumber);
	else if (firstNumber != FAILURE_INT && secondNumber == FAILURE_INT)
		return HugeInt(firstNumber);
	else {
		print("Unexpected case");
		exit(__LINE__);
	}
}

HugeInt multiplyOrSumBigNumbers(const int& firstNumber, const int& secondNumber, const string& firstString, 	const string& secondString, string (*function)(const string&, const string&)) {
	if (firstNumber == BIG_NUMBER && secondNumber == BIG_NUMBER) {
		string result = function(firstString, secondString);
		return HugeInt(result);
	} else if (firstNumber == BIG_NUMBER) {
		string result = function(firstString, turn_into_a_string(secondNumber));
		return HugeInt(result);
	} else if (secondNumber == BIG_NUMBER) {
		string result = function(turn_into_a_string(firstNumber), secondString);
		return HugeInt(result);
	}
	return HugeInt("unexpected case");
}
