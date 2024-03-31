#include <stdio.h>
char *strcpy(const char *source, char *target)
{
    char *d = target;
    while (*source)
    {
        *d++ = *source++;
    }
    *d = '\0'; // 添加字符串结束符
    return target;
}

int main(int argc, char const *argv[])
{
    char *source = "easy";
    char target[5];
    char *result = strcpy(source, target);
    fprintf(stdout, result);
    return 0;
}
