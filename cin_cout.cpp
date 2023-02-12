#include "./headers/general_header.h"

// cout operation
ostream &operator<<(ostream &os, const HugeInt &hi) {
	if (hi.INT == BIG_NUMBER) {
		os << "number (str) = " << hi.STR;
	} else {
		os << "number (int) = " << hi.INT;
	}
	return os;
}

// cin operation
istream &operator>>(istream &is, HugeInt &hi) {
	string str;
	int i;
	
	try {
		print("Type a number");
		getline(is, str);
	} catch (const invalid_argument &ia) {
		print("\ninvalid argument exception %\n", ia.what());
		is.clear();
		return is;
	} catch (exception &ex) {
		cerr << ex.what() << endl;
	} catch (...) {
		cerr << "Caught unknown exception." << endl;
	}

	if (!isNumeric(str)) {
		print("\nbad input => %;", str);
		hi.INT = FAILURE_INT;
		hi.STR = FAILURE_STRING;
		is.clear();
		return is;
	}

	if (isNormalInteger(str)) {
		i = stoi(str);
		hi.INT = i;
		hi.STR = DEFAULT_STRING;
	} else {
		hi.INT = BIG_NUMBER;
		hi.STR = str;
	}
	return is;
}