#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *worker(void *arg)
{
    while (1)
    {
        printf("Thread id %ld is waiting", pthread_self());
        sleep(2);
    }
    return NULL;
}

int main()
{
    pthread_t threads[3];

    for (int i = 0; i < 3; i++)
        pthread_create(&threads[i], NULL, worker, NULL);

    pthread_join(threads[0], NULL);
}