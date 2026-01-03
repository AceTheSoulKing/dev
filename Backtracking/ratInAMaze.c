#include <stdio.h>
#include <stdlib.h>

void rat(int N, int path, int i, int j, int *M, int *sol)
{
    int dim = N + 1;

    if (i == N && j == N)
    {
        sol[2 * path] = i;
        sol[2 * path + 1] = j;

        printf("Path:\n");
        for (int k = 0; k <= path; k++)
            printf("(%d,%d) ", sol[2 * k], sol[2 * k + 1]);
        printf("\n\n");

        M[i * dim + j] = 0; // lock destination
        return;
    }

    M[i * dim + j] = 0;
    sol[2 * path] = i;
    sol[2 * path + 1] = j;
    path++;

    if (j + 1 <= N && M[i * dim + (j + 1)] == 1)
        rat(N, path, i, j + 1, M, sol);

    if (i + 1 <= N && M[(i + 1) * dim + j] == 1)
        rat(N, path, i + 1, j, M, sol);

    if (j - 1 >= 1 && M[i * dim + (j - 1)] == 1)
        rat(N, path, i, j - 1, M, sol);

    if (i - 1 >= 1 && M[(i - 1) * dim + j] == 1)
        rat(N, path, i - 1, j, M, sol);

    M[i * dim + j] = 1; // backtrack
}

int main()
{
    int N;
    printf("Enter the dimension of rat in a maze:\n");
    scanf("%d", &N);

    int dim = N + 1;

    int *M = malloc(sizeof(int) * dim * dim);
    int *sol = malloc(sizeof(int) * 2 * dim * dim);

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            M[i * dim + j] = 1;

    /* Obstacles (0 = blocked, 1 = free) */
    /* Flat indexing: M[row * dim + col] */

    M[1 * dim + 4] = 0;

    M[2 * dim + 1] = 0;
    M[2 * dim + 3] = 0;
    M[2 * dim + 5] = 0;

    M[3 * dim + 1] = 0;
    M[3 * dim + 3] = 0;
    M[3 * dim + 6] = 0;

    M[4 * dim + 4] = 0;
    M[4 * dim + 6] = 0;

    M[5 * dim + 2] = 0;
    M[5 * dim + 3] = 0;
    M[5 * dim + 4] = 0;
    M[5 * dim + 6] = 0;
    M[5 * dim + 7] = 0;

    M[6 * dim + 4] = 0;

    M[7 * dim + 1] = 0;
    M[7 * dim + 2] = 0;
    M[7 * dim + 6] = 0;

    rat(N, 0, 1, 1, M, sol);

    free(M);
    free(sol);
}
