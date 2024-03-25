#include <stdio.h>
#include <string.h>

#define MIN(a, b) a < b ? a : b;
int coinChange(int *coins, int coinsSize,
               int amount)
{
    int i, j;
    int dp[amount + 1];
    memset(dp, 0x3f3f3f3f, sizeof(dp));
    dp[0] = 0;

    for (i = 0; i < coinsSize; i++)
    {
        for (j = 1; j <= amount; j++)
        {
            if (j >= coins[i] && dp[j - coins[i]] != 0x3f3f3f3f)
            {
                dp[j] = MIN(dp[j], dp[j - coins[i]] + 1);
            }
        }
    }
    if (dp[amount] == 0x3f3f3f3f)
    {
        return -1;
    }
    return dp[amount];
}
int main(int argc, char const *argv[])
{
    int coins[] = {1, 2, 5};
    int res = coinChange(coins, 3, 11);
    printf("%d", res);
    return 0;
}
