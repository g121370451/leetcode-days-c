int *findColumnWidth(int **grid, int gridSize, int *gridColSize, int *returnSize)
{
    int maxGlobal = 0;
    for (int i = 0; i < gridSize; i++)
    {
        int max = 0;
        for (int j = 0; j < gridColSize[i]; j++)
        {
            int len = sprintf(str, "%d", num);
            max >= len ?: max = len;
        }
        maxGlobal < max ? maxGlobal = max : ;
        returnSize[i] = max;
    }
    return maxGlobal;
}