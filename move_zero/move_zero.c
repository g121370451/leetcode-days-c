#include <stdio.h>
// 1 0 3 0 0 5
void moveZeroes(int *nums, int numsSize)
{
    int i = 0;
    int j = 0;
    while (i < numsSize)
    {
        if (nums[i] != 0)
        {
            if (i != j)
            {
                nums[j] = nums[i];
                nums[i]=0;
            }
            j++;
        }
        i++;
    }
}

int main(int argc, char const *argv[])
{
    int nums[] = {0, 1, 0, 3, 12};
    int nums1[] = {1,0,3,0,0,5};
    moveZeroes(nums, 5);
    moveZeroes(nums1,6);
    for (int i = 0; i < 5; i++)
    {
        printf("%d", nums[i]);
    }
        for (int i = 0; i < 6; i++)
    {
        printf("%d", nums1[i]);
    }
    return 0;
}
