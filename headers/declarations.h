#pragma once

#include "includes.h"

const long long int MIN = INT_MIN;
const long long int MAX = INT_MAX;
const int BIG_NUMBER = -111;
const int DEFAULT_NUMBER = -222;
const int FAILURE_INT = -333;
const int EMPTY_NUMBER = -444;
const int MAX_TRIPLE_NUMBER = 999;
const int TRIPLE_SIZE = 3;

const string DEFAULT_STRING = "defaultString";
const string FAILURE_STRING = "failureString";
const string EMPTY_STRING = "emptyString";

bool isNumeric(const string &str);
bool isNormalInteger(const string &str);
int splitStringsAndFinalize(const string str1, const string str2, vector<string>* splittedStr1, vector<string>* splittedStr2);
vector<string> Split(const string &str, int splitLength = 3);
vector<string> finalizeStringArray(const vector<string> &str, const int size);
string concatString(string s, int n);
string prettifyString(const string& str);
string concatTriples(const vector<string>& vec, string& head);
string subtractTriples(const string &arg1, const string &arg2);
string sumTwoNumericStirng(const string &str1, const string &str2);
string multiplyTwoNumericStrings(const string& str1, const string& str2);
string multipliesTwoNumericStirng(const string &str1, const string &str2);
string sumTriples(const string &arg1, const string &arg2, const int &arg3);
string sumTwoPositiveNumericStrings(const string& str1, const string& str2);
string subtractTwoPositiveNumericStrings(const string& str1, const string& str2);
string repeatSumDigitsTime(const string& str, const int& times, const int& baseTen);
string generateBigString(const int& times, const string customInitialString = "1234567890");

void generateAllTestCases();
void chainingOperationsTest();
void multipliesTest();
void sumTest();

class HugeInt {
public:
	HugeInt();
	HugeInt(string value);
	HugeInt(int value);

	friend ostream &operator<<(ostream &os, const HugeInt &hi);
	friend istream &operator>>(istream &is, HugeInt &hi);
	
	HugeInt operator+(const HugeInt &arg) const;
	HugeInt operator*(const HugeInt &arg) const;
	
	HugeInt operator=(const HugeInt &hi);
	HugeInt(const HugeInt &hi); // copy constructor
	
	string getNumber() const;
	
	~HugeInt();

private:
	int INT;
	string STR;
};

HugeInt checkingNumbers(const int& firstNumber, const int& secondNumber);
HugeInt multiplyOrSumBigNumbers(const int& firstNumber, const int& secondNumber, const string& firstString, const string& secondString, string (*function)(const string&, const string&));
HugeInt normalOperation(const int& firstNumber, const int& secondNumber, string (*function)(const string&, const string&), bool isSum);
HugeInt power(HugeInt number, int times);