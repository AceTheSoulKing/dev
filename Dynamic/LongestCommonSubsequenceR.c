#include <stdio.h>

int max(int a, int b)
{
    return a > b ? a : b;
}

int LCS(char A[], char B[], int i, int j)
{
    if (i == 0 || j == 0)
        return 0;

    if (A[i] == B[j])
        return 1 + (LCS(A, B, i - 1, j - 1));
    else
        return max(LCS(A, B, i - 1, j), LCS(A, B, i, j - 1));
}

int main()
{
    char A[] = {'\0', 'a', 'c', 't'};
    char B[] = {'\0', 'a', 'b', 'c', 'd', 'e'};

    int i = sizeof(A) / sizeof(A[0]) - 1;
    int j = sizeof(B) / sizeof(B[0]) - 1;

    printf("%d\n", LCS(A, B, i, j));
}