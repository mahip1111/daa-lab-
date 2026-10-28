
#include <stdio.h>
#include <string.h>

#define N 6
#define L 4

// Dictionary list
char words[N][L] = {
    "hot", "dot", "dog", "lot", "log", "cog"
};

int main() {
    char start[] = "hot";
    char target[] = "cog";

    int dist[N], parent[N];
    int queue[N];
    int front = 0, rear = 0;
    int s = 0, t = 5;

    // Initialize
    for (int i = 0; i < N; i++) {
        dist[i] = -1;
        parent[i] = -1;
    }

    // Start BFS
    dist[s] = 0;
    queue[rear++] = s;

    while (front < rear) {
        int u = queue[front++];

        if (u == t)
            break;

        // Try changing each character
        char temp[L];
        strcpy(temp, words[u]);

        for (int pos = 0; pos < 3; pos++) {
            char old = temp[pos];

            for (char c = 'a'; c <= 'z'; c++) {
                if (c == old)
                    continue;

                temp[pos] = c;

                // Search the dictionary list
                for (int v = 0; v < N; v++) {
                    if (strcmp(temp, words[v]) == 0 &&
                        dist[v] == -1) {

                        dist[v] = dist[u] + 1;
                        parent[v] = u;
                        queue[rear++] = v;
                    }
                }
            }

            temp[pos] = old;
        }
    }

    // Print shortest path
    if (dist[t] == -1) {
        printf("No transformation possible\n");
    } else {
        int path[N], count = 0;

        int curr = t;

        while (curr != -1) {
            path[count++] = curr;
            curr = parent[curr];
        }

        printf("Minimum transformations: %d\n", dist[t]);
        printf("Path: ");

        for (int i = count - 1; i >= 0; i--) {
            printf("%s", words[path[i]]);

            if (i > 0)
                printf(" -> ");
        }

        printf("\n");
    }

    return 0;
}
