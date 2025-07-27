#include <iostream>
#include <unordered_map>

using namespace std;
unsigned long long collatz(unsigned long long n, unordered_map<unsigned long long, unsigned long long>& map) {
    if (map.count(n)) {
        return map[n];
    }
    if (n == 1) {
        return 1;
    }
    unsigned long long next;
    if (n % 2 == 0) {
        next = n / 2;
    } else {
        next = 3 * n + 1;
    }
    unsigned long long length = 1 + collatz(next, map);
    map[n] = length;
    return length;
}

int main() {
    unordered_map<unsigned long long, unsigned long long> map;
    map[1] = 1;
    map[2] = 2;
    int limit = 1000000;
    unsigned long long max_length = 0;
    unsigned long long max_number = 0;
    for (int i = 3; i <= limit; i++) {
        unsigned long long length = collatz(i, map);
        if (length > max_length) {
            max_length = length;
            max_number = i;
        }
    }
    cout << "Max number: " << max_number << ", Max length: " << max_length << endl;
    return 0;
}