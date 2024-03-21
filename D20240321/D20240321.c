#include <stdio.h>
#include "../lib/uthash.h"
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
    int key;
    int val;
    UT_hash_handle hh;
} Hash_Item;
;

typedef struct
{
    Hash_Item *frequency;
    Hash_Item *frequency_cnt;
} FrequencyTracker;

Hash_Item *isTargetInHash(int target, Hash_Item **hash_item)
{
    Hash_Item *node;
    HASH_FIND_INT(*hash_item, &target, node);
    if (node != NULL)
    {
        return node;
    }
    node = (Hash_Item *)malloc(sizeof(Hash_Item));
    node->key = target;
    node->val = 0;
    HASH_ADD_INT(*hash_item, key, node);
    return node;
}

void deleteTargetInHash(Hash_Item **list, Hash_Item *item)
{
    HASH_DELETE(hh, *list, item);
    free(item);
}

FrequencyTracker *frequencyTrackerCreate()
{
    FrequencyTracker *frequencyTracker = (FrequencyTracker *)malloc(sizeof(FrequencyTracker));
    frequencyTracker->frequency = NULL;
    frequencyTracker->frequency_cnt = NULL;
    return frequencyTracker;
}

void frequencyTrackerAdd(FrequencyTracker *obj, int number)
{
    Hash_Item *target = isTargetInHash(number, &obj->frequency);
    if (target->val == 0)
    {
        target->val = 1;
        Hash_Item *cnt_target = isTargetInHash(1, &obj->frequency_cnt);
        if (cnt_target->val == 0)
        {
            cnt_target->val = 1;
        }
        else
        {
            ++cnt_target->val;
        }
    }
    else
    {
        Hash_Item *cnt_target = isTargetInHash(target->val, &obj->frequency_cnt);
        Hash_Item *cnt_target_next = isTargetInHash(target->val + 1, &obj->frequency_cnt);
        --cnt_target->val;
        if (cnt_target_next->val == 0)
        {
            cnt_target_next->val = 1;
        }
        else
        {
            ++cnt_target_next->val;
        }
        ++target->val;
    }
}

void frequencyTrackerDeleteOne(FrequencyTracker *obj, int number)
{
    Hash_Item *target = isTargetInHash(number, &obj->frequency);
    if (target->val != 0)
    {
        --isTargetInHash(target->val, &obj->frequency_cnt)->val;
        if (target->val != 1)
        {
            ++isTargetInHash(target->val - 1, &obj->frequency_cnt)->val;
        }
        --target->val;
    }
}

bool frequencyTrackerHasFrequency(FrequencyTracker *obj, int frequency)
{
    Hash_Item *target = isTargetInHash(frequency, &obj->frequency_cnt);
    if (target->val <= 0)
    {
        return false;
    }
    return true;
}

void frequencyTrackerFree(FrequencyTracker *obj)
{
    free(obj->frequency);
    free(obj->frequency_cnt);
}

int main(int argc, char const *argv[])
{
    /* code */
    FrequencyTracker *obj = frequencyTrackerCreate();
    // frequencyTrackerAdd(obj, 2);
    // frequencyTrackerAdd(obj, 3);
    // frequencyTrackerAdd(obj, 3);
    // frequencyTrackerAdd(obj, 3);
    // frequencyTrackerAdd(obj, 4);
    // frequencyTrackerDeleteOne(obj, 3);
    // bool param_3 = frequencyTrackerHasFrequency(obj, 1);
    // bool param_4 = frequencyTrackerHasFrequency(obj, 2);
    // bool param_5 = frequencyTrackerHasFrequency(obj, 3);
    frequencyTrackerAdd(obj, 3);
    frequencyTrackerAdd(obj, 3);
    bool param_5 = frequencyTrackerHasFrequency(obj, 2);
    frequencyTrackerFree(obj);
    return 0;
}