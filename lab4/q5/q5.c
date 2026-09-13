//  Application of sorting-V: Given a list I of n intervals, specified as (xi, yi) pairs, return
// a list where the overlapping intervals are merged. For I = {(1, 3), (2, 6), (8, 10), (7, 18)} the
// output should be {(1, 6), (7, 18)}. Your algorithm should run in worst-case O(n ·log n) time
// complexity. By choosing a suitable input and output representation, write a program in C
// to validate your algorithm

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
} Interval;

/* Compare intervals based on starting time */
int compare(const void *a, const void *b) {
    Interval *i1 = (Interval *)a;
    Interval *i2 = (Interval *)b;

    return i1->start - i2->start;
}

/* Merge overlapping intervals */
int mergeIntervals(Interval intervals[], int n, Interval result[]) {

    if (n == 0)
        return 0;

    /* Step 1: Sort intervals by start time */
    qsort(intervals, n, sizeof(Interval), compare);

    int resultCount = 0;

    /* Start with the first interval */
    int start = intervals[0].start;
    int end = intervals[0].end;

    /* Step 2: Merge */
    for (int i = 1; i < n; i++) {

        /* Overlapping */
        if (intervals[i].start <= end) {

            /* Extend the ending time */
            if (intervals[i].end > end)
                end = intervals[i].end;
        }

        /* Non-overlapping */
        else {

            /* Store the current merged interval */
            result[resultCount].start = start;
            result[resultCount].end = end;
            resultCount++;

            /* Start a new interval */
            start = intervals[i].start;
            end = intervals[i].end;
        }
    }

    /* Store the last interval */
    result[resultCount].start = start;
    result[resultCount].end = end;
    resultCount++;

    return resultCount;
}

int main() {

    int n;

    printf("Enter number of intervals: ");
    scanf("%d", &n);

    Interval *intervals = malloc(n * sizeof(Interval));
    Interval *result = malloc(n * sizeof(Interval));

    printf("Enter intervals (start end):\n");

    for (int i = 0; i < n; i++) {
        scanf("%d %d",
              &intervals[i].start,
              &intervals[i].end);
    }

    int resultCount = mergeIntervals(intervals, n, result);

    printf("\nMerged intervals:\n");

    for (int i = 0; i < resultCount; i++) {
        printf("(%d, %d) ",
               result[i].start,
               result[i].end);
    }

    printf("\n");

    free(intervals);
    free(result);

    return 0;
}