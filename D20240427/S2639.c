#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int* findColumnWidth(int** grid, int gridSize, int* gridColSize, int* returnSize) {
    int n = gridSize, m = gridColSize[0];
    int *res = (int *)malloc(sizeof(int) * m);
    *returnSize = m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x = grid[i][j];
            int length = 0;
            if (x <= 0) {
                length = 1;
            }
            while (x != 0) {
                length += 1;
                x /= 10;
            }
            res[j] = fmax(res[j], length);
        }
    }
    return res;
}