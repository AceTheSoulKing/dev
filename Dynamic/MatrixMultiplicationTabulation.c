#include <stdio.h>
#include <limits.h>

void mcm(int n, int d[], int T[][n])
{
    for (int i = 1; i <= n; i++)
        T[i][i] = 0;

    for (int diff = 1; diff < n; diff++)
    {
        for (int i = 1; i <= n - diff; i++)
        {
            int j = i + diff;
            T[i][j] = INT_MAX;
            for (int k = i; k < j; k++)
            {
                int cost = T[i][k] + T[k + 1][j] + d[i - 1] * d[k] * d[j];

                if (cost < T[i][j])
                    T[i][j] = cost;
            }
        }
    }
}

int main()
{
    int dimensions[] = {3, 2, 4, 2, 5};

    int tabulation_size = sizeof(dimensions) / sizeof(dimensions[0]);

    int T[tabulation_size][tabulation_size];

    mcm(tabulation_size, dimensions, T);

    for (int i = 0; i < tabulation_size; i++)
    {
        for (int j = 0; j < tabulation_size; j++)
            printf("%d\t", T[i][j]);
        printf("\n");
    }
}