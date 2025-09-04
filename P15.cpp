#include <iostream>



long long nCr(int n, int r){
    if (r < 0 || r > n) return 0;
    if(r == 0 || r == n) return 1;
    
    r = std::min(r, n -r);
    
    long long result = 1;
    for (int i = 0; i < r; ++i) {
        result = result * (n - i) / (i + 1);
    }
    return result;
}

/*
The formula for calculate for a (n-1) *(n-1) grid is
nCr(2n-2,n-1)
*/

int main() {
    int n = 21;
    long long res = nCr(2*n-2,n-1);
    std::cout << res << std::endl;
    return 0;
}