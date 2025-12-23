#include <stdio.h>

int max(int a, int b)
{
    return a > b ? a : b;
}

int LCS(char A[], char B[], int n, int m)
{

    int L[n + 1][m + 1];

    for (int i = 0; i <= n; i++)
        L[i][0] = 0;

    for (int j = 0; j <= m; j++)
        L[0][j] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (A[i] == B[j])
                L[i][j] = 1 + L[i - 1][j - 1];
            else
                L[i][j] = max(L[i][j - 1], L[i - 1][j]);
        }
    }
    return L[n][m];
}

int main()
{
    char A[] = {'\0', 'a', 'c', 'e'};
    char B[] = {'\0', 'a', 'b', 'c', 'd', 'e'};

    int n = sizeof(A) / sizeof(A[0]) - 1;
    int m = sizeof(B) / sizeof(B[0]) - 1;

    printf("%d\n", LCS(A, B, n, m));
}