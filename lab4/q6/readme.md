# Maximum Overlap Point in Intervals

## 📌 Description

This C program finds the **point where the maximum number of intervals overlap**.

It uses the **Sweep Line Algorithm** with sorting of start and end events.

### Example

```text
Input:
(1, 5)
(2, 6)
(4, 8)

Output:
Point with maximum overlap = 4
Maximum overlapping intervals = 3
```

## ⚙️ Approach

1. Convert every interval into two events:

   * Start → `+1`
   * End → `-1`
2. Sort all events by position.
3. If two events have the same position, process **start before end** because intervals are inclusive.
4. Sweep from left to right.
5. Maintain the current number of overlapping intervals.
6. Whenever a new maximum is found, store that point.

## ⏱️ Complexity

* Creating events: `O(n)`
* Sorting events: `O(n log n)`
* Sweep: `O(n)`
* **Overall: `O(n log n)`**
* Space: `O(n)`

## 🛠️ Concepts Used

* Structures (`struct`)
* Sweep Line Algorithm
* Sorting
* `qsort()`
* Dynamic Memory Allocation
* Event-based Processing
* Time & Space Complexity

## 🚀 Run

```bash
gcc main.c -o main
./main
```
