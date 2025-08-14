#include <iostream>
#include <string>
#include <boost/multiprecision/cpp_int.hpp>

using namespace boost::multiprecision;

int factorialDigitSum(int n) {
    cpp_int factorial = 1;
    for (int i = 1; i <= n; ++i) {
        factorial *= i;
    }

    // Sum the digits
    std::string digits = factorial.str();
    int sum = 0;
    for (char c : digits) {
        sum += (c - '0');
    }

    return sum;
}

int main() {
    int n = 100;
    std::cout << "Sum of digits in " << n << "! = " << factorialDigitSum(n) << "\n";
    return 0;
}