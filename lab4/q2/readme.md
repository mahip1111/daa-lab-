# Find Pair with Given Sum Using Binary Search

## 📌 Description

This program checks whether there exists a pair of elements—one from set `S1` and one from set `S2`—whose sum is equal to a given value `x`.

The program uses:

* **Quick Sort (`qsort`)** to sort `S2`
* **Binary Search** to efficiently find the required element
* The formula:

```text
required = x - S1[i]
```

If `required` exists in `S2`, then:

```text
S1[i] + required = x
```

and the program prints the pair.

---

## 🧠 How It Works

Suppose:

```text
S1 = {2, 4, 7, 10}
S2 = {1, 3, 6, 8}
x = 10
```

For every element in `S1`, the program calculates the element required from `S2`.

For example:

```text
S1[0] = 2

required = x - S1[0]
         = 10 - 2
         = 8
```

Now the program performs a binary search for `8` in `S2`.

Since `8` exists:

```text
2 + 8 = 10
```

Therefore, the pair exists.

---

## ⚙️ Algorithm

1. Read the size `n`.
2. Read elements of `S1`.
3. Read elements of `S2`.
4. Read the target sum `x`.
5. Sort `S2` using `qsort()`.
6. For every element `a` in `S1`:

   * Calculate `required = x - a`.
   * Perform binary search for `required` in `S2`.
7. If found, print the pair and terminate.
8. If no pair is found, print `"No such pair exists."`

---

## 💻 Code

```c
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

    /* Sort S2 */
    qsort(S2, n, sizeof(int), compare);

    /* Search for required element */
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
```

---

## 🧪 Example

### Input

```text
Enter size of each set: 4

Enter elements of S1:
2 4 7 10

Enter elements of S2:
1 3 6 8

Enter x: 10
```

### Output

```text
Pair exists: (2, 8)
```

Because:

```text
2 + 8 = 10
```

---

## ⏱️ Time Complexity

### Sorting `S2`

`qsort()` takes:

```text
O(n log n)
```

### Binary Search

For each of the `n` elements in `S1`, binary search takes:

```text
O(log n)
```

Therefore:

```text
n × O(log n) = O(n log n)
```

### Overall

```text
O(n log n) + O(n log n)
= O(n log n)
```

**Overall Time Complexity: `O(n log n)`**

### Space Complexity

The program stores two arrays of size `n`:

```text
S1 → O(n)
S2 → O(n)
```

So the overall auxiliary/input storage is:

```text
O(n)
```

---

## 🔑 Important Concepts Used

### 1. Binary Search

Binary search works on a **sorted array** and repeatedly divides the search space into half.

Time complexity:

```text
O(log n)
```

### 2. `qsort()`

C provides the built-in `qsort()` function for sorting arrays.

```c
qsort(S2, n, sizeof(int), compare);
```

The arguments mean:

```text
S2              → array to sort
n               → number of elements
sizeof(int)     → size of each element
compare         → comparison function
```

### 3. Two-Sum Idea

The core idea is:

```text
a + b = x
```

Therefore:

```text
b = x - a
```

So for every `a` in `S1`, we only need to check whether:

```text
x - a
```

exists in `S2`.

---

## 🎯 Key Advantage

A simple brute-force approach would check every possible pair:

```text
S1[i] + S2[j]
```

This would take:

```text
O(n²)
```

This solution improves it to:

```text
O(n log n)
```

by sorting `S2` once and using binary search.

---

## 📚 Concepts to Learn from This Program

* Arrays
* Functions in C
* Pointers
* `const void *`
* Type casting
* `qsort()`
* Binary Search
* Time Complexity
* Space Complexity
* Two-Sum technique
* Divide and Conquer searching

---

## 🚀 How to Run

Save the program as:

```text
main.c
```

Compile:

```bash
gcc main.c -o main
```

Run:

```bash
./main
```

On Windows:

```bash
main.exe
```

---

## 👨‍💻 Author

**Manavendra Gupta**
