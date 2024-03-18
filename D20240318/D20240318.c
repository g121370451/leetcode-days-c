#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *nums;
} NumArray;

NumArray *numArrayCreate(int *nums, int numsSize)
{
    NumArray *numArray = (NumArray *)malloc(sizeof(NumArray));
    numArray->nums = malloc(sizeof(int) * (numsSize + 1));
    numArray->nums[0] = 0;
    for (int i = 0; i < numsSize; i++)
    {
        numArray->nums[i+1] = numArray->nums[i] + nums[i];
    }

    return numArray;
}

int numArraySumRange(NumArray *obj, int left, int right)
{
    return obj->nums[right + 1] - obj->nums[left];
}

void numArrayFree(NumArray *obj)
{
    free(obj->nums);
}

/**
 * Your NumArray struct will be instantiated and called as such:
 * NumArray* obj = numArrayCreate(nums, numsSize);
 * int param_1 = numArraySumRange(obj, left, right);

 * numArrayFree(obj);
*/

int main(int argc, char const *argv[])
{
    /* code */
    int nums[] = {-2, 0, 3, -5, 2, -1};
    NumArray *obj = numArrayCreate(nums, 6);
    int param_1 = numArraySumRange(obj, 0, 2);
    int param_2 = numArraySumRange(obj, 2, 5);
    int param_3 = numArraySumRange(obj, 0, 5);
    numArrayFree(obj);
    return 0;
}
