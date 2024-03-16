#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char *capitalizeTitle(char *title)
{
    int n = strlen(title);
    int left_index = 0, right_index = 0;
    while (right_index < n)
    {
        while (right_index < n && title[right_index] != ' ')
        {
            ++right_index;
        }
        if (right_index - left_index > 2)
        {
            title[left_index++] = toupper(title[left_index]);
        }
        while (left_index < right_index)
        {
            title[left_index++] = tolower(title[left_index]);
        }
        left_index = ++right_index;
    }
    return title;
}

int main()
{
    char str[] = "capiTalIze tHe titLe";
    char *p = str;
    char *result1 = capitalizeTitle(p);
    for (int i = 0; i < strlen(result1); i++)
    {
        printf("%c", result1[i]);
    }
}