#include <stdio.h>
int maxProfit(int *prices, int pricesSize)
{
    int profitList[pricesSize];
    profitList[0] = 0;
    for (int i = 1; i < pricesSize; i++)
    {
        int max = profitList[i - 1];
        for (int j = i - 1; j > 0; j--)
        {
            int temp = profitList[j - 1] + prices[i] - prices[j];
            if (temp > max)
            {
                max = temp;
            }
        }
        if (prices[i] - prices[0] > max)
        {
            max = prices[i] - prices[0];
        }
        
        profitList[i] = max;
    }
    return profitList[pricesSize-1];
}

int main(int argc, char const *argv[])
{
    int nums[] = {7, 1, 5, 3, 6, 4};
    int res = maxProfit(nums, 6);
    printf("%d", res);
    return 0;
}
