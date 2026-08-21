# Sort Items by Colour in O(n)

## Problem

We are given `n` pairs of items.

Each pair contains:

* A **number**
* A **colour**: Red, Blue, or Yellow

The input items are already sorted by their **number**.

We need to sort the items by colour in this order:

```text
Red → Blue → Yellow
```

The important condition is that the numbers having the **same colour must remain sorted**.

### Example

Input:

```text
(1, R) (2, B) (3, R) (4, Y) (5, B) (6, Y) (7, R) (8, B)
```

Output:

```text
(1, R) (3, R) (7, R) (2, B) (5, B) (8, B) (4, Y) (6, Y)
```

Notice that:

* Red numbers: `1, 3, 7` → sorted
* Blue numbers: `2, 5, 8` → sorted
* Yellow numbers: `4, 6` → sorted

---

## Approach

Since the input is already sorted by number, we do **not** need to sort the numbers again.

We create three separate arrays:

```text
Red array
Blue array
Yellow array
```

Then we scan the original array from left to right.

For every item:

* If colour is `R`, put it in the Red array.
* If colour is `B`, put it in the Blue array.
* If colour is `Y`, put it in the Yellow array.

Because we process the input from left to right, the numbers inside each colour array automatically remain sorted.

Finally, we combine:

```text
Red → Blue → Yellow
```

---

## Algorithm

```text
1. Create three arrays: red, blue, yellow.

2. Traverse the input array from left to right.

3. If the colour is:
      R → store in red
      B → store in blue
      Y → store in yellow

4. Copy all red items back into the original array.

5. Copy all blue items after the red items.

6. Copy all yellow items after the blue items.

7. Print the final array.
```

---

## Time Complexity

We traverse the array once to separate the colours:

```text
O(n)
```

Then we traverse the three colour arrays to combine them:

```text
O(n)
```

Therefore:

```text
O(n) + O(n) = O(n)
```

### Final Time Complexity

```text
O(n)
```

### Space Complexity

We use three additional arrays containing at most `n` elements in total.

Therefore:

```text
O(n)
```

---

## C Implementation

```c
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

    // Traverse the input only once
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

    // Put Red items first
    int k = 0;

    for (int i = 0; i < r; i++) {
        arr[k++] = red[i];
    }

    // Put Blue items next
    for (int i = 0; i < b; i++) {
        arr[k++] = blue[i];
    }

    // Put Yellow items last
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
```

---

## Sample Input

```text
8
1 R
2 B
3 R
4 Y
5 B
6 Y
7 R
8 B
```

## Sample Output

```text
Before sorting:
(1, R) (2, B) (3, R) (4, Y) (5, B) (6, Y) (7, R) (8, B)

After sorting by colour:
(1, R) (3, R) (7, R) (2, B) (5, B) (8, B) (4, Y) (6, Y)
```

---

## Key Idea

The main trick is:

> **The input is already sorted by number, so simply separating the colours preserves the number order automatically.**

We don't need a traditional sorting algorithm like Bubble Sort, Merge Sort, or Quick Sort.

That is why the algorithm achieves **O(n)** time complexity.
