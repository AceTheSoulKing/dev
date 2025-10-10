#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <climits>

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

/*
This is iterative method to display the data from the linked list
void display(struct Node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->Next;
    }
}
*/
void recurDisplay(struct Node *p)
{
    if (p != NULL)
    {
        printf("%d ", p->data);
        recurDisplay(p->Next);
    }
}

/*
int count(struct Node *p) // Iterative count
{
    int c = 0;
    while (p != NULL)
    {
        c++;
        p = p->Next;
    }
    return c;
}

int rCount(struct Node *p) // Recursive count
{
    if (p == NULL)
    {
        return 0;
    }

    else
        return rCount(p->Next) + 1;
}
*/

/*
int sum(struct Node *p) // Iterative version of sum
{
    int sum = 0;

    while (p != NULL)
    {
        sum += p->data;
        p = p->Next;
    }
    // sum += p->data;

    return sum;
}

int rSum(struct Node *p) // Recursive version of sum
{
    if (p == NULL)
        return 0;

    else
        return rSum(p->Next) + p->data;
}
*/

int max(struct Node *p) // Iterative version of finding max element
{
    int m = INT_MIN;
    while (p)
    {
        if (p->data > m)
            m = p->data;

        p = p->Next;
    }
    return m;
}

int rMax(struct Node *p)
{
    int x = 0;

    if (p == NULL)
        return INT_MIN;

    else
    {
        x = rMax(p->Next);
        if (x > p->data)
            return x;

        else
            return p->data;
    }
}

struct Node *search(struct Node *p, int key)
{
    struct Node *q = NULL; // keeps track of the previous node

    while (p != NULL)
    {
        if (key == p->data)
        {
            // if not already at front, move to front
            if (q != NULL)
            {
                q->Next = p->Next;
                p->Next = first;
                first = p;
            }
            return p; // return the found node
        }

        q = p;
        p = p->Next;
    }

    return NULL; // not found
}

int main()
{
    int a[] = {10, 100, 1000, 10000, 100000, 1000000, 10000000};
    create(a, 7);

    recurDisplay(first);
    std::cout << std::endl;

    /*
    int count = rCount(first);
    std::cout << "Number of nodes are " << count << std::endl;


    int sum_e = sum(first);
    std::cout << "Sum of all elements in the linked list : " << sum_e << std::endl;

    int r_sum = rSum(first);
    std::cout << "Sum of elements in linked list is {recursive} :" << r_sum << std::endl;
    */
    /*
    int Max = max(first);
    std::cout << "Max element in linked list is {Iterative} : " << Max << std::endl;

    int _rMax = rMax(first);
    std::cout << "Max element in linked list is {Recursive} : " << _rMax << std::endl;
    */

    int key = 10000000;
    struct Node *fon = search(first, key);

    if (fon != NULL)
        std::cout << fon->data << std::endl;
    else
        std::cout << "No matching found " << std::endl;

    recurDisplay(first);

    return 0;
}
