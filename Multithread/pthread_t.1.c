#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *task(void *arg)
{
    int value = *(int *)arg;
    free(arg);
    return NULL;
}

int main()
{
    int *x = malloc(sizeof(int));
    *x = 5;
    pthread_t t;
    pthread_create(&t, NULL, task, x);
    pthread_join(t, NULL);

    return 0;
}