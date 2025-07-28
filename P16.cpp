#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>

int main()
{
    boost::multiprecision::cpp_int n = 1;
    n <<= 1000;

    std::string s = n.str();
    unsigned long long sum = 0;
    for (char c : s)
    {
        sum += c - '0'; // Convert char to digit
    }
    std::cout << sum << std::endl;
    return 0;
}