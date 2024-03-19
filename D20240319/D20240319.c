#include <stdio.h>

int maximumScore(int *nums, int numsSize, int k)
{
    int left = k - 1;
    int right = k + 1;
    int ans_left = k;
    int ans_right = k;
    int length = 1;
    int sum = nums[k];
    int min_num = nums[k];
    // 如果两侧大 直接加
    // 如果两侧都小 1. 已知最大情况下都小 取消延展
    //             2. 如果不小 选择大的延展
    // 重复判断
    while (left >= 0 && right < numsSize)
    {
        ++length;
        if (nums[left] > nums[right])
        {
            if (nums[left] < min_num)
            {
                min_num = nums[left];
            }
            if (sum < min_num * length)
            {
                ans_left = left;
                sum = min_num * length;
            }
            --left;
        }
        else
        {
            if (nums[right] < min_num)
            {
                min_num = nums[right];
            }
            if (sum < min_num * length)
            {
                ans_right = right;
                sum = min_num * length;
            }
            ++right;
        }
    }
    while (left >= 0)
    {
        ++length;
        if (nums[left] < min_num)
        {
            min_num = nums[left];
        }
        if (sum < min_num * length)
        {
            ans_left = left;
            sum = min_num * length;
        }
        --left;
    }
    while (right < numsSize)
    {
        ++length;
        if (nums[right] < min_num)
        {
            min_num = nums[right];
        }
        if (sum < min_num * length)
        {
            ans_right = right;
            sum = min_num * length;
        }
        ++right;
    }

    return sum;
}

int main(int argc, char const *argv[])
{
    // 1 1 1 1 1 1
    // {1, 4, 3, 7, 2, 5}; //12
    int nums[] = {1, 4, 3, 7, 4, 5};
    int nums1[] = {8182,1273,9847,6230,52,1467,6062,726,4852,4507,2460,2041,500,1025,5524};
    int res = maximumScore(nums, 6, 3);
    int res1 = maximumScore(nums1, 15, 8);
    printf("%d", res1);
    return 0;
}
