#include <iostream>
#include <numeric>

inline int pythagoreanTriplets(int limit) {
    for (int m = 2; ; ++m) {
        int m_squared = m * m;
        for (int n = (m % 2 == 0) ? 1 : 2; n < m; n += 2) {
            if (std::gcd(m, n) != 1) continue;
            
            int a = m_squared - n * n;
            int b = 2 * m * n;
            int c = m_squared + n * n;
            int sum = a + b + c;
            if (sum > limit) break;
            
            if (limit % sum == 0) {
                int k = limit / sum;
                return k * k * k * a * b * c;
            }
        }
    }
}

int main() {
    int res = pythagoreanTriplets(1000);
    std::cout << res << std::endl;
    return 0;
}