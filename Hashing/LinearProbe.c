#include <stdio.h>
#define size 10

int _hash(int H[], int key)
{
    return key % size;
}

int _probe(int H[], int key)
{
    int index = _hash(H, key);
    int i = 0;

    while (H[(index + i) % size] != 0)
        i++;

    return (index + i) % size;
}

void _insert(int H[], int key)
{
    int index = _hash(H, key);

    if (H[index] != 0)
        index = _probe(H, key);
    H[index] = key;
}

int _search(int H[], int key)
{
    int index = _hash(H, key);

    int i = 0;
    while (H[(index + i) % size] != key)
        i++;
    return (index + i) % size;
}

int main()
{
    int H[10] = {0};

    _insert(H, 25);
    _insert(H, 55);
    _insert(H, 66);

    int temp = _search(H, 55);
    temp = _search(H, 100);
}