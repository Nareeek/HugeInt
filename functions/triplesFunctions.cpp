#include "../headers/general_header.h"

string sumTriples(const string &arg1, const string &arg2, const int &arg3) {
	assert (!isNumeric(arg1) || !isNumeric(arg2) == false);
	string result = to_string(stoi(arg1) + stoi(arg2) + arg3);
	if (result.length() != 3) {
		result = concatString("0", 3 - result.length()) + result;
	}
	return result;
}

string subtractTriples(const string &arg1, const string &arg2) {
	assert (!isNumeric(arg1) || !isNumeric(arg2) == false);
	return to_string(stoi(arg1) - stoi(arg2));
}

string concatTriples(const vector<string>& vec, string& head) {
	for (auto& element : vec) {
		head += element;
	}
	return head;
}