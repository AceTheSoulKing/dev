#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int data;
    int size;
    int *stack;
    int top;

    Stack(int size)
    {
        this->size = size;
        stack = (int *)malloc(sizeof(int) * size);
        top = -1;
    }

    void
    push(int data)
    {
        if (top == size - 1)
        {
            printf("Stack is full\n");
            return;
        }

        this->stack[++top] = data;
    }

    int pop()
    {
        int x = -1;

        if (top < 0)
        {
            printf("Stack is Empty\n");
            return x;
        }

        x = this->stack[top--];
        return x;
    }

    int isEmpty()
    {
        return top == -1;
    }
};

void DFS(int A[][5], int start, int n)
{
    Stack st(10);
    int visited[5] = {0};

    st.push(start);

    while (!st.isEmpty())
    {
        int u = st.pop();

        if (visited[u] == 0)
        {
            printf("%d\n", u);
            visited[u] = 1;

            for (int v = n - 1; v >= 1; v--) // push neighbors reverse to mimic recursive DFS
            {
                if (A[u][v] == 1 && visited[v] == 0)
                    st.push(v);
            }
        }
    }
}

int main()
{
    int A[5][5] = {
        {0, 0, 0, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0}};

    DFS(A, 3, 5);
}