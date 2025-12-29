#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int _subArraySum(int A[], int n)
{
    int max = INT_MIN;
    int *sum = (int *)malloc(sizeof(int) * n);
    sum[0] = A[0];

    for (int i = 1; i < n; i++)
    {
        if (sum[i - 1] < 0)
        {
            sum[i] = A[i];
        }
        else
        {
            sum[i] = sum[i - 1] + A[i];
        }
    }

    for (int i = 0; i < n; i++)
        if (max < sum[i])
            max = sum[i];

    return max;
}

int main()
{
    int A[] = {4, -5, 8, -2, -1, 7, -6};
    int no_of_elements = sizeof(A) / sizeof(A[0]);

    int result = _subArraySum(A, no_of_elements);
    printf("%d\t", result);
}