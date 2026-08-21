# Merge Overlapping Intervals

## 📌 Description

This C program merges all **overlapping intervals** into a single interval.

It first sorts the intervals by their starting time and then merges overlapping intervals.

### Example

```text
Input:
(1, 3) (2, 6) (8, 10) (9, 12)

Output:
(1, 6) (8, 12)
```

## ⚙️ Approach

1. Sort intervals by their `start` value using `qsort()`.
2. Start with the first interval.
3. If the next interval overlaps:

   ```text
   next.start <= current.end
   ```

   extend the current interval.
4. If it doesn't overlap, store the current interval and start a new one.
5. Store the final interval.

## ⏱️ Complexity

* Sorting: `O(n log n)`
* Merging: `O(n)`
* **Overall: `O(n log n)`**
* Space: `O(n)`

## 🛠️ Concepts Used

* Structures (`struct`)
* Arrays
* `qsort()`
* Sorting
* Greedy approach
* Dynamic Memory Allocation
* Time & Space Complexity

## 🚀 Run

```bash
gcc main.c -o main
./main
```
