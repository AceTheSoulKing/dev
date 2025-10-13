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

void deleteNode(struct Node *p, int value)
{
    struct Node *n, *m;
    n = p;
    m = NULL;

    while (n != NULL)
    {
        if (n->data == value)
        {
            if (n == first)
            {
                p = p->Next;
                delete n;
                return;
            }
            else
            {
                m->Next = n->Next;
                if (n == last)
                {
                    last = m;
                }
                delete n;
                return;
            }
        }
        m = n;
        n = n->Next;
    }
}

int main()
{

    insertLast(10);
    insertLast(15);
    insertLast(150);

    recurDisplay(first);

    deleteNode(first, 15);

    recurDisplay(first);

    return 0;
}