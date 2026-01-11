#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int counter = 0;

void *increment(void *arg)
{
    int i = 0;
    while (i < 1000000)
    {
        counter++;
        i++;
    }
}

int main()
{
    pthread_t t1, t2;

    pthread_create(&t1, NULL, increment, NULL);
    pthread_create(&t2, NULL, increment, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Final counter value is %d\t", counter);

    return 0;
}