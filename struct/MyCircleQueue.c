#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int flag;
    int rear;
    int front;
    int *nums;
    int length;
} MyCircularQueue;

MyCircularQueue *myCircularQueueCreate(int k)
{
    MyCircularQueue *queue = (MyCircularQueue *)malloc(sizeof(MyCircularQueue));
    queue->flag = 0;
    queue->rear = 0;
    queue->front = 0;
    queue->nums = (int *)malloc(sizeof(int) * k);
    queue->length = k;
    return queue;
}

bool myCircularQueueEnQueue(MyCircularQueue *obj, int value)
{
    if (obj->flag == 1 && obj->rear == obj->front)
    {
        return false;
    }
    obj->nums[obj->rear] = value;
    obj->rear = (obj->rear + 1) % obj->length;
    obj->flag = 1;
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue *obj)
{
    if (obj->flag == 0 && obj->front == obj->rear)
    {
        return false;
    }
    obj->front = (obj->front + 1) % obj->length;
    obj->flag = 0;
    return true;
}

int myCircularQueueFront(MyCircularQueue *obj)
{
    if (obj->flag == 0 && obj->front == obj->rear)
    {
        return -1;
    }
    return obj->nums[obj->front];
}

int myCircularQueueRear(MyCircularQueue *obj)
{
    if (obj->flag == 0 && obj->front == obj->rear)
    {
        return -1;
    }
    return obj->nums[(obj->rear + obj->length - 1) % obj->length];
}

bool myCircularQueueIsEmpty(MyCircularQueue *obj)
{
    if (obj->flag == 0 && obj->front == obj->rear)
    {
        return true;
    }
    return false;
}

bool myCircularQueueIsFull(MyCircularQueue *obj)
{
    if (obj->flag == 1 && obj->front == obj->rear)
    {
        return true;
    }
    return false;
}

void myCircularQueueFree(MyCircularQueue *obj)
{
    free(obj->nums);
    free(obj);
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);

 * bool param_2 = myCircularQueueDeQueue(obj);

 * int param_3 = myCircularQueueFront(obj);

 * int param_4 = myCircularQueueRear(obj);

 * bool param_5 = myCircularQueueIsEmpty(obj);

 * bool param_6 = myCircularQueueIsFull(obj);

 * myCircularQueueFree(obj);
*/