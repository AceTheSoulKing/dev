#include <stdio.h>
#include <stdlib.h>
#include <iostream>

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

int main()
{
    int a[] = {10, 100, 1000, 10000, 100000, 1000000, 10000000};
    create(a, 7);

    recurDisplay(first);
    std::cout << std::endl;

    /*
    int count = rCount(first);
    std::cout << "Number of nodes are " << count << std::endl;
    */

    int sum_e = sum(first);
    std::cout << "Sum of all elements in the linked list : " << sum_e << std::endl;

    int r_sum = rSum(first);
    std::cout << "Sum of elements in linked list is {recursive} :" << r_sum << std::endl;

    return 0;
}
