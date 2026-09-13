// Application of sorting-VI: You are given a set S of n intervals on a line, with the ith
// interval described by its left and right endpoints (li, ri). Give an O(n ·log n) algorithm to
// identify a point p on the line that is in the largest number of intervals. As an example, for
// S = {(10, 40), (20, 60), (50, 90), (15, 70)} no point exists in all four intervals, but p = 50 is
// an example of a point in three intervals. You can assume an endpoint counts as being in
// its interval. By choosing a suitable input and output representation, write a program in C
// to validate your algorithm

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int position;
    int type;   // +1 = start, -1 = end
} Event;

/*
 * Sorting rule:
 * 1. Sort by position.
 * 2. If positions are equal, process START (+1) before END (-1)
 *    because endpoints are included in intervals.
 */
int compareEvents(const void *a, const void *b) {
    Event *e1 = (Event *)a;
    Event *e2 = (Event *)b;

    if (e1->position != e2->position)
        return e1->position - e2->position;

    return e2->type - e1->type;
}

void findMaximumOverlap(int left[], int right[], int n,
                        int *bestPoint, int *maxCount) {

    // We have 2 events for every interval
    Event *events = malloc(2 * n * sizeof(Event));

    if (events == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    // Create start and end events
    for (int i = 0; i < n; i++) {
        events[2 * i].position = left[i];
        events[2 * i].type = +1;

        events[2 * i + 1].position = right[i];
        events[2 * i + 1].type = -1;
    }

    // Sort all events
    qsort(events, 2 * n, sizeof(Event), compareEvents);

    int current = 0;
    *maxCount = 0;
    *bestPoint = events[0].position;

    // Sweep from left to right
    for (int i = 0; i < 2 * n; i++) {

        current += events[i].type;

        // Found a point with more intervals
        if (current > *maxCount) {
            *maxCount = current;
            *bestPoint = events[i].position;
        }
    }

    free(events);
}

int main() {

    int n;

    printf("Enter number of intervals: ");
    scanf("%d", &n);

    int *left = malloc(n * sizeof(int));
    int *right = malloc(n * sizeof(int));

    if (left == NULL || right == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter the intervals (left right):\n");

    for (int i = 0; i < n; i++) {
        printf("Interval %d: ", i + 1);
        scanf("%d %d", &left[i], &right[i]);
    }

    int bestPoint;
    int maxCount;

    findMaximumOverlap(left, right, n,
                       &bestPoint, &maxCount);

    printf("\nPoint with maximum overlap = %d\n", bestPoint);
    printf("Maximum number of overlapping intervals = %d\n",
           maxCount);

    free(left);
    free(right);

    return 0;
}