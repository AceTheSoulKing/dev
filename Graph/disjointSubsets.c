#include <stdio.h>

void _display(int S[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d\t", S[i]);
    printf("\n");
}

int _find(int s[], int u)
{
    int x = s[u];

    while (s[x] > 0)
        x = s[x];

    return x;
}

void _union(int s[], int u, int v)
{
    if (s[u] < s[v])
    {
        s[u] = s[u] + s[v];
        s[v] = u;
    }
    else
    {
        s[v] = s[v] + s[u];
        s[u] = v;
    }
    _display(s, 11);
}

int main()
{
    int s[11] = {-1};

    s[3] = -3;
    s[4] = -4;

    s[5] = 3;
    s[9] = 3;

    s[7] = 4;
    s[8] = 4;
    s[10] = 4;

    //_union(s, 3, 4);
    printf("%d\n", _find(s, 9));

    _union(s, 3, 4);
    printf("%d\n", _find(s, 9));
}