/* compile with: gcc -std=c11 knap.c -o knap */
#include <stdio.h>

int knap(int items, int size, int obj[][4])
{
    if (items == 0 || size == 0)
        return 0;

    int idx = items - 1; // use 0-based index
    int wt = obj[1][idx];
    int val = obj[0][idx];

    if (wt <= size)
    {
        int no = knap(items - 1, size, obj);
        int yes = knap(items - 1, size - wt, obj) + val;
        return no > yes ? no : yes;
    }
    else
    {
        return knap(items - 1, size, obj);
    }
}

int main(void)
{
    int obj[][4] = {
        {6, 5, 3, 8}, // values
        {1, 2, 1, 20} // weights
    };

    printf("%d\n", knap(4, 5, obj)); // expected result subject to items/weights
    return 0;
}
