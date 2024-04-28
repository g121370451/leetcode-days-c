#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct AnagramsList
{
    int size;
    int *return_size;
    char ***return_strs;
    int **counta;
} AnagramsList;

void isAnagrams(AnagramsList *anagramsList, char *b, int *countb)
{
    for (int index = 0; index < anagramsList->size; index++)
    {
        int flag = 1;
        for (int i = 0; i < 26; i++)
        {
            if (anagramsList->counta[index][i] != countb[i])
            {
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            anagramsList->return_strs[index][anagramsList->return_size[index]] = b;
            anagramsList->return_size[index] += 1;
            return;
        }
    }
    anagramsList->return_size[anagramsList->size] = 1;
    anagramsList->return_strs[anagramsList->size] = (char **)malloc(sizeof(char**) * 100);
    anagramsList->return_strs[anagramsList->size][0] = b;
    anagramsList->counta[anagramsList->size] = countb;
    anagramsList->size += 1;
}

char ***groupAnagrams(char **strs, int strsSize, int *returnSize, int **returnColumnSizes)
{
    AnagramsList anagramsList;
    anagramsList.size = 0;
    anagramsList.return_size = (int *)malloc(sizeof(int) * strsSize);
    anagramsList.return_strs = (char ***)malloc(strsSize * sizeof(char **));
    anagramsList.counta = (int **)malloc(strsSize * sizeof(int *));
    for (int i = 0; i < strsSize; i++)
    {
        int * countb= (int* )malloc(sizeof(int) * 26);
        for (int i = 0; i < 26; i++)
        {
            countb[i] = 0;
        }
        
        char *b = strs[i];
        int len = strlen(b);
        for (int i = 0; i < len; i++)
        {
            int index = b[i] - 'a';
            countb[index] = countb[index] + 1;
        }
        isAnagrams(&anagramsList, b, countb);
    }
    *returnSize = anagramsList.size;
    *returnColumnSizes = anagramsList.return_size;
    return anagramsList.return_strs;
}
// 怎么标记一个异构字符串
int main(int argc, char const *argv[])
{
    char *strs[] = {"eat", "tea", "tan", "ate", "nat", "bat"};
    int res = 0;
    int *returnColumnSizes;
    char ***res_list = groupAnagrams(strs, 6, &res, &returnColumnSizes);
    return 0;
}
