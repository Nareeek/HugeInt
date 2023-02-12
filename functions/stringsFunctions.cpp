#include "../headers/general_header.h"

string concatString(string s, int n) {
	string s1 = s;
	
	for (int i = 1; i < n; i++)
		s += s1;
	if (n <= 0) {
		return "";
	}
	return s;
}

vector<string> finalizeStringArray(const vector<string> &strArr, const int destSize) {
	vector<string> result;
	int addLen = 0;
	int arrLen = strArr.size();
	string triple = concatString("0", TRIPLE_SIZE);
	
	if (arrLen < destSize) {
		addLen = destSize - arrLen;
	while (addLen--)
		result.push_back(triple);
		result.insert(result.end(), strArr.begin(), strArr.end());
	} else {
		result = strArr;
	}
	return result;
}

int splitStringsAndFinalize(const string str1, const string str2, vector<string>* splittedStr1, vector<string>* splittedStr2) {
	int maxSize = 0;
	
	*splittedStr1 = Split(str1);
    *splittedStr2 = Split(str2);
    maxSize = (*splittedStr1).size() >= (*splittedStr2).size() ? (*splittedStr1).size()
                                                         : (*splittedStr2).size();
    *splittedStr1 = finalizeStringArray(*splittedStr1, maxSize);
    *splittedStr2 = finalizeStringArray(*splittedStr2, maxSize);
	return maxSize;
}

string subtractTwoPositiveNumericStrings(const string& str1, const string& str2) {
	if (str1 == str2) {
	return "0";
	}
	vector<string> splittedStr1;
	vector<string> splittedStr2;
	vector<string> resultStr;
	
	string pairSubtraction = "";
	string head = "";
	int number;
	int maxSize = 0;

	maxSize = splitStringsAndFinalize(str1, str2, &splittedStr1, &splittedStr2);
    for (auto i = maxSize - 1; i >= 0; --i) {
		pairSubtraction = subtractTriples(splittedStr1[i], splittedStr2[i]);
		number = stoi(pairSubtraction);
		if (number < 0) {
			pairSubtraction = pairSubtraction.substr(1);
		}
		resultStr.insert(resultStr.begin(), pairSubtraction);
		if (i == 0) {
			if (number < 0) {
				head += "-";
			}
			if (pairSubtraction.length() != 3) {
				head += concatString("0", 3 - pairSubtraction.length());;
			}
		}
	}
	return concatTriples(resultStr, head);
}

string multiplyTwoNumericStrings(const string& str1, const string& str2) {
	int baseTen = 0;
	int digit = 0;
	string oneTimeResult = "";
	string result = "0";
	string letter = "";

	for (int i = str1.size() - 1; i >= 0; --i) {
		letter = str1[i];
		digit = stoi(letter);
		oneTimeResult = repeatSumDigitsTime(str2, digit, baseTen);
		result = sumTwoPositiveNumericStrings(result, oneTimeResult);
		baseTen++;
	}
	return result;
}

string sumTwoPositiveNumericStrings(const string& str1, const string& str2) {
	vector<string> splittedStr1;
	vector<string> splittedStr2;
	vector<string> resultStr;
	
	string pairSum = "";
	string head = "";
	string result = "";
	int remainder = 0;
	int number;
	int maxSize = 0;

	maxSize = splitStringsAndFinalize(str1, str2, &splittedStr1, &splittedStr2);
    for (auto i = maxSize - 1; i >= 0; --i) {
		pairSum = sumTriples(splittedStr1[i], splittedStr2[i], remainder);
		number = stoi(pairSum);
		remainder = 0;
		if (number > MAX_TRIPLE_NUMBER) {
			remainder = 1;
			pairSum = pairSum.substr(2, 3);
		}
		resultStr.insert(resultStr.begin(), pairSum);
		if (i == 0) {
			if (number > MAX_TRIPLE_NUMBER) {
				resultStr.insert(resultStr.begin(), concatString("0", 2) + turn_into_a_string(remainder));
			}
			else if (pairSum.length() != 3) {
				head += concatString("0", 3 - pairSum.length());;
			}
		}
	}
	result = concatTriples(resultStr, head);
	result = prettifyString(result);
	return result;
}

string prettifyString(const string& str){
	if (str.substr(0, 3) == "000") {
		return str.substr(3);
	}
	return str;
}
