#include <stdbool.h>
#include <stdio.h>

int getNext(int n)
{
    int res = 0;
    while (n != 0)
    {
        res += (n % 10) * (n % 10);
        n = n / 10;
    }
    return res;
}

bool isHappy(int n)
{
    int slow = n;
    int fast = n;
    do
    {
        slow = getNext(slow);
        fast = getNext(fast);
        fast = getNext(fast);
    } while (slow != fast);
    return slow == 1;
}

int main(int argc, char const *argv[])
{
    bool res = isHappy(2);
    if (res)
    {
        printf("true\n");
    }
    else
    {
        printf("false\n");
    }
    return 0;
}
