// 50求快速幂 https://leetcode.cn/problems/powx-n/description/
// 二进制 x^n => n=n1+n2+n3+... x^n = x^(n1+2*n2+3*n3+...) = x^n1 +x^(2*n2) +x^(4*n3) n1 n2 n3 为n对应二进制位0/1 然后向下递归 x^2 x^4
// 分治
//
#include <stdio.h>

double myPowDivide(double x, long long n)
{
    if (x == 1)
    {
        return x;
    }
    if (n == 0)
    {
        return 1;
    }
    double res = myPowDivide(x, n / 2);
    res = res * res;
    if (n % 2 != 0)
    {
        res *= x;
    }
    return res;
}

double myPow(double x, long long n)
{
    if (n < 0)
    {
        return 1 / myPowDivide(x, -n);
    }

    return myPowDivide(x, n);
}

int main(int argc, char const *argv[])
{
    // double res = myPow(2.00000, 10); // 1001
     double res = myPow(8.95371,-1); // 1001
    // double res = myPow(2,-2147483648); // 1001
    printf("%lf", res);
    return 0;
}
