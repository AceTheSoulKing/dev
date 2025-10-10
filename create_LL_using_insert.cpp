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
    struct Node *t;

    t = new Node();
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
        printf("\n%d\n ", p->data);
        recurDisplay(p->Next);
    }
}

int main()
{

    insertLast(10);
    insertLast(15);
    insertLast(150);

    recurDisplay(first);

    return 0;
}