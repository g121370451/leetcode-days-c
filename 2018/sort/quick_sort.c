#include <stdio.h>

int partation(int *nums, int left, int right)
{
    int pivot = nums[left];
    while (left < right)
    {
        while (left < right && nums[right] > pivot)
            right--;
        if (left < right)
            nums[left++] = nums[right];
        while (left < right && nums[left] < pivot)
            left++;
        if (left < right)
            nums[right--] = nums[left];
    }
    nums[left] = pivot;
    return left;
}

void quick_sort(int *nums, int left, int right)
{
    if (left < right)
    {
        int index = partation(nums, left, right);
        quick_sort(nums, left, index - 1);
        quick_sort(nums, index + 1, right);
    }
}

void qsort(int *nums, int length)
{
    int left = 0;
    int right = length - 1;
    quick_sort(nums, left, right);
}

int main(int argc, char const *argv[])
{
    int nums[] = {972, 309, 648, 731, 82, 254, 529, 36, 747, 882, 932, 480, 145, 364, 715, 165, 278, 488, 671, 206};
    int length = 20;
    qsort(nums, length);
    return 0;
}
