# HugeInt

HugeInt is a C++ program that provides a data structure for storing and performing **addition** and **multiplication** operations on integers of arbitrarily large sizes, ranging from tens to hundreds of digits long. With HugeInt, you can easily perform these arithmetic operations on large integers using familiar C++ syntax.

In addition to the core data structure and arithmetic operations, HugeInt also provides convenient input/output functions, error handling, and other useful utilities to make working with large numbers as straightforward and painless as possible. Whether you're working on a personal project or a professional application that requires handling of large integer values, HugeInt can save you time and effort by simplifying the process of working with these values.


## Usage

To use HugeInt, run the `HugeInt` executable and choose the operation you want to perform.

```cpp
#include "HugeInt.h"
#include <iostream>

int main() {
    // Create two HugeInt objects and perform addition and multiplication
    HugeInt a("12345678901234567890");
    HugeInt b("98765432109876543210");
    HugeInt sum = a + b;
    HugeInt product = a * b;

    // Output the results
    std::cout << "The sum is: " << sum << std::endl;
    std::cout << "The product is: " << product << std::endl;

    // Handle corner cases
    try {
        HugeInt c("12345a67890"); // Invalid input (contains non-numeric characters)
    } catch (std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try {
        HugeInt d("12345678901234567890123456789012345678901234567890123456789012345678901234567890"); // If input too large
    } catch (std::out_of_range& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}

