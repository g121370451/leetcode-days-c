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

    int index = 1;
    double res = myPow(x, n / 2);
    res *= res;
    res *= myPow(x, n % 2);
    return res;
}

int main(int argc, char const *argv[])
{
    double res = myPow(34.00515, -3);
    printf("%lf", res);
    return 0;
}
