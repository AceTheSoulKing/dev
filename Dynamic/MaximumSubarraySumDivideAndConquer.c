#include <stdio.h>
#include <limits.h>

int crossSum(int A[], int low, int mid, int high)
{
    int leftSum = INT_MIN;
    int sum = 0;

    for (int i = mid; i >= low; i--)
    {
        sum += A[i];
        if (sum > leftSum)
            leftSum = sum;
    }

    sum = 0;
    int rightSum = INT_MIN;

    for (int i = mid + 1; i <= high; i++)
    {
        sum += A[i];
        if (sum > rightSum)
            rightSum = sum;
    }

    return leftSum + rightSum;
}

int maxSum(int A[], int l, int h)
{
    if (l == h)
        return A[l];

    int mid = (l + h) / 2;

    int leftSide = maxSum(A, l, mid);
    int rightSide = maxSum(A, mid + 1, h);
    int crossSide = crossSum(A, l, mid, h);

    int lr = leftSide > rightSide ? leftSide : rightSide;

    return lr > crossSide ? lr : crossSide;
}

int main()
{
    int A[] = {3, -7, 10, -2, -1, 7, 11, -5, 9, 3};
    int low = 0;
    int high = sizeof(A) / sizeof(A[0]) - 1;

    printf("Maximum Subarray sum is %d\n", maxSum(A, low, high));
}