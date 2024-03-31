#include <stdio.h>

int my_strcmp(const char *source, const char *target)
{
    while (*source && *source == *target)
    {
        source++;
        target++;
    }
    return *(unsigned char *)source - *(unsigned char *)target;
}

int main(int argc, char const *argv[])
{
    /* code */
    char str1[] = "Hello";
    char str2[] = "Hello";
    char str3[] = "World";
    int res = my_strcmp(str1, str2);
    int res2 = my_strcmp(str2, str3);
    printf("%d", res2);
    return 0;
}
