#include "../headers/general_header.h"

// constructor for none argument
HugeInt::HugeInt() : INT(EMPTY_NUMBER), STR(EMPTY_STRING) {
}

// constructor for int argument
HugeInt::HugeInt(int arg) : INT(arg), STR(DEFAULT_STRING) {
}

// constructor for string argument
HugeInt::HugeInt(string arg) : INT(DEFAULT_NUMBER), STR(arg) {
	bool isNumber = isNormalInteger(arg);
	
	if (isNumeric(arg)) {
		if (isNumber) {
			INT = stoi(arg);
			STR = DEFAULT_STRING;
		} else if (!isNumber) {
			INT = BIG_NUMBER;
		} else {
			print("bad case, improve your code!");
		}
	} else {
		print("\nwrong string => %\n", arg);
		INT = FAILURE_INT;
		STR = FAILURE_STRING;
	}
}

// copy constructor
HugeInt::HugeInt(const HugeInt &hi) : INT(hi.INT), STR(hi.STR) {
}

// destructor
HugeInt ::~HugeInt() {
}
