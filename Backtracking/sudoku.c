#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isValid(int *S, int row, int col, int val)
{
    for (int i = 1; i <= 9; i++)
        if (S[row * 10 + i] == val)
            return false;

    for (int i = 1; i <= 9; i++)
        if (S[i * 10 + col] == val)
            return false;

    int blockRow = row - (row - 1) % 3;
    int blockCol = col - (col - 1) % 3;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (S[(blockRow + i) * 10 + (blockCol + j)] == val)
                return false;
        }
    }
    return true;
}

void Sudoku(int *S, int row, int col)
{
    if (row > 9)
    {
        for (int i = 1; i <= 9; i++)
        {
            for (int j = 1; j <= 9; j++)
            {
                printf("%d\t", S[i * 10 + j]);
            }
            printf("\n");
        }
        return;
    }

    if (S[row * 10 + col] != 0)
    {
        Sudoku(S,
               col == 9 ? row + 1 : row,
               col == 9 ? 1 : col + 1);
    }
    else
    {
        for (int i = 1; i <= 9; i++)
        {
            if (isValid(S, row, col, i))
            {
                S[row * 10 + col] = i;
                Sudoku(S, col == 9 ? row + 1 : row, col == 9 ? 1 : col + 1);
                S[row * 10 + col] = 0;
            }
        }
    }
}

int main()
{
    int *S = malloc(sizeof(int) * 10 * 10);

    /* initialize all to 0 */
    for (int i = 0; i < 10 * 10; i++)
        S[i] = 0;

    /* Row 1 */
    S[1 * 10 + 1] = 5;
    S[1 * 10 + 2] = 3;
    S[1 * 10 + 5] = 7;

    /* Row 2 */
    S[2 * 10 + 1] = 6;
    S[2 * 10 + 4] = 1;
    S[2 * 10 + 5] = 9;
    S[2 * 10 + 6] = 5;

    /* Row 3 */
    S[3 * 10 + 2] = 9;
    S[3 * 10 + 3] = 8;
    S[3 * 10 + 8] = 6;

    /* Row 4 */
    S[4 * 10 + 1] = 8;
    S[4 * 10 + 5] = 6;
    S[4 * 10 + 9] = 3;

    /* Row 5 */
    S[5 * 10 + 1] = 4;
    S[5 * 10 + 4] = 8;
    S[5 * 10 + 6] = 3;
    S[5 * 10 + 9] = 1;

    /* Row 6 */
    S[6 * 10 + 1] = 7;
    S[6 * 10 + 5] = 2;
    S[6 * 10 + 9] = 6;

    /* Row 7 */
    S[7 * 10 + 2] = 6;
    S[7 * 10 + 7] = 2;
    S[7 * 10 + 8] = 8;

    /* Row 8 */
    S[8 * 10 + 4] = 4;
    S[8 * 10 + 5] = 1;
    S[8 * 10 + 6] = 9;
    S[8 * 10 + 9] = 5;

    /* Row 9 */
    S[9 * 10 + 5] = 8;
    S[9 * 10 + 8] = 7;
    S[9 * 10 + 9] = 9;

    Sudoku(S, 1, 1);

    free(S);
}