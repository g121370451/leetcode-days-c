// 1017. Convert to Base -2
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
int max(int x, int y)
{
    return x > y ? x : y;
}

char *baseNeg2(int n)
{
    if (n == 0)
    {
        return "0";
    }
    if (n == 1)
    {
        return "1";
    }
    int postive = 1;
    int negative = 0;
    int sum = 1;
    int len = 1;
    while (sum < n)
    {
        postive *= 4;
        sum += postive;
        len += 2;
    }
    char *res = (char *)calloc(len + 1, sizeof(char));
    memset(res, '0', len);
    negative = postive / -2;
    res[0] = '1';
    n -= postive;
    postive /= 4;
    int postiveIndex = 2;
    int negativeIndex = 1;
    while (n != 0)
    {
        if (n > 0)
        {
            if ((postive - 1) / 3 >= n)
            {
                res[postiveIndex] = '0';
            }
            else
            {
                n -= postive;
                res[postiveIndex] = '1';
            }
            postive /= 4;
            postiveIndex += 2;
        }
        else if (n < 0)
        {
            if ((negative - 1) / 3 + 1 <= n)
            {
                res[negativeIndex] = '0';
            }
            else
            {
                n -= negative;
                res[negativeIndex] = '1';
            }
            negative /= 4;
            negativeIndex += 2;
        }
    }
    return res;
}

int main(int argc, char const *argv[])
{
    // 1    1   1    1  1  1  1
    // 64  -32  16  -8  4 -2  1
    // printf("%s\n", baseNeg2(0)); // 0
    // printf("%s\n", baseNeg2(1)); // 1
    // printf("%s\n", baseNeg2(2)); // 110
    printf("%s\n", baseNeg2(29)); // 1 1 0 1 1 0 1
    // printf("%s\n", baseNeg2(3)); // 111
    // printf("%s\n", baseNeg2(4)); // 100
    // printf("%s\n", baseNeg2(5)); // 101 -> 5
    // printf("%s\n", baseNeg2(6)); // 11010 -> 21 (1-4e3)/(1-4) = (1-64)/-3 = -63/-3 = 21 16 -8 -2
    // 10010-> 16-2 14
    return 0;
}
