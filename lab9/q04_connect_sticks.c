/* DAA Lab 09 - Q4: Minimum cost to connect sticks
   Each time, combine the two shortest sticks.
   Simple sorting-by-selection version.
*/
#include <stdio.h>

int main(void) {
    int n, i, j, min1, min2;
    long long a[100], total = 0;

    printf("Number of sticks (max 100): ");
    scanf("%d", &n);
    if (n < 1 || n > 100) return 0;
    for (i = 0; i < n; i++) {
        printf("Length of stick %d: ", i + 1);
        scanf("%lld", &a[i]);
    }

    for (i = n; i > 1; i--) {
        min1 = min2 = -1;
        for (j = 0; j < i; j++) {
            if (min1 == -1 || a[j] < a[min1]) {
                min2 = min1; min1 = j;
            } else if (min2 == -1 || a[j] < a[min2]) {
                min2 = j;
            }
        }
        long long sum = a[min1] + a[min2];
        total += sum;
        printf("Connect %lld and %lld -> %lld\n", a[min1], a[min2], sum);
        if (min1 > min2) { int temp = min1; min1 = min2; min2 = temp; }
        a[min1] = sum;
        a[min2] = a[i - 1];
        /* The active array has one fewer element now. */
    }
    printf("Minimum total cost = %lld\n", total);
    return 0;
}
