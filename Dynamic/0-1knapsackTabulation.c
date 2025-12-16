#include <stdio.h>

int max(int a, int b)
{
    return a > b ? a : b;
}

void knap(int n, int m, int p[], int w[], int T[][6])
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (w[i] <= j)
                T[i][j] = max(T[i - 1][j],
                              T[i - 1][j - w[i]] + p[i]);
            else
                T[i][j] = T[i - 1][j];
        }
    }
}

int main()
{
    int sack_cap = 5;

    // 1-based indexing
    int price[] = {0, 6, 5, 3, 8};
    int weight[] = {0, 1, 2, 1, 2};
    int n = 4;

    int T[5][6] = {0}; // (n+1) x (capacity+1)

    knap(n, sack_cap, price, weight, T);

    // Print DP table
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sack_cap; j++)
            printf("%d\t", T[i][j]);
        printf("\n");
    }

    printf("\nMax Profit = %d\n", T[n][sack_cap]);
}
