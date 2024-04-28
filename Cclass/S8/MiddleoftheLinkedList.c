#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../../include/StructLeetcode.h"

struct ListNode *middleNode(struct ListNode *head)
{
    if (head->next == NULL)
    {
        return head;
    }
    ListNode *slow = head->next;
    int n = 0;
    while (head)
    {
        if (n % 2 == 0)
        {
            slow = slow->next;
        }
        head = head->next;
    }
    return slow;
}

int main(int argc, char const *argv[])
{
    /* code */
    ListNode *head = createListNodeW(1, createListNodeW(2, createListNodeW(3, createListNodeW(4, createListNodeW(5, createListNode(6))))));
    ListNode *head1 = createListNodeW(1, createListNodeW(2, createListNodeW(3, createListNodeW(4, createListNode(5)))));
    ListNode *res = middleNode(head1);
    return 0;
}
