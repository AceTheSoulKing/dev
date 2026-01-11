#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

typedef struct task
{
    void (*function)(int);
    int arg;
    struct task *next;
} task_t;

task_t *task_queue = NULL;

pthread_mutex_t lock;
pthread_cond_t cond;

void add_task(void (*func)(int), int arg)
{
    task_t *task = malloc(sizeof(task_t));
    task->function = func;
    task->arg = arg;
    task->next = NULL;

    pthread_mutex_lock(&lock);

    task->next = task_queue;
    task_queue = task;

    pthread_cond_signal(&cond);

    pthread_mutex_unlock(&lock);
}

void *worker(void *arg)
{
    while (1)
    {
        pthread_mutex_lock(&lock);

        while (task_queue == NULL)
            pthread_cond_wait(&cond, &lock);

        task_t *task = task_queue;
        task_queue = task_queue->next;

        pthread_mutex_unlock(&lock);

        task->function(task->arg);
        free(task);
    }
}

void print_number(int x)
{
    printf("Thread %ld executing task %d\n", pthread_self(), x);
    sleep(1);
}

int main()
{
    pthread_t threads[3];

    pthread_mutex_init(&lock, NULL);
    pthread_cond_init(&cond, NULL);

    for (int i = 0; i < 3; i++)
        pthread_create(&threads[i], NULL, worker, NULL);

    for (int i = 0; i < 10; i++)
        add_task(print_number, i);

    sleep(5);
}