#include <stdio.h>

int max(int a, int b)
{
    return a > b ? a : b;
}

int LCS(int m, int n, char A[], char B[], int i, int j, int L[][6])
{
    if (i == 0 || j == 0)
    {
        L[i][j] = 0;
        return 0;
    }

    if (L[i][j] != -1)
        return L[i][j];

    if (A[i] == B[j])
        L[i][j] = 1 + LCS(m, n, A, B, i - 1, j - 1, L);
    else
        L[i][j] = max(
            LCS(m, n, A, B, i - 1, j, L),
            LCS(m, n, A, B, i, j - 1, L));

    return L[i][j];
}

int main()
{
    char A[] = {'\0', 'a', 'c', 'e'};
    char B[] = {'\0', 'a', 'b', 'c', 'd', 'e'};

    int i = sizeof(A) / sizeof(A[0]) - 1; // 3
    int j = sizeof(B) / sizeof(B[0]) - 1; // 5

    int L[4][6];

    for (int a = 0; a <= i; a++)
        for (int b = 0; b <= j; b++)
            L[a][b] = -1;

    LCS(i, j, A, B, i, j, L);

    for (int a = 0; a <= i; a++)
    {
        for (int b = 0; b <= j; b++)
            printf("%d\t", L[a][b]);
        printf("\n");
    }
}
