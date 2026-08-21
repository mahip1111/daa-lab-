#include <stdio.h>
#include <stdlib.h>

/*
    Check whether k elements from S[] add up to T.

    Approach:
    - Recursively choose k-1 elements.
    - For the remaining 1 element, use binary search.
    - Sort the array first.

    Time Complexity:
        O(n^(k-1) * log n)

    Input representation:
        Sorted array of integers.
*/

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

/* Binary search for target */
int binarySearch(int arr[], int n, long long target) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target)
            return 1;

        if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return 0;
}

/*
    Choose 'remaining' numbers.

    start     -> starting index
    remaining -> how many numbers still need to be chosen
    sum       -> sum chosen so far
*/
int findKSum(int arr[], int n, int start,
            int remaining, long long sum, long long T) {

    /*
        Base case:
        We have selected k-1 numbers.
        Now find the last number using binary search.
    */
    if (remaining == 1) {
        long long needed = T - sum;

        /*
            Only search from 'start' onwards,
            so the same element is not reused.
        */
        return binarySearch(arr + start, n - start, needed);
    }

    /*
        Try every possible element for the current position.
    */
    for (int i = start; i <= n - remaining; i++) {

        if (findKSum(arr, n, i + 1,
                     remaining - 1,
                     sum + arr[i], T)) {
            return 1;
        }
    }

    return 0;
}

int main() {
    int n, k;
    long long T;

    printf("Enter n: ");
    scanf("%d", &n);

    int *S = malloc(n * sizeof(int));

    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &S[i]);
    }

    printf("Enter k: ");
    scanf("%d", &k);

    printf("Enter T: ");
    scanf("%lld", &T);

    if (k <= 0 || k > n) {
        printf("Invalid value of k.\n");
        free(S);
        return 0;
    }

    /*
        Sort the input.
        Sorting takes O(n log n).
    */
    qsort(S, n, sizeof(int), compare);

    /*
        Find whether k different elements
        add up to T.
    */
    if (findKSum(S, n, 0, k, 0, T))
        printf("YES: %d elements add up to %lld.\n", k, T);
    else
        printf("NO: No %d elements add up to %lld.\n", k, T);

    free(S);

    return 0;
}