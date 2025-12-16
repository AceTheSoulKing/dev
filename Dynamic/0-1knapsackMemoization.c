#include <stdio.h>

int knap(int n, int m, int p[], int w[], int T[][6])
{
    if (n == 0 || m == 0)
    {
        return T[n][m] = 0;
    }

    if (T[n][m] != -1)
    {
        return T[n][m];
    }

    int idx = n - 1; // use 0-based index for item n
    if (w[idx] <= m)
    {
        int no = knap(n - 1, m, p, w, T);
        int yes = knap(n - 1, m - w[idx], p, w, T) + p[idx]; // add profit
        return T[n][m] = (no > yes ? no : yes);
    }
    else
    {
        return T[n][m] = knap(n - 1, m, p, w, T);
    }
}

int main(void)
{
    int sack_capacity = 5;

    int p[] = {6, 5, 3, 8};           // profits
    int w[] = {1, 2, 1, 2};           // weights
    int n = sizeof(p) / sizeof(p[0]); // number of items (4)

    // T must be (n+1) x (capacity+1). Here capacity is 5 so second dim is 6.
    int T[5][6]; // since n=4, n+1 = 5 ; capacity=5 -> 6
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= sack_capacity; ++j)
            T[i][j] = -1;

    int result = knap(n, sack_capacity, p, w, T);
    printf("Max profit = %d\n", result);

    return 0;
}
