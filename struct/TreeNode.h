#define MAX_QUEUE_NUM 20
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#pragma region tree
typedef struct BinaryTreeNode
{
    int val;
    struct BinaryTreeNode *left;
    struct BinaryTreeNode *right;
} BinaryTreeNode;

// 创建新节点函数
BinaryTreeNode *createNode(int val)
{
    BinaryTreeNode *newNode = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// 构建二叉树函数
BinaryTreeNode *buildTree()
{
    // 创建根节点和子节点
    BinaryTreeNode *root = createNode(1);
    BinaryTreeNode *leftChild = createNode(2);
    BinaryTreeNode *rightChild = createNode(3);

    // 连接子节点和根节点
    root->left = leftChild;
    root->right = rightChild;

    // 创建左子节点的子节点
    leftChild->left = createNode(4);
    leftChild->right = createNode(5);

    // 创建右子节点的子节点
    rightChild->left = createNode(6);
    rightChild->right = createNode(7);

    return root;
}

BinaryTreeNode *buildComplexTree()
{
    BinaryTreeNode *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->left->left = createNode(7);       // 更深的左子树
    root->right->left->left->left = createNode(8); // 更深的左子树
    root->right->right = createNode(9);
    return root;
}
#pragma endregion tree
#pragma region queue

typedef struct CircleQueue
{
    int flag;
    int front;
    int rear;
    int length;
    BinaryTreeNode *tree;
} CircleQueue;

CircleQueue *myCircularQueueCreate(int k)
{
    CircleQueue *queue = (CircleQueue *)malloc(sizeof(CircleQueue));
    queue->flag = 0;
    queue->rear = 0;
    queue->front = 0;
    queue->tree = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode) * k);
    queue->length = k;
    return queue;
}

bool myCircularQueueEnQueue(CircleQueue *obj, BinaryTreeNode *value)
{
    if (obj->flag == 1 && obj->rear == obj->front)
    {
        return false;
    }
    obj->tree[obj->rear] = *value;
    obj->rear = (obj->rear + 1) % obj->length;
    obj->flag = 1;
    return true;
}

bool myCircularQueueDeQueue(CircleQueue *obj)
{
    if (obj->flag == 0 && obj->front == obj->rear)
    {
        return false;
    }
    obj->front = (obj->front + 1) % obj->length;
    obj->flag = 0;
    return true;
}

BinaryTreeNode *myCircularQueueFront(CircleQueue *obj)
{
    if (obj->flag == 0 && obj->front == obj->rear)
    {
        return NULL;
    }
    return &obj->tree[obj->front];
}

BinaryTreeNode *myCircularQueueRear(CircleQueue *obj)
{
    if (obj->flag == 0 && obj->front == obj->rear)
    {
        return NULL;
    }
    return &obj->tree[(obj->rear + obj->length - 1) % obj->length];
}

bool myCircularQueueIsEmpty(CircleQueue *obj)
{
    if (obj->flag == 0 && obj->front == obj->rear)
    {
        return true;
    }
    return false;
}

bool myCircularQueueIsFull(CircleQueue *obj)
{
    if (obj->flag == 1 && obj->front == obj->rear)
    {
        return true;
    }
    return false;
}

void myCircularQueueFree(CircleQueue *obj)
{
    free(obj->tree);
    free(obj);
}
#pragma endregion queue

#pragma region stack

typedef struct Stack
{
    int top;
    int max;
    BinaryTreeNode *nums;
} Stack;

Stack *createStack(int k)
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->top = 0;
    stack->max = k;
    stack->nums = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode) * k);
    return stack;
}

BinaryTreeNode *stackPeek(Stack *obj)
{
    if (obj->top == 0)
    {
        return NULL;
    }
    return &obj->nums[obj->top - 1];
}

bool stackPush(Stack *obj, BinaryTreeNode *node)
{
    if (obj->top == obj->max)
    {
        return false;
    }
    obj->nums[obj->top++] = *node;
    return true;
}

bool isStackEmpty(Stack *obj)
{
    return obj->top == 0;
}

bool isStackFull(Stack *obj)
{
    return obj->top == obj->max;
}

BinaryTreeNode *stackPull(Stack *obj)
{
    if (isStackEmpty(obj))
    {
        return NULL;
    }

    BinaryTreeNode *node = stackPeek(obj);
    --obj->top;
    return node;
}

#pragma endregion stack