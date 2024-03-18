#include <stdio.h>
int maxProfit(int *prices, int pricesSize)
{
    int max = 0;
    for (int i = 1; i < pricesSize; i++)
    {
        if (prices[i]>prices[i-1])
        {
            max += prices[i] - prices[i-1];
        }
    }
    return max;
}

int main(int argc, char const *argv[])
{
    int nums[] = {7, 1, 5, 3, 6, 4};
    int res = maxProfit(nums, 6);
    printf("%d", res);
    return 0;
}
