#include <stdio.h>
#include <limits.h>

int _subArraySum(int A[], int n)
{
    int maximum = INT_MIN;
    int start, end;

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int sum = 0;
            for (int k = i; k <= j; k++)
            {
                sum += A[k];
            }
            if (sum > maximum)
            {
                maximum = sum;
                start = i;
                end = j;
            }
        }
    }

    printf("from index %d to index %d is the maximum subarray sum \n", start, end);
    return maximum;
}

int main()
{
    int A[] = {4, -5, 8, -2, -1, 7, -6};
    int no_of_elements = sizeof(A) / sizeof(A[0]);

    int result = _subArraySum(A, no_of_elements);
    printf("%d\t", result);
}