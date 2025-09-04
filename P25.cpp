#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>

int approx() {
    const double phi = (1.0 + std::sqrt(5.0)) / 2.0;
    const double log10_phi = std::log10(phi);
    const double log10_sqrt5 = std::log10(5.0) / 2.0;

    int n = 1;
    while (true) {
        double log10_fn = n * log10_phi - log10_sqrt5;
        if (log10_fn >= 999.0) {
            std::cout << n << std::endl;
            break;
        }
        n++;
    }
    return 0;
}


int main(){
    size_t i = 3000;
    approx();
    return 0;
}