#include <stdio.h>
#include <pthread.h>

pthread_mutex_t lock;
pthread_cond_t cond;

int data = 0;
int ready = 0;

void *producer(void *arg)
{
    pthread_mutex_lock(&lock);

    data = 100;
    ready = 1;

    pthread_cond_signal(&cond);
    pthread_mutex_unlock(&lock);

    return NULL;
}

void *consumer(void *arg)
{
    pthread_mutex_lock(&lock);

    while (ready == 0)
        pthread_cond_wait(&cond, &lock);

    printf("Consumed data = %d \n", data);

    pthread_mutex_unlock(&lock);
    return NULL;
}

int main()
{
    pthread_t p, c;

    pthread_mutex_init(&lock, NULL);
    pthread_cond_init(&cond, NULL);

    pthread_create(&c, NULL, consumer, NULL);
    pthread_create(&p, NULL, producer, NULL);

    pthread_join(p, NULL);
    pthread_join(c, NULL);

    pthread_mutex_destroy(&lock);
    pthread_cond_destroy(&cond);

    return 0;
}