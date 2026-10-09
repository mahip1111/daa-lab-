/* DAA Lab 09 - Q1: Fractional Knapsack with Deterioration
   Beginner simulation. Assumption: time advances by the amount of weight taken.
   Compile: gcc q01_fractional_knapsack.c -o q01
*/
#include <stdio.h>

typedef struct {
    char name;
    double value, weight, decay;
} Item;

int main(void) {
    int n, i, used[100] = {0};
    double capacity, time = 0, totalValue = 0;
    Item a[100];

    printf("Number of items (max 100): ");
    scanf("%d", &n);
    if (n < 1 || n > 100) return 0;

    for (i = 0; i < n; i++) {
        printf("Item %d: symbol value weight decay_rate: ", i + 1);
        scanf(" %c %lf %lf %lf", &a[i].name, &a[i].value,
              &a[i].weight, &a[i].decay);
        if (a[i].weight <= 0) {
            printf("Weight must be positive.\n");
            return 0;
        }
    }
    printf("Knapsack capacity: ");
    scanf("%lf", &capacity);

    while (capacity > 1e-9) {
        int best = -1;
        double bestDensity = -1e100;
        for (i = 0; i < n; i++) {
            if (!used[i]) {
                double density = a[i].value / a[i].weight - a[i].decay * time;
                if (density > bestDensity) {
                    bestDensity = density;
                    best = i;
                }
            }
        }
        if (best == -1 || bestDensity <= 0) break;

        double take = a[best].weight < capacity ? a[best].weight : capacity;
        double gained = take * bestDensity;
        printf("At time %.2f, take %.2f weight of item %c (density %.2f)\n",
               time, take, a[best].name, bestDensity);
        totalValue += gained;
        capacity -= take;
        time += take;
        used[best] = 1;
    }

    printf("Total simulated value = %.2f\n", totalValue);
    return 0;
}
