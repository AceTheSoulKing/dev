#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *Next;
};

void _insert(struct Node *h[], int index, int value)
{
    struct Node *q = (struct Node *)malloc(sizeof(struct Node));
    q->data = value;
    q->Next = NULL;

    // Case 1: bucket empty OR insert at head
    if (h[index] == NULL || h[index]->data > value)
    {
        q->Next = h[index];
        h[index] = q;
        return;
    }

    // Case 2: insert inside list
    struct Node *p = h[index];

    while (p->Next != NULL && p->Next->data < value)
        p = p->Next;

    q->Next = p->Next;
    p->Next = q;
}

void _search(struct Node *h[], int index, int value)
{
    if (h[index] == NULL)
    {
        printf("Bucket empty\n");
        return;
    }

    struct Node *p = h[index];

    while (p != NULL && p->data < value)
        p = p->Next;

    if (p != NULL && p->data == value)
        printf("%d found in bucket %d\n", value, index);
    else
        printf("%d not found\n", value);
}

void _delete(struct Node *h[], int index, int value)
{
    if (h[index] == NULL)
    {
        printf("Bucket empty\n");
        return;
    }

    struct Node *p = h[index];
    struct Node *q = NULL;

    // Find node
    while (p != NULL && p->data < value)
    {
        q = p;
        p = p->Next;
    }

    if (p != NULL && p->data == value)
    {
        // Deleting head node
        if (q == NULL)
            h[index] = p->Next;
        else
            q->Next = p->Next;

        free(p);
        printf("%d deleted\n", value);
    }
    else
        printf("%d not found to delete\n", value);
}

int main()
{
    struct Node *H[10]; // FIX: must be 10, not 9

    for (int i = 0; i < 10; i++)
        H[i] = NULL;

    // Test insert
    _insert(H, 5, 55);
    _insert(H, 5, 10);
    _insert(H, 5, 40);
    _insert(H, 5, 60);

    // Test search
    _search(H, 5, 55);
    _search(H, 5, 100);

    // Test delete
    _delete(H, 5, 40);
    _search(H, 5, 40);
}
