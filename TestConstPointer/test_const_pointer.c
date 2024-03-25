#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a = 1;
    int c = 4;
    int * const b = &a;
    b = &c;
    printf("%d",a);
    printf("%d",*b);
    return 0;
}
