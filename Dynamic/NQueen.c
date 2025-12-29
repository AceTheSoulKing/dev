#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool valid(int *x, int k, int l)
{
    for (int i = 1; i < k; i++)
    {
        if (x[i] == l || abs(i - k) == abs(x[i] - l))
            return false;
    }
    return true;
}

void NQueen(int *x, int n, int k)
{
    if (k > n)
    {
        // one solution found
        for (int i = 1; i <= n; i++)
            printf("%d ", x[i]);
        printf("\n");
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        if (valid(x, k, i))
        {
            x[k] = i;
            NQueen(x, n, k + 1);
        }
    }
}

int main()
{
    int n;
    printf("Enter how many queens: ");
    scanf("%d", &n);

    int *x = malloc(sizeof(int) * (n + 1));

    NQueen(x, n, 1);

    free(x);
    return 0;
}
