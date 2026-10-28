
#include <stdio.h>
#include <limits.h>

#define N 4
#define M 5
#define INF INT_MAX

// Adjacency List
typedef struct {
    int to;
    int weight;
    int next;
} Edge;

Edge edges[M];
int head[N];
int edgeCount = 0;

// Deque state
typedef struct {
    int vertex;
    int parity;
} State;

State deque[2 * N * M + 10];
int front = 0, rear = 0, size = 0;

int dist[N][2];

// Add an edge without dynamic memory
void addEdge(int u, int v, int w) {
    edges[edgeCount].to = v;
    edges[edgeCount].weight = w;
    edges[edgeCount].next = head[u];

    head[u] = edgeCount;
    edgeCount++;
}

// Initialize graph and distances
void initialize() {
    for (int i = 0; i < N; i++) {
        head[i] = -1;
        dist[i][0] = INF;
        dist[i][1] = INF;
    }
}

// Deque operations
void pushFront(State s) {
    front = (front - 1 + 2 * N * M + 10)
            % (2 * N * M + 10);
    deque[front] = s;
    size++;
}

void pushBack(State s) {
    deque[rear] = s;
    rear = (rear + 1) % (2 * N * M + 10);
    size++;
}

State popFront() {
    State s = deque[front];
    front = (front + 1) % (2 * N * M + 10);
    size--;
    return s;
}

// 0-1 BFS
void shortestPath(int source) {
    dist[source][0] = 0;
    pushBack((State){source, 0});

    while (size > 0) {
        State current = popFront();

        int u = current.vertex;
        int p = current.parity;

        for (int i = head[u]; i != -1; i = edges[i].next) {
            int v = edges[i].to;
            int w = edges[i].weight;

            int nextParity = p ^ w;
            int newDist = dist[u][p] + w;

            if (newDist < dist[v][nextParity]) {
                dist[v][nextParity] = newDist;

                State next = {v, nextParity};

                if (w == 0)
                    pushFront(next);
                else
                    pushBack(next);
            }
        }
    }
}

// Print minimum cost with odd-parity penalty
void printResults(int penalty) {
    for (int i = 0; i < N; i++) {
        int evenCost = dist[i][0];
        int oddCost = dist[i][1];

        if (oddCost != INF)
            oddCost += penalty;

        int bestCost = evenCost < oddCost
                     ? evenCost : oddCost;

        printf("Vertex %d: ", i);

        if (bestCost == INF)
            printf("Unreachable\n");
        else
            printf("Minimum cost = %d\n", bestCost);
    }
}

int main() {
    int source = 0;
    int penalty = 3;

    initialize();

    // Fixed directed graph
    addEdge(0, 1, 1);
    addEdge(0, 2, 0);
    addEdge(1, 2, 1);
    addEdge(1, 3, 0);
    addEdge(2, 3, 1);

    shortestPath(source);
    printResults(penalty);

    return 0;
}
