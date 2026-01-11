#include <stdio.h>
#include <pthread.h>

int counter = 0;

void *printA(void *arg)
{
    for (int i = 0; i <= 5; i++)
    {
        printf("Thread A: %d\n", i);
    }
    return NULL;
}

void *printB(void *arg)
{
    for (int i = 0; i <= 5; i++)
    {
        printf("Thread B: %d\n", i);
    }
    return NULL;
}

int main()
{
    pthread_t t1, t2;

    pthread_create(&t1, NULL, printA, NULL);
    pthread_create(&t2, NULL, printB, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Main finished\n");

    return 0;
}