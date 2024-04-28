#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int countElements(int *arr, int arrSize)
{
    int res = 0;
    int *counter = (int *)calloc(1001, sizeof(int));
    memset(counter, 0, sizeof(int) * 1001);
    for (int i = 0; i < arrSize; i++)
    {
        ++counter[arr[i]];
    }
    for (int i = 0; i < arrSize; i++)
    {
        if (i + 1 < 1001 && counter[arr[i]+1]!=0)
        {
            ++res;
        }
    }
    return res;
}

int main(int argc, char const *argv[])
{
    int a1[] = {1, 2, 3};
    int a2[] = {1, 1, 3, 3, 5, 5, 7, 7};
    int a3[] = {1, 3, 2, 3, 5, 0};
    int a4[] = {1, 1, 2, 2};
    printf("%d", countElements(a1, 3));
    printf("%d", countElements(a2, 8));
    printf("%d", countElements(a3, 6));
    printf("%d", countElements(a4, 4));
    return 0;
}
