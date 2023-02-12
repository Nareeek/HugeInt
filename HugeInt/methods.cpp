#include "../headers/general_header.h"

string HugeInt::getNumber() const {
	if (isNumeric(this->STR)) {
		return (this->STR);
	} else {
		string number = turn_into_a_string(this->INT);
		if (isNumeric(number)) {
			return number;
		}
		return ("not a numeric string");
	}
}