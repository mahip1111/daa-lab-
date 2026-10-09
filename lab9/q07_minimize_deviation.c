/* DAA Lab 09 - Q7: Minimise deviation
   Standard greedy: make all numbers even first; repeatedly halve the current
   maximum while it is even. A simple array scan replaces a max-heap here.
*/
#include <stdio.h>

int main(void) {
    int n, i, maxIndex;
    long long a[1000], minimum, deviation, best;

    printf("Number of elements (max 1000): ");
    scanf("%d", &n);
    if (n < 1 || n > 1000) return 0;

    minimum = 9223372036854775807LL;
    for (i = 0; i < n; i++) {
        printf("Positive number %d: ", i + 1);
        scanf("%lld", &a[i]);
        if (a[i] <= 0) return 0;
        if (a[i] % 2 == 1) a[i] *= 2;
        if (a[i] < minimum) minimum = a[i];
    }

    best = 9223372036854775807LL;
    while (1) {
        maxIndex = 0;
        for (i = 1; i < n; i++) if (a[i] > a[maxIndex]) maxIndex = i;
        deviation = a[maxIndex] - minimum;
        if (deviation < best) best = deviation;
        if (a[maxIndex] % 2 == 1) break;
        a[maxIndex] /= 2;
        if (a[maxIndex] < minimum) minimum = a[maxIndex];
    }
    printf("Minimum deviation = %lld\n", best);
    return 0;
}
