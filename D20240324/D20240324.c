#include <stdio.h>
// 1 2 5 -> 11
// 5 5 2 1 -> 6
//   2 1 -> 11
#include <stdlib.h>
#include <string.h>

#define MIN(a, b) (a<b?a:b)

int coinChange(int* coins, int coinsSize, 
                int amount) {
    int i, j, k;
    int m, n;
    // int dp[coinsSize+1][amount+1];
    int dp[amount+1];

    memset(dp, 0x3f3f3f3f, sizeof(dp));
    dp[0]=0;

    // 注意这里循环的i跟前两个方法相比小1
    for(i=0;i<coinsSize;i++){
        for(j=0;j<=amount;j++){
            if(j>=coins[i] && dp[j-coins[i]]!=0x3f3f3f3f){
                dp[j]=MIN(dp[j], dp[j-coins[i]]+1);
            }
        }
    }

    if(dp[amount]==0x3f3f3f3f){
        return -1;
    }
    return dp[amount];
}

int main(int argc, char const *argv[])
{
    int coins[] = {1, 2, 5};
    int coins1[] = {411, 412, 413, 414, 415, 416, 417, 418, 419, 420, 421, 422};
    int res = coinChange(coins1, 12, 9864);
    printf("%d", res);
    return 0;
}
