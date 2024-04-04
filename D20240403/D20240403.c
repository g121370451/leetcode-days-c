#include <stdio.h>
#include <stdlib.h>
#include "../struct/TreeNode.h"

typedef struct Queue_TreeNode
{
    int front;
    int rear;
    int size;
    int flag;
    struct TreeNode **trees;
} Queue_TreeNode;

int enQueue(Queue_TreeNode *obj, TreeNode *nodeOriginal)
{
    if (obj->flag == 1 && obj->front == obj->rear)
    {
        return 0;
    }
    obj->trees[obj->front] = nodeOriginal;
    obj->front = (obj->front + 1) % obj->size;
    obj->flag = 1;
}

TreeNode *peekQueue(Queue_TreeNode *obj)
{
    if (obj->flag == 0 && obj->front == obj->rear)
    {
        return NULL;
    }
    return obj->trees[obj->rear];
}

int deQueue(Queue_TreeNode *obj)
{
    if (obj->flag == 0 && obj->front == obj->rear)
    {
        return 0;
    }
    obj->rear = (obj->rear + 1) % obj->size;
    obj->flag = 0;
    return 1;
}

int isEmpty(Queue_TreeNode *obj)
{
    if (obj->flag == 0 && obj->front == obj->rear)
    {
        return 1;
    }
    return 0;
}

int isFull(Queue_TreeNode *obj)
{
    if (obj->flag == 1 && obj->front == obj->rear)
    {
        return 1;
    }
    return 0;
}

TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned, TreeNode *target)
{
    Queue_TreeNode *obj = (Queue_TreeNode *)malloc(sizeof(Queue_TreeNode));
    obj->size = 10000;
    obj->front = 0;
    obj->rear = 0;
    obj->flag = 0;
    obj->trees = (TreeNode **)malloc(sizeof(TreeNode *) * 10000);
    enQueue(obj, original);
    enQueue(obj, cloned);
    TreeNode *t;
    TreeNode *tc;
    while (!isEmpty(obj))
    {
        t = peekQueue(obj);
        deQueue(obj);
        tc = peekQueue(obj);
        deQueue(obj);
        if (t == target)
        {
            return tc;
        }
        else
        {
            if (t->left != NULL)
            {
                enQueue(obj, t->left);
                enQueue(obj, tc->left);
            }
            if (t->right != NULL)
            {
                enQueue(obj, t->right);
                enQueue(obj, tc->right);
            }
        }
    }
    return NULL;
}

TreeNode *createNodeMy(int val)
{
    TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int main(int argc, char const *argv[])
{
    TreeNode *root = createNodeMy(7);
    root->left = createNodeMy(4);
    root->right = createNodeMy(3);
    root->right->left = createNodeMy(6);
    root->right->right = createNodeMy(19);

    TreeNode *root1 = createNodeMy(7);
    root1->left = createNodeMy(4);
    root1->right = createNodeMy(3);
    root1->right->left = createNodeMy(6);
    root1->right->right = createNodeMy(19);

    TreeNode *t = getTargetCopy(root, root1, root->right->left);
    return 0;
}
