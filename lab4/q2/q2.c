#include <stdio.h>
#include <stdlib.h>

/* Compare function for qsort */
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

/* Binary Search
   Returns 1 if target is found, otherwise 0
*/
int binarySearch(int arr[], int n, int target) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return 1;

        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return 0;
}

int main() {
    int n, x;

    printf("Enter size of each set: ");
    scanf("%d", &n);

    int S1[n], S2[n];

    printf("Enter elements of S1:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &S1[i]);
    }

    printf("Enter elements of S2:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &S2[i]);
    }

    printf("Enter x: ");
    scanf("%d", &x);

    /*
     * Sort S2
     * Time = O(n log n)
     */
    qsort(S2, n, sizeof(int), compare);

    /*
     * For every element a in S1,
     * search for (x - a) in S2.
     */
    for (int i = 0; i < n; i++) {
        int required = x - S1[i];

        if (binarySearch(S2, n, required)) {
            printf("Pair exists: (%d, %d)\n",
                   S1[i], required);
            return 0;
        }
    }

    printf("No such pair exists.\n");

    return 0;
}