#include <iostream>
#include <vector>
#include <cmath>

std::vector<int> findFirstNPrimes(int N)
{
    if (N <= 0)
        return {};

    // Estimate upper bound for prime numbers (n ln n + n ln ln n)
    int limit = static_cast<int>(N * (log(N) + log(log(N)))) + 1000;
    std::vector<bool> sieve(limit + 1, false);

    if (limit >= 2)
        sieve[2] = true;
    if (limit >= 3)
        sieve[3] = true;

    for (int x = 1; x * x <= limit; ++x)
    {
        for (int y = 1; y * y <= limit; ++y)
        {
            int n = 4 * x * x + y * y;
            if (n <= limit && (n % 12 == 1 || n % 12 == 5))
            {
                sieve[n] = !sieve[n];
            }

            n = 3 * x * x + y * y;
            if (n <= limit && n % 12 == 7)
            {
                sieve[n] = !sieve[n];
            }

            n = 3 * x * x - y * y;
            if (x > y && n <= limit && n % 12 == 11)
            {
                sieve[n] = !sieve[n];
            }
        }
    }

    for (int r = 5; r * r <= limit; ++r)
    {
        if (sieve[r])
        {
            for (int i = r * r; i <= limit; i += r * r)
            {
                sieve[i] = false;
            }
        }
    }

    std::vector<int> primes;
    for (int p = 2; p <= limit && primes.size() < N; ++p)
    {
        if (sieve[p])
        {
            primes.push_back(p);
        }
    }

    return primes;
}

int main()
{
    const int N = 10001;
    std::vector<int> primes = findFirstNPrimes(N);

    std::cout << "The first " << N << " primes are:\n";
    for (int i = 0; i < primes.size(); ++i)
    {
        std::cout << primes[i] << " ";
        if ((i + 1) % 10 == 0)
            std::cout << "\n"; // Print 10 per line
    }

    std::cout << "\n\nThe 10,001st prime is: " << primes.back() << "\n";
    return 0;
}