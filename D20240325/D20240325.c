#include <stdio.h>

#include <stdlib.h>
#include <string.h>

int change(int amount, int *coins, int coinsSize)
{
    int i, j;
    int dp[amount + 1];

    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (i = 0; i < coinsSize; i++)
    {
        for (j = coins[i]; j <= amount; j++)
        {
            dp[j] += dp[j - coins[i]];
        }
    }
    return dp[amount];
}

int main(int argc, char const *argv[])
{
    int coins[] = {1, 2, 5};
    // int coins1[] = {411, 412, 413, 414, 415, 416, 417, 418, 419, 420, 421, 422};
    // int coins1[] = {7};
    int res = change(11, coins, 3);
    printf("%d", res);
    return 0;
}
