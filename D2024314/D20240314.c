#include <stdio.h>
#include <stdlib.h>
//[2,3,7,9,3] res 9
//
long long maxArrayValue_mine(int *nums, int numsSize)
{
    long long res = 0;
    if (numsSize==1)
    {
        res = nums[0];
        return res;
    }
    long long * res_l = malloc(sizeof(long long) * numsSize);
    for(int i = 0;i<numsSize;i++){
        res_l[i] = nums[i];
    }
    int i = numsSize - 1;
    while (i > 0)
    {
        if (res_l[i] >= res_l[i - 1])
        {
            res_l[i - 1] = res_l[i - 1] + res_l[i];
        }
        res = res_l[i - 1];
        --i;
    }
    return res;
}

long long maxArrayValue(int* nums, int numsSize){
    long long sum = nums[numsSize - 1];
    for (int i = numsSize - 2; i >= 0; i--) {
        sum = nums[i] <= sum ? nums[i] + sum : nums[i];
    }
    return sum;
}

int main()
{
    int nums[] = {2, 3, 7, 9, 3};
    int nums1[] = {5, 3, 3};
    int nums2[] = {77};
    long long res = maxArrayValue(nums, 5);
    long long res1 = maxArrayValue(nums1, 3);
    long long res2 = maxArrayValue(nums2, 3);
    printf("%d", res);
    printf("%d", res1);
    printf("%d", res2);
}