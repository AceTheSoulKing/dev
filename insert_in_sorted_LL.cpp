#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <climits>

struct Node
{
    int data;
    struct Node *Next;
};

struct Node *first = NULL;
struct Node *last = NULL;

void insertLast(int value)
{
    struct Node *t = new Node();
    t->data = value;
    t->Next = NULL;

    if (first == NULL)
    {
        first = last = t;
    }
    else
    {
        last->Next = t;
        last = t;
    }
}

void recurDisplay(struct Node *p)
{
    if (p != NULL)
    {
        printf("%d ", p->data);
        recurDisplay(p->Next);
    }
}

void insertSorted(int value)
{
    struct Node *t = new Node();
    t->data = value;
    t->Next = NULL;

    // Case 1: Empty list
    if (first == NULL)
    {
        first = last = t;
        return;
    }

    struct Node *p = first;
    struct Node *q = NULL;

    // Find position to insert
    while (p != NULL && p->data < value)
    {
        q = p;
        p = p->Next;
    }

    // Case 2: insert at beginning
    if (q == NULL)
    {
        t->Next = first;
        first = t;
    }
    else
    {
        // Case 3: insert in middle or end
        t->Next = q->Next;
        q->Next = t;

        // If inserted at the end, update 'last'
        if (q == last)
            last = t;
    }
}

int main()
{
    insertLast(10);
    insertLast(15);
    insertLast(150);

    insertSorted(5);
    insertSorted(1000);
    insertSorted(50);

    recurDisplay(first);
    return 0;
}
