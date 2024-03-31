#include <stdio.h>
#include "../../struct/TreeNode.h"
#include <stdlib.h>

int findKNode(BinaryTreeNode *root, int k)
{
    int res = 0;
    CircleQueue *queue = myCircularQueueCreate(1024);
    myCircularQueueEnQueue(queue, root);
    while (myCircularQueueIsEmpty(queue) != 1)
    {
        BinaryTreeNode *node = myCircularQueueFront(queue);
        int temp = 0;
        if (node->left != NULL)
        {
            ++temp;
            myCircularQueueEnQueue(queue, node->left);
        }
        if (node->right != NULL)
        {
            ++temp;
            myCircularQueueEnQueue(queue, node->left);
        }
        if (temp == k)
        {
            ++res;
        }
        myCircularQueueDeQueue(queue);
    }
    return res;
}

void preOrderFind(BinaryTreeNode *root)
{
    BinaryTreeNode *node = root;
    Stack *obj = createStack(1024);
    while (node != NULL || !isStackEmpty(obj))
    {
        if (node != NULL)
        {
            // 输出前序遍历结果
            fprintf(stdout, "%d",node->val);
            stackPush(obj, node);
            node = node->left;
        }
        else
        {
            node = stackPull(obj);
            node = node->right;
        }
    }
}

void midOrderFind(BinaryTreeNode *root)
{
    Stack *obj = createStack(1024);
    BinaryTreeNode *p = root;
    while (p != NULL || !isStackEmpty(obj))
    {
        if (p != NULL)
        {
            stackPush(obj, p);
            p = p->left;
        }
        else
        {
            // 打印栈内第一个
            BinaryTreeNode *t = stackPull(obj);
            fprintf(stdout, "%d", t->val);
            if (t->right != NULL)
            {
                p = t->right;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    // BinaryTreeNode *tree = buildTree();
    BinaryTreeNode *tree = buildComplexTree();
    // int k = findKNode(tree, 2);
    preOrderFind(tree);
    printf("\n");
    midOrderFind(tree);
    // printf("%d", k);
    return 0;
}
