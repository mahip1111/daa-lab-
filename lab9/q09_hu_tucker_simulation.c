/* DAA Lab 09 - Q9: Hu-Tucker educational simulation
   NOTE: This is NOT a full Hu-Tucker implementation. It shows a basic
   adjacent-merge simulation that preserves order, for learning only.
   A correct optimal alphabetic tree requires the actual Hu-Tucker algorithm.
*/
#include <stdio.h>

int main(void) {
    int n, i, j, best;
    long long w[100], total = 0;
    int active[100];

    printf("Number of ordered weights (max 100): ");
    scanf("%d", &n);
    if (n < 2 || n > 100) return 0;
    for (i = 0; i < n; i++) {
        printf("Weight %d: ", i + 1);
        scanf("%lld", &w[i]);
        active[i] = 1;
    }

    printf("\nAdjacent-merge simulation (educational, not guaranteed optimal):\n");
    for (int count = n; count > 1; count--) {
        best = -1;
        for (i = 0; i < n - 1; i++) {
            if (active[i] && active[i + 1]) {
                if (best == -1 || w[i] + w[i + 1] < w[best] + w[best + 1])
                    best = i;
            }
        }
        if (best == -1) break;
        long long sum = w[best] + w[best + 1];
        printf("Merge adjacent weights %lld and %lld -> %lld\n",
               w[best], w[best + 1], sum);
        total += sum;
        w[best] = sum;
        active[best + 1] = 0;
        /* Compact active sequence to keep the next merge adjacent. */
        for (j = best + 1; j < n - 1; j++) {
            if (active[j + 1]) { w[j] = w[j + 1]; active[j] = 1; }
        }
    }
    printf("Simulation merge cost = %lld\n", total);
    printf("Reminder: use a verified Hu-Tucker algorithm for the exact lab requirement.\n");
    return 0;
}
