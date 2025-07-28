#include <string>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>
#include <algorithm> // For std::reverse

namespace fs = std::filesystem;

std::string sum_large_numbers(const std::vector<std::string> &numbers)
{
    size_t max_len = 0;
    for (const auto &num : numbers)
    {
        if (num.length() > max_len)
        {
            max_len = num.length();
        }
    }

    std::string result;
    int carry = 0;

    for (int pos = 0; pos < max_len || carry > 0; pos++)
    {
        int digit_sum = carry;

        for (const auto &num : numbers)
        {
            int num_pos = num.length() - 1 - pos;
            if (num_pos >= 0)
            {
                digit_sum += num[num_pos] - '0';
            }
        }

        carry = digit_sum / 10;
        result.push_back((digit_sum % 10) + '0');
    }

    std::reverse(result.begin(), result.end());
    return result;
}

int main()
{
    fs::path file_path = "doc/P13.txt";
    if (!fs::exists(file_path))
    {
        std::cerr << "File not found\n";
        return 1;
    }

    std::ifstream file(file_path);
    if (!file.is_open())
    {
        std::cerr << "Cannot open file\n";
        return 1;
    }

    std::vector<std::string> numbers;
    std::string line;

    while (std::getline(file, line))
    {
        numbers.push_back(line);
    }

    std::string total_sum = sum_large_numbers(numbers);
    std::string first_10_digits = total_sum.substr(0, 10);

    std::cout << "First 10 digits of sum: " << first_10_digits << std::endl;
    return 0;
}