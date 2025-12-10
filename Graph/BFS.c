#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int size;
    int *Q;
    int front;
    int rear;

    Queue(int size)
    {
        this->size = size;
        Q = (int *)malloc(sizeof(int) * size);
        front = rear = -1;
    }

    void enqueue(int data)
    {
        if (rear == size - 1)
        {
            printf("Queue is full\n");
            return;
        }
        Q[++rear] = data;
    }

    int dequeue()
    {
        if (front == rear)
        {
            printf("Queue is empty\n");
            return -1;
        }
        return Q[++front];
    }

    int isEmpty()
    {
        return front == rear;
    }
};

void BFS(int A[][5], int start) // 1-based (index 1..4), so 5 columns
{
    Queue q(10);

    int u, v;
    int visited[5] = {0}; // index 0 unused

    printf("%d ", start);
    visited[start] = 1;
    q.enqueue(start);

    while (!q.isEmpty())
    {
        u = q.dequeue();

        for (v = 1; v <= 4; v++) // 1-based
        {
            if (A[u][v] == 1 && visited[v] == 0)
            {
                printf("%d ", v);
                visited[v] = 1;
                q.enqueue(v);
            }
        }
    }
}

int main()
{
    // 1-based adjacency matrix (index 1..4)
    int A[5][5] = {
        {0, 0, 0, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0}};

    BFS(A, 1);
}
