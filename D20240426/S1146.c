#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    int snapId;
    int val;
} Pair;

typedef struct
{
    int length;
    Pair **list;
    int *capablity;
    int *max;
    int snap;
} SnapshotArray;

Pair *buildPair(int snapId, int val)
{
    Pair *pair = (Pair *)malloc(sizeof(Pair));
    pair->snapId = snapId;
    pair->val = val;
    return pair;
}

SnapshotArray *snapshotArrayCreate(int length)
{
    SnapshotArray *obj = (SnapshotArray *)malloc(sizeof(SnapshotArray));
    obj->list = (Pair **)malloc(sizeof(Pair *) * length);
    obj->capablity = (int *)malloc(sizeof(int) * length);
    obj->max = (int *)malloc(sizeof(int) * length);
    memset(obj->capablity, 0, sizeof(int) * length);
    memset(obj->max, 10, sizeof(int) * length);
    for (int i = 0; i < length; i++)
    {
        obj->list[i] = NULL;
    }
    obj->snap = 0;
    obj->length = length;
    return obj;
}

void snapshotArraySet(SnapshotArray *obj, int index, int val)
{
    if (obj->capablity[index] == 0)
    {
        obj->list[index] = (Pair *)malloc(sizeof(Pair) * obj->max[index]);
        ++obj->capablity[index];
    }
    else if (obj->capablity[index] == obj->max[index])
    {
        obj->max[index] *= 2;
        Pair *temp = obj->list[index];
        obj->list[index] = (Pair *)malloc(sizeof(Pair) * obj->max[index]);
        memcpy(obj->list[index], temp, sizeof(Pair) * (obj->capablity[index] + 1));
        free(temp);
    }
    // 获取某一个位置的最新数据
    Pair *p = &(obj->list[index][obj->capablity[index] - 1]);
    if (p->snapId != (obj->snap + 1))
    {
        p = buildPair(obj->snap + 1, val);
        obj->list[index][++obj->capablity[index]] = *p;
    }
    p->val = val;
}

int snapshotArraySnap(SnapshotArray *obj)
{
    return obj->snap++;
}

int binarySearch(int capablity, Pair *obj, int snapId)
{
    if (obj == NULL)
    {
        return 0;
    }
    snapId += 1;
    int left = 0;
    int right = capablity;
    while (left <= right)
    {
        int temp = (left + right) / 2;
        if (obj[temp].snapId == snapId)
        {
            return obj[temp].val;
        }
        else if (obj[temp].snapId < snapId)
        {
            left = temp + 1;
        }
        else
        {
            right = temp - 1;
        }
    }
    return 0;
}

int snapshotArrayGet(SnapshotArray *obj, int index, int snap_id)
{
    return binarySearch(obj->capablity[index], obj->list[index], snap_id);
}

void snapshotArrayFree(SnapshotArray *obj)
{
    for (int i = 0; i < obj->length; i++)
    {
        free(obj->list[i]);
    }
    free(obj->list);
    free(obj->capablity);
    free(obj->max);
    free(obj);
}

int main(int argc, char const *argv[])
{
    /* code */
    SnapshotArray *obj = snapshotArrayCreate(1);
    // printf("%d\n", snapshotArraySnap(obj));
    snapshotArraySet(obj, 0, 4);
    snapshotArraySet(obj, 0, 16);
    snapshotArraySet(obj, 0, 13);
    printf("%d\n", snapshotArraySnap(obj));
    printf("%d\n", snapshotArrayGet(obj, 0, 0));
    printf("%d\n", snapshotArraySnap(obj));
    // printf("%d\n", snapshotArrayGet(obj, 0, 0));
    // snapshotArraySet(obj, 2, 4);
    // printf("%d\n", snapshotArraySnap(obj));
    // snapshotArraySet(obj, 1, 4);

    snapshotArrayFree(obj);
}

/**
 * ["SnapshotArray","snap","snap","get","set","snap","set"]
[[4],[],[],[3,1],[2,4],[],[1,4]]
 * Your SnapshotArray struct will be instantiated and called as such:
 * SnapshotArray* obj = snapshotArrayCreate(length);
 * snapshotArraySet(obj, index, val);

 * int param_2 = snapshotArraySnap(obj);

 * int param_3 = snapshotArrayGet(obj, index, snap_id);

 * snapshotArrayFree(obj);
*/