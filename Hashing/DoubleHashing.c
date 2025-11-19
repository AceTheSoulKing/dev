#include <stdio.h>

/* h1(x)=x%size,
   h2(x)=R-(x%R)   ---R is nearest prime number of size
   h'(x)=(h1(x)+i*h2(x))%size  i=0,1,2,3
*/

#define size 10

int _isPrime(int num)
{
    if (num < 2)
        return 0;

    int i;
    for (i = 2; i * i <= num; i++)
        if (num % i == 0)
            return 0;

    return 1;
}

int _Nearestprime(int n)
{
    int i;
    for (i = n - 1; i >= 2; i--)
        if (_isPrime(i))
            return i;

    return -1;
}

int _hash(int key)
{
    return key % size;
}

int _hash2(int key)
{
    int R = _Nearestprime(size);

    int h = R - (key % R);
    if (h == 0)
        h = 1; // ensure non-zero step

    return h;
}

void _doubleHashing(int H[], int key)
{
    int i = 1;
    int index = (_hash(key) + i * _hash2(key)) % size;

    while (H[index] != 0)
    {
        i++;
        index = (_hash(key) + i * _hash2(key)) % size;
    }
    H[index] = key;
}

void _insert(int H[], int key)
{
    int index = _hash(key);

    if (H[index] == 0)
    {
        H[index] = key;
        return;
    }

    _doubleHashing(H, key);
}

int main()
{
    int H[10] = {0};

    _insert(H, 5);
    _insert(H, 25);
    _insert(H, 15);
    _insert(H, 35);
    _insert(H, 95);
}