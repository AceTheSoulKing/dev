#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *Next;
} *first = NULL;

void create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0]; // starting with array's first element
    first->Next = NULL;
    last = first;

    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->Next = NULL;
        last->Next = t;
        last = t;
    }
}

void display(struct Node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->Next;
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

int main()
{
    int a[] = {10, 100, 1000, 10000, 100000, 1000000, 10000000};
    create(a, 7);

    recurDisplay(first);

    return 0;
}