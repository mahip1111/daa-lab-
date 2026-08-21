#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int time;
    int type;   // +1 = entry, -1 = exit
} Event;

/* Comparison function for qsort */
int compareEvents(const void *a, const void *b) {
    Event *e1 = (Event *)a;
    Event *e2 = (Event *)b;

    return e1->time - e2->time;
}

int main() {
    int n;

    printf("Enter number of people: ");
    scanf("%d", &n);

    Event *events = (Event *)malloc(2 * n * sizeof(Event));

    printf("Enter entry time and exit time for each person:\n");

    for (int i = 0; i < n; i++) {
        int a, b;

        printf("Person %d: ", i + 1);
        scanf("%d %d", &a, &b);

        // Entry event
        events[2 * i].time = a;
        events[2 * i].type = +1;

        // Exit event
        events[2 * i + 1].time = b;
        events[2 * i + 1].type = -1;
    }

    // Sort all events according to time
    qsort(events, 2 * n, sizeof(Event), compareEvents);

    int currentPeople = 0;
    int maxPeople = 0;
    int maxTime = 0;

    // Sweep through all events
    for (int i = 0; i < 2 * n; i++) {

        currentPeople += events[i].type;

        if (currentPeople > maxPeople) {
            maxPeople = currentPeople;
            maxTime = events[i].time;
        }
    }

    printf("\nMaximum number of people present = %d\n", maxPeople);
    printf("Time when maximum was reached = %d\n", maxTime);

    free(events);

    return 0;
}