#include "../include/StructLeetcode.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
typedef struct
{
    int val;
    struct FindElements *left;
    struct FindElements *right;
} FindElements;

FindElements *createFindElements(int val)
{
    FindElements *obj = (FindElements *)malloc(sizeof(FindElements));
    obj->val = val;
    obj->left = NULL;
    obj->right = NULL;
    return obj;
}

void buildNode(FindElements **obj, struct TreeNode *root, int num)
{
    if (root == NULL)
    {
        return;
    }
    *obj = createFindElements(num);
    buildNode(&((*obj)->left), root->left, num * 2 + 1);
    buildNode(&((*obj)->right), root->right, num * 2 + 2);
}

FindElements *findElementsCreate(struct TreeNode *root)
{
    FindElements *obj = createFindElements(0);
    buildNode(&(obj->left), root->left, 1);
    buildNode(&(obj->right), root->right, 2);
    return obj;
}

bool findElementsFind(FindElements *obj, int target)
{
    if (obj == NULL)
    {
        return false;
    }
    if (obj->val == target)
    {
        return true;
    }
    
    if (target%2==0)
    {
        findElementsCreate(obj->right)
    }
    
    return res;
}

void findElementsFree(FindElements *obj)
{
    free(obj);
}

int main(int argc, char const *argv[])
{
    // struct TreeNode *root = createNode(-1);
    // root->right = createNode(-1);
    // FindElements *obj = findElementsCreate(root);
    // bool param_1 = findElementsFind(obj, 1);
    // bool param_2 = findElementsFind(obj, 2);
    // findElementsFree(obj);

    struct TreeNode *root = createNode(-1);
    root->left = createNode(-1);
    root->left->left = createNode(-1);
    root->left->right = createNode(-1);
    root->right = createNode(-1);
    FindElements *obj = findElementsCreate(root);
    bool param_1 = findElementsFind(obj, 1);
    bool param_2 = findElementsFind(obj, 3);
    bool param_3 = findElementsFind(obj, 5);
    findElementsFree(obj);
}
