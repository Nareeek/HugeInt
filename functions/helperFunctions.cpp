#include "../headers/general_header.h"

string generateBigString(const int &times, const string customInitialString) {
  int repeat = times;
  string bigStr = "";
  while (repeat--) {
    bigStr += customInitialString;
  }
  return bigStr;
}

HugeInt power(HugeInt number, int times) {
  HugeInt result = number;

  while (times-- && result.getNumber().length() < 777) {
    result = result * number;
  }
  if (result.getNumber().length() >= 777 || times) {
    print("TODO: optimize for big numbers.");
    print("Result is too big...\n");
  }
  print("len = %\n", result.getNumber().length());
  return result;
}

double operationTime(const HugeInt &first, const HugeInt &second, const char &ch) {
  const clock_t begin_time = clock();
  switch (ch) {
	  case '*':
	  	(void)(first * second);
	  	break;
	  case '+':
	  	(void)(first + second);
	  	break;
	  default:
	  	;
  }
  return (clock() - begin_time) / (double)CLOCKS_PER_SEC;
}