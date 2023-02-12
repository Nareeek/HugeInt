#pragma once

#include <cassert>
#include <climits>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

template <typename T>
void print(T format) {
  cout << format << endl;
}

template <typename T, typename... Args>
void print(const char *format, T value, Args... args) {
  for (; *format != '\0'; format++) {
    if (*format == '%') {
      cout << value;
      print(format + 1, args...);
      return;
    }
    cout << *format;
  }
  cout << endl;
}

template <typename ValueType>
string turn_into_a_string(ValueType v) {
  ostringstream oss;
  oss << v;
  return oss.str();
}
