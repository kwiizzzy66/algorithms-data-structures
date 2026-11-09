// способ 1
#include <iostream>
long long fastPow(long long base, long long exp) {
    long long result = 1;
    while (exp > 0) {
        if (exp & 1) {          
            result *= base;     
        }
        base *= base; 
        exp >>= 1;              
    }
    return result;
}

int main() {
    long long a, n;
    std::cin >> a >> n;
    std::cout << fastPow(a, n) << std::endl;
    return 0;
}

// способ 2
long long fastPow(long long base, long long exp) {
    if (exp == 0) return 1;
    if (exp % 2 == 0) {
        long long half = fastPow(base, exp / 2);
        return half * half;
    }
    return base * fastPow(base, exp - 1);
}