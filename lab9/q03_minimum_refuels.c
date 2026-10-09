/* DAA Lab 09 - Q3: Minimum refuelling stops (reverse greedy)
   At each step, choose the largest fuel among stations we already passed.
*/
#include <stdio.h>

typedef struct { int distance, fuel; } Station;

int main(void) {
    int n, i, target, fuel, current = 0, stops = 0;
    Station s[100];
    int used[100] = {0};

    printf("Number of stations (max 100): ");
    scanf("%d", &n);
    if (n < 0 || n > 100) return 0;
    printf("Target distance and starting fuel: ");
    scanf("%d %d", &target, &fuel);
    for (i = 0; i < n; i++) {
        printf("Station %d distance and fuel: ", i + 1);
        scanf("%d %d", &s[i].distance, &s[i].fuel);
    }

    while (current + fuel < target) {
        int farthestReach = current + fuel;
        int best = -1;
        for (i = 0; i < n; i++) {
            if (!used[i] && s[i].distance <= farthestReach &&
                s[i].distance > current) {
                /* We will consider reachable stations as possible past stops. */
                if (best == -1 || s[i].fuel > s[best].fuel) best = i;
            }
        }
        if (best == -1) {
            printf("Impossible to reach target.\n");
            return 0;
        }
        current = s[best].distance;
        fuel = farthestReach - current + s[best].fuel;
        used[best] = 1;
        stops++;
    }
    printf("Minimum refuelling stops (greedy simulation) = %d\n", stops);
    return 0;
}
