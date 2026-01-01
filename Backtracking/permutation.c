#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void perm(char *str, char *res, bool *sel, int n, int k)
{
    if (n == k)
    {
        res[k] = '\0';
        printf("%s\n", res);
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (!sel[i])
        {
            res[k] = str[i];
            sel[i] = true;
            perm(str, res, sel, n, k + 1);
            sel[i] = false;
        }
    }
}

int main()
{
    char str[100];

    printf("Enter the string to check its permutations:\n");
    scanf("%s", str);
    printf("\n");

    int strsize = strlen(str);

    char *res = malloc(strsize + 1);
    bool *sel = malloc(strsize * sizeof(bool));

    for (int i = 0; i < strsize; i++)
        sel[i] = false;

    perm(str, res, sel, strsize, 0);

    free(res);
    free(sel);
}
