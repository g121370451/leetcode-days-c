
#include <stdio.h>

double my_atof(const char *str)
{
    double res = 0.0;
    int flag = 0;
    if (str[0] == '-')
    {
        flag = 1;
        str++;
    }
    while (*str != '\0' && *str != '.')
    {
        res *= 10;
        res += *(str) - '0';
        str++;
    }
    if (*str != '\0')
    {
        str++;
        double temp = my_atof(str);
        while (temp >= 1)
        {
            temp = temp / 10.0;
        }
        res += temp;
    }
    if (flag)
    {
        return -res;
    }
    return res;
}

int main(int argc, char const *argv[])
{
    // if (argc != 2)
    // {
    //     fprintf(stderr, "Using atof <str>");
    // }
    // const char *str = argv[1];
    double res = my_atof("1236.6");
    printf("%lf", res);
    return 0;
}
