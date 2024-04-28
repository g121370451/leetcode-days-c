#include <stddef.h>
#include "../lib/uthash.h"
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// 创建新节点
struct TreeNode *createNode(int val)
{
    struct TreeNode *newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    if (newNode != NULL)
    {
        newNode->val = val;
        newNode->left = NULL;
        newNode->right = NULL;
    }
    return newNode;
}

typedef struct HashItem
{
    int key;
    struct UT_hash_handle hh;
} HashItem;

typedef struct ListNode
{
    int val;
    struct ListNode *next;
} ListNode;

struct ListNode *createListNode(int val)
{
    struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
    if (newNode != NULL)
    {
        newNode->val = val;
        newNode->next = NULL;
    }
    return newNode;
}
struct ListNode *createListNodeW(int val, ListNode *next)
{
    struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
    if (newNode != NULL)
    {
        newNode->val = val;
        newNode->next = next;
    }
    return newNode;
}
