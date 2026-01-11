#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t lock;
pthread_cond_t cond;

void *worker(void *arg)
{
    pthread_mutex_lock(&lock);

    while (1)
    {
        printf("Thread %ld sleeping...\n", pthread_self());
        pthread_cond_wait(&cond, &lock);
        printf("Thread %ld woke up!\n", pthread_self());
    }
    pthread_mutex_unlock(&lock);
    return NULL;
}

int main()
{
    pthread_t threads[3];

    pthread_mutex_init(&lock, NULL);
    pthread_cond_init(&cond, NULL);

    for (int i = 0; i < 3; i++)
        pthread_create(&threads[i], NULL, worker, NULL);

    sleep(1);

    printf("Main thread waking workers...\n");
    pthread_cond_broadcast(&cond);

    pthread_join(threads[0], NULL);
}