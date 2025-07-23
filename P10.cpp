#include <iostream>
#include <vector>
#include <cstdint>

void sieve(std::vector<bool>& prime_list) {
    for (size_t p = 2; p * p < prime_list.size(); ++p) {
        if (prime_list[p]) {
            for (size_t i = p * p; i < prime_list.size(); i += p) {
                prime_list[i] = false;
            }
        }
    }
}

int main() {
    const size_t N = 2000001;
    std::vector<bool> prime_list(N, true);

    sieve(prime_list);

    std::vector<unsigned> primes;
    primes.reserve(150000); // Preallocate memory

    for (size_t i = 2; i < prime_list.size(); ++i) {
        if (prime_list[i]) {
            primes.push_back(static_cast<unsigned>(i));
        }
    }

    uint64_t sum = 0;
    for (unsigned prime : primes) {
        sum += prime;
    }
    std::cout << sum << std::endl;

    return 0;
}