
#include <stdio.h>

#define V 6
#define K 2
#define R 2

// Adjacency list
int graph[V][V] = {
    {1, 2},     // Vertex 1 connects to 2, 3
    {0, 3},     // Vertex 2 connects to 1, 4
    {0, 3},     // Vertex 3 connects to 1, 4
    {1, 2, 4},  // Vertex 4 connects to 2, 3, 5
    {3, 5},     // Vertex 5 connects to 4, 6
    {4}         // Vertex 6 connects to 5
};

int degree[V] = {2, 2, 2, 3, 2, 1};

int main() {
    int hubs[K] = {0, 5};  // Vertices 1 and 6

    int dist[V], owner[V];
    int queue[V], front = 0, rear = 0;

    // Initialize
    for (int i = 0; i < V; i++) {
        dist[i] = -1;
        owner[i] = -1;
    }

    // Add all hubs to the queue
    for (int i = 0; i < K; i++) {
        int h = hubs[i];
        dist[h] = 0;
        owner[h] = i + 1;
        queue[rear++] = h;
    }

    // Multi-Source BFS
    while (front < rear) {
        int u = queue[front++];

        if (dist[u] == R)
            continue;

        for (int i = 0; i < degree[u]; i++) {
            int v = graph[u][i];

            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                owner[v] = owner[u];
                queue[rear++] = v;
            }
        }
    }

    // Print results
    printf("Vertex  Distance  Hub\n");

    for (int i = 0; i < V; i++) {
        if (dist[i] != -1 && dist[i] <= R)
            printf("%d       %d         %d\n",
                   i + 1, dist[i], owner[i]);
        else
            printf("%d       -1        Unassigned\n", i + 1);
    }

    return 0;
}
