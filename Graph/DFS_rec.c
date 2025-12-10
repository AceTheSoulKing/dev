#include <stdio.h>

void DFS(int A[][5], int start, int n)
{
    static int visited[5] = {0};
    int j;

    if (visited[start] == 0)
    {
        printf("%d\n", start);
        visited[start] = 1;
    }

    for (j = 1; j <= n; j++)
    {
        if (A[start][j] == 1 && visited[j] == 0)
            DFS(A, j, n);
    }
}

int main()
{
    int A[5][5] = {
        {0, 0, 0, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0}};

    DFS(A, 2, 5);
}