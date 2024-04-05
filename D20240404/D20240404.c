#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../lib/uthash.h"
#include <stdbool.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

// 使用邻接链表存储有向图
// v[i] 表示从节点 i 出发的一条边（0 代表无）
// e.o 表示该边指向的节点，e.next 表示邻接链表中的下一条边
int v[1000], es;
struct { int o, next; } e[500000];

// 记录路径上的节点，以及标记经过的节点
int temp[1000], ts, set[1000];


void dfs(int x) {
    for (int i = v[x]; i; i = e[i].next) {
        if (set[e[i].o]) continue;
        set[e[i].o] = 1;
        temp[ts++] = e[i].o;
        dfs(e[i].o);
    }
}


int cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}


int** getAncestors(
int n,
int** edges,
int edgesSize,
int* edgesColSize, // *edgesColSize == 2
int* returnSize,
int** returnColumnSizes)
{
    es = 1;
    memset(v, 0, sizeof (int) * n);

    // 注意这里反转了边的方向，目的是可以从子节点反过来到达所有祖先节点
    for (int i = 0; i < edgesSize; ++i) {
        int from = edges[i][0], to = edges[i][1];
        e[es].o = from;
        e[es].next = v[to];
        v[to] = es++;
    }
    
    *returnSize = n;
    *returnColumnSizes = malloc(sizeof (int) * n);
    int** ans = malloc(sizeof (int*) * n);
    
    for (int i = 0; i < n; ++i) {
        ts = 0;
        memset(set, 0, sizeof (int) * n);
        dfs(i);
        (*returnColumnSizes)[i] = ts;
        ans[i] = malloc(sizeof (int) * ts);
        memcpy(ans[i], temp, sizeof (int) * ts);
        qsort(ans[i], ts, sizeof (int), cmp);
    }
    
    return ans;
}

int main(int argc, char const *argv[])
{
    // int edges[10][2] = {{0, 1}, {0, 2}, {0, 3}, {0, 4}, {1, 2}, {1, 3}, {1, 4}, {2, 3}, {2, 4}, {3, 4}};
    int edges[9][2] = {{0,3},{0,4},{1,3},{2,4},{2,7},{3,5},{3,6},{3,7},{4,6}};
    // 将二维数组的地址传递给指向指针的指针
    int *ptr[9];
    for (int i = 0; i < 9; i++)
    {
        ptr[i] = edges[i];
    }
    int n = 8;
    int edgeSize = 9;
    int edgeColumnSize[10] = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2};
    int returnSize = 0;
    int *returnColumnSize;
    int **res = getAncestors(n, ptr, edgeSize, edgeColumnSize, &returnSize, &returnColumnSize);
    return 0;
}
