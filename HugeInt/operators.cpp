#include "../headers/general_header.h"

// = operation
HugeInt HugeInt::operator=(const HugeInt &hi) {
	if (&hi == this) {
		return *this;
	}
	
	// for big and normal number
	if (hi.INT != FAILURE_INT) {
		INT = hi.INT;
		STR = hi.STR;
	} else
		print(" = operator didn't change int and string values");
	return *this;
}

// + operation
HugeInt HugeInt ::operator+(const HugeInt &hi) const {
	if (this->INT == FAILURE_INT || hi.INT == FAILURE_INT) {
		checkingNumbers(this->INT, hi.INT);
	} else if (this->INT == BIG_NUMBER || hi.INT == BIG_NUMBER) {
		return multiplyOrSumBigNumbers(this->INT, hi.INT, this->STR, hi.STR, sumTwoNumericStirng);
	} else {
		return normalOperation(this->INT, hi.INT, sumTwoNumericStirng, true);
	}
	return HugeInt("error+");
}

// * operation
HugeInt HugeInt ::operator*(const HugeInt &hi) const {
	if (this->INT == FAILURE_INT || hi.INT == FAILURE_INT) {		
		return checkingNumbers(this->INT, hi.INT);
	} else if (this->INT == BIG_NUMBER || hi.INT == BIG_NUMBER) {		
		return multiplyOrSumBigNumbers(this->INT, hi.INT, this->STR, hi.STR, multipliesTwoNumericStirng);
	} else {
		return normalOperation(this->INT, hi.INT, multipliesTwoNumericStirng, false);
	}
	return HugeInt("error*");
}
