#include <stdio.h>

int kadaneMaxSub(int A[], int n)
{
    int max = A[0];
    int prevSubSum = A[0];
    int start = 0, end = 0, subStart = 0;

    for (int i = 1; i < n; i++)
    {
        if (prevSubSum < 0)
        {
            prevSubSum = A[i];
            subStart = i;
        }
        else
        {
            prevSubSum = prevSubSum + A[i];
        }
        if (max < prevSubSum)
        {
            max = prevSubSum;
            start = subStart;
            end = i;
        }
    }

    for (int i = start; i <= end; i++)
        printf("%d ", A[i]);
    printf("\n");

    return max;
}

int main()
{
    int A[] = {4, -5, 8, -2, -1, 7, -6};
    int no_of_elements = sizeof(A) / sizeof(A[0]);

    int result = kadaneMaxSub(A, no_of_elements);
    printf("%d\t", result);
}