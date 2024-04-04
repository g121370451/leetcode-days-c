#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
static int flagRowNumPrint = 0;
static int flagRowPrintNum = 1;
struct 
{
    int val;
    int key;
} pair;

void grep(const char *pattern, const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error opening file: %s\n", filename);
        return;
    }
    char line_max_array[1024];
    int rowNumber = 1;
    while (fgets(line_max_array, 1024, file) != NULL)
    {
        if (strstr(line_max_array, pattern) != NULL)
        {
            if (flagRowNumPrint != 0)
            {
                fprintf(stdout, "current row is %d\n", rowNumber);
            }
            fprintf(stdout, line_max_array);
            --flagRowPrintNum;
            while (flagRowPrintNum > 0 && fgets(line_max_array, 1024, file) != NULL)
            {
                fprintf(stdout, line_max_array);
                --flagRowPrintNum;
                rowNumber++;
            }
        }
    }
    if (fclose(file) != 0)
    {
        fprintf(stderr, "Error closing file: %s\n", filename);
        return;
    }
}

void print_usage()
{
    fprintf(stderr, "Usgae: grep [-n] [-m NUM] <filename> <pattern>\n");
    fprintf(stderr, "Options:\n");
    fprintf(stderr, "\t-n             show current row number\n");
    fprintf(stderr, "\t-m NUM         show num row\n");
}

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        print_usage();
        return 1;
    }

    int i;
    for (i = 1; i < argc - 2; i++)
    {
        if (strcmp(argv[i], "-n") == 0)
        {
            flagRowNumPrint = 1;
        }
        else if (strcmp(argv[i], "-m") == 0)
        {
            if (i + 1 < argc - 2)
            {
                ++i;
                flagRowPrintNum = atoi(argv[i]);
            }
            else
            {
                fprintf(stderr, "-m option requires a parameter");
                return 1;
            }
        }
    }
    const char *filename = argv[i++];
    const char *pattern = argv[i];
    grep(pattern, filename);
    return 0;
}