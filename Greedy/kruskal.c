#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct disjoint
{
    int size;
    int *subset;

    disjoint(int size)
    {
        this->size = size;
        subset = (int *)malloc(sizeof(int) * size);
        for (int i = 0; i < size; i++)
            subset[i] = -1; // each element is its own set, size = 1
    }

    int find(int u)
    {
        int x = u;
        while (subset[x] > 0) // while x is not a root
        {
            x = subset[x]; // go to parent
        }
        return x; // root index
    }

    void uni(int u, int v)
    {
        u = find(u);
        v = find(v);
        if (u == v)
            return; // already in same set

        // union by size (more negative = bigger set)
        if (subset[u] < subset[v])
        {
            subset[u] += subset[v]; // new size
            subset[v] = u;          // v’s root points to u
        }
        else
        {
            subset[v] += subset[u];
            subset[u] = v;
        }
    }

    void display()
    {
        for (int i = 0; i < size; i++)
            printf("%d\t", subset[i]);
        printf("\n");
    }
};

struct selected
{
    int size;
    bool *select;

    selected(int size)
    {
        this->size = size;
        select = (bool *)malloc(sizeof(bool) * size);
        for (int i = 0; i < size; i++)
            select[i] = false;
    }
};

// ---------- Min-heap on edges, 1-based indices ----------

void insert(int edges[][9], int idx)
{
    int i = idx;

    int temp0 = edges[0][i]; // u
    int temp1 = edges[1][i]; // v
    int temp2 = edges[2][i]; // w (key)

    // Bubble up in min-heap by weight (row 2)
    while (i > 1 && temp2 < edges[2][i / 2])
    {
        edges[0][i] = edges[0][i / 2];
        edges[1][i] = edges[1][i / 2];
        edges[2][i] = edges[2][i / 2];
        i = i / 2;
    }

    edges[0][i] = temp0;
    edges[1][i] = temp1;
    edges[2][i] = temp2;
}

void deleteMin(int edges[][9], int size)
{
    // Save root (min edge)
    int x0 = edges[0][1];
    int x1 = edges[1][1];
    int x2 = edges[2][1];

    // Move last element to root
    edges[0][1] = edges[0][size];
    edges[1][1] = edges[1][size];
    edges[2][1] = edges[2][size];

    // Put original root at the end (sorted part)
    edges[0][size] = x0;
    edges[1][size] = x1;
    edges[2][size] = x2;

    int heapSize = size - 1; // new heap is [1..heapSize]

    int i = 1;
    int j = 2 * i;

    // Sift down in min-heap
    while (j <= heapSize)
    {
        // Pick smaller child
        if (j + 1 <= heapSize && edges[2][j + 1] < edges[2][j])
        {
            j = j + 1;
        }

        if (edges[2][i] > edges[2][j])
        {
            int temp;

            temp = edges[0][i];
            edges[0][i] = edges[0][j];
            edges[0][j] = temp;

            temp = edges[1][i];
            edges[1][i] = edges[1][j];
            edges[1][j] = temp;

            temp = edges[2][i];
            edges[2][i] = edges[2][j];
            edges[2][j] = temp;

            i = j;
            j = 2 * j;
        }
        else
        {
            break;
        }
    }
}

void heapSort(int edges[][9], int size)
{
    // Build min-heap on indices 1..size
    for (int i = 2; i <= size; i++)
        insert(edges, i);

    // Extract min one by one to the end
    for (int i = size; i > 1; i--)
        deleteMin(edges, i);
    // Result: edges[2][1..size] is sorted in **descending** order
    // (largest at index 1, smallest at index size)
}

// ---------- Kruskal using sorted edges + DSU ----------

int kruskal(int edges[][9], int edgeCount, int vertexCount)
{
    // vertices are 1..vertexCount
    disjoint subset(vertexCount + 1); // +1 to use index == vertex
    int minCost = 0;
    int mstEdges = 0;

    heapSort(edges, edgeCount);
    // After heapSort: edges[2][1] = largest, edges[2][edgeCount] = smallest.

    // Process edges from smallest weight to largest:
    for (int i = edgeCount; i >= 1 && mstEdges < vertexCount - 1; i--)
    {
        int u = edges[0][i];
        int v = edges[1][i];
        int w = edges[2][i];

        if (subset.find(u) != subset.find(v))
        {
            subset.uni(u, v);
            minCost += w;
            mstEdges++;
        }
    }

    return minCost;
}

int main()
{
    // We'll ignore column 0; use indices 1..8
    int edges[3][9] = {
        // u:
        {0, 1, 1, 2, 2, 3, 4, 4, 5},
        // v:
        {0, 2, 6, 3, 7, 4, 5, 7, 7},
        // w (weights):
        {0, 25, 10, 16, 14, 12, 22, 18, 24}};

    int edgeCount = 8;   // edges[?][1..8]
    int vertexCount = 7; // vertices 1..7 appear

    int cost = kruskal(edges, edgeCount, vertexCount);
    printf("MST cost = %d\n", cost);

    return 0;
}
