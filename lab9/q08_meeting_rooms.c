/* DAA Lab 09 - Q8: Minimum meeting rooms
   Sort start and end times separately. If next meeting starts before the
   earliest ending meeting ends, another room is needed.
*/
#include <stdio.h>

int main(void) {
    int n, i, j, temp, rooms = 0, maxRooms = 0;
    int start[1000], end[1000];

    printf("Number of meetings (max 1000): ");
    scanf("%d", &n);
    if (n < 1 || n > 1000) return 0;
    for (i = 0; i < n; i++) {
        printf("Meeting %d start and end: ", i + 1);
        scanf("%d %d", &start[i], &end[i]);
        if (end[i] < start[i]) return 0;
    }
    for (i = 0; i < n; i++) for (j = i + 1; j < n; j++) {
        if (start[j] < start[i]) { temp = start[i]; start[i] = start[j]; start[j] = temp; }
        if (end[j] < end[i]) { temp = end[i]; end[i] = end[j]; end[j] = temp; }
    }

    i = j = 0;
    while (i < n) {
        if (start[i] < end[j]) {
            rooms++;
            if (rooms > maxRooms) maxRooms = rooms;
            i++;
        } else {
            rooms--;
            j++;
        }
    }
    printf("Minimum meeting rooms required = %d\n", maxRooms);
    return 0;
}
