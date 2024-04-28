#include <stdio.h>

double myPow(double x, int n)
{
    if (n == 0)
    {
        return 1;
    }
    if (n == 1)
    {
        return x;
    }
    if (n == -1)
    {
        return 1 / x;
    }

    double res = myPow(x, n / 2);
    res *= res;
    res *= myPow(x, n % 2);
    return res;
}

int main(int argc, char const *argv[])
{
    double res = myPow(2, 10);
    printf("%lf", res);
    return 0;
}
