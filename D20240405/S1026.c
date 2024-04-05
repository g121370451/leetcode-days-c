#include "../struct/TreeNode.h"

int getRes(int *res, int max, int min, struct TreeNode *node)
{
    if (node->val < min)
    {
        min = node->val;
    }
    if (node->val > max)
    {
        max = node->val;
    }
    if (max - min > *res)
    {
        *res = max - min;
    }
    if (node->left != NULL)
    {
        getRes(res, max, min, node->left);
    }
    if (node->right != NULL)
    {
        getRes(res, max, min, node->right);
    }
    return *res;
}

int maxAncestorDiff(struct TreeNode *root)
{
    int res = 0;
    getRes(&res, 0, 0x3f3f3f3f, root);
    return res;
}

int main(int argc, char const *argv[])
{
    // 8,3,10,1,6,null,14,null,null,4,7,13
    TreeNode *root = createTreeNode(8);
    root->left = createTreeNode(3);
    root->left->left = createTreeNode(1);
    root->left->right = createTreeNode(6);
    root->left->right->left = createTreeNode(4);
    root->left->right->right = createTreeNode(7);
    root->right = createTreeNode(10);
    root->right->right = createTreeNode(14);
    root->right->right->left = createTreeNode(13);
    int res = maxAncestorDiff(root);
    return 0;
}
