#include <stdio.h>

void Sort(double p[][5], int size)
{
    int i;
    int j;

    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - i - 1; j++)
        {
            double r1 = p[0][j] / p[1][j];
            double r2 = p[0][j + 1] / p[1][j + 1];

            if (r1 < r2)
            {
                double temp = p[0][j];
                p[0][j] = p[0][j + 1];
                p[0][j + 1] = temp;

                temp = p[1][j];
                p[1][j] = p[1][j + 1];
                p[1][j + 1] = temp;
            }
        }
    }
}

double knapSack(double p[][5], int m, int n)
{
    Sort(p, n);
    double profit = 0;

    for (int i = 0; i < n; i++)
    {
        if (p[1][i] <= m)
        {
            profit += p[0][i];
            m -= p[1][i];
        }
        else
        {
            profit += p[0][i] * m / p[1][i];
            break;
        }
    }
    return profit;
}

int main()
{
    double p[][5] = {{12, 5, 21, 17, 3}, {1, 2, 3, 2, 1}};

    double profit = knapSack(p, 5, 5);

    printf("%f", profit);
}