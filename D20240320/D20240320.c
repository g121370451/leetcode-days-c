#include <stdio.h>
#include <math.h>
// 不等式3*5 > 1*7
//      0011 0101 0001 0111
// 0001 0010 0011 0100 0101 0110 0111
// 6*6*6*7  (2^p-1)(2^p-2)^(2^(p-1)-1) 7* 6^3
long long fastPow(long long x, long long n, long long mod) {
    long long res = 1;
    for (; n != 0; n >>= 1) {
        if (n & 1) {
            res = res * x % mod;
        }
        x = x * x % mod;
    }
    return res;
}

int minNonZeroProduct(int p) {
    if (p == 1) {
        return 1;
    }
    long long mod = 1e9 + 7;
    long long x = fastPow(2, p, mod) - 1; // 2ep -1
    long long y = (long long) 1 << (p - 1);// 2e(p-1)
    return fastPow(x - 1, y - 1, mod) * x % mod;// (2^p-2)^(2^(p-1)-1) * (2^p -1) % mod
}

int main(int argc, char const *argv[])
{
    int res = minNonZeroProduct(5);
    printf("%d", res);
    return 0;
}
