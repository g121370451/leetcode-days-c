#include <stdio.h>
int maxSubArray(int *nums, int numsSize)
{
    int max = nums[0];
    for (int i = 0; i < numsSize; i++)
    {
        int sum = 0;
        for (int j = i; j < numsSize; j++)
        {
            sum += nums[j];
            max = max > sum ? max : sum;
        }
    }
    return max;
}

int main(int argc, char const *argv[])
{
    int nums[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int nums1[] = {-2, 1};
    int nums12[] = {-2, -1};
    int res = maxSubArray(nums, 9);
    int res1 = maxSubArray(nums1, 2);
    int res2 = maxSubArray(nums12, 2);
    printf("%d", res);
    printf("%d", res1);
    printf("%d", res2);
    return 0;
}
