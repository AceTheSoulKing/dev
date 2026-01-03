#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void perm(char *str, bool *sel, char *res, int n, int k)
{
    if (k == n)
    {
        for (int i = 0; i < n; i++)
            printf("%c", res[i]);
        printf("\n");
        return;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (sel[i] == false)
            {
                if (k > 0 && str[i] - res[k - 1] == 1)
                    continue;
                res[k] = str[i];
                sel[i] = true;
                perm(str, sel, res, n, k + 1);
                sel[i] = false;
            }
        }
    }
}

int main()
{
    char str[100];
    printf("Enter the words to check permutations of it with some bounding conditions\n");
    scanf("%s", str);
    printf("\n");

    int size_of_the_input_string = strlen(str);

    bool *sel = malloc(sizeof(bool) * (size_of_the_input_string));
    for (int i = 0; i < size_of_the_input_string; i++)
        sel[i] = false;

    char *res = malloc(sizeof(char) * (size_of_the_input_string + 1));

    perm(str, sel, res, size_of_the_input_string, 0);

    free(sel);
    free(res);
}