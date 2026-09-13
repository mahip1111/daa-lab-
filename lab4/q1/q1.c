// Application of sorting-I: Assume that we are given n pairs of items as input, where the
// first item is a number and the second item is one of three colours (red, blue, or yellow).
// Further assume that the items are sorted by number. Give an O(n) algorithm to sort
// the items by colour (all reds before all blues before all yellows) such that the numbers for
// identical colours stay sorted. By choosing the proper input representation, write a program
// in C to validate your algorithm.

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int number;
    char color;
} Item;

void sortByColor(Item arr[], int n) {

    // Arrays for each colour
    Item *red = malloc(n * sizeof(Item));
    Item *blue = malloc(n * sizeof(Item));
    Item *yellow = malloc(n * sizeof(Item));

    int r = 0, b = 0, y = 0;

    // One pass through the input
    for (int i = 0; i < n; i++) {

        if (arr[i].color == 'R') {
            red[r++] = arr[i];
        }
        else if (arr[i].color == 'B') {
            blue[b++] = arr[i];
        }
        else if (arr[i].color == 'Y') {
            yellow[y++] = arr[i];
        }
    }

    // Put them back:
    // Reds -> Blues -> Yellows
    int k = 0;

    for (int i = 0; i < r; i++) {
        arr[k++] = red[i];
    }

    for (int i = 0; i < b; i++) {
        arr[k++] = blue[i];
    }

    for (int i = 0; i < y; i++) {
        arr[k++] = yellow[i];
    }

    free(red);
    free(blue);
    free(yellow);
}

int main() {

    int n;

    printf("Enter number of items: ");
    scanf("%d", &n);

    Item *arr = malloc(n * sizeof(Item));

    printf("Enter number and colour (R/B/Y):\n");

    for (int i = 0; i < n; i++) {
        scanf("%d %c", &arr[i].number, &arr[i].color);
    }

    printf("\nBefore sorting:\n");

    for (int i = 0; i < n; i++) {
        printf("(%d, %c) ", arr[i].number, arr[i].color);
    }

    sortByColor(arr, n);

    printf("\n\nAfter sorting by colour:\n");

    for (int i = 0; i < n; i++) {
        printf("(%d, %c) ", arr[i].number, arr[i].color);
    }

    printf("\n");

    free(arr);

    return 0;
}