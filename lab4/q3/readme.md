# K-Sum Using Recursion and Binary Search

## 📌 Description

This C program checks whether **k different elements** from an array add up to a given target `T`.

It uses:

* Sorting using `qsort()`
* Recursion to select `k-1` elements
* Binary Search to find the last required element

## ⚙️ Approach

For every selected set of `k-1` elements:

```text
required = T - current_sum
```

Then binary search is used to check whether `required` exists in the remaining array.

Example:

```text
Array = {1, 2, 3, 4, 5}
k = 3
T = 9

2 + 3 = 5
required = 9 - 5 = 4

Since 4 exists:
2 + 3 + 4 = 9
```

## ⏱️ Complexity

* Sorting: `O(n log n)`
* Recursive search + Binary Search: `O(n^(k-1) log n)`
* Space: `O(n + k)`

## 🛠️ Concepts Used

* Recursion
* Binary Search
* Sorting
* Dynamic Memory Allocation
* Arrays
* Time & Space Complexity

## 🚀 Run

```bash
gcc main.c -o main
./main
```

## 📌 Output

If a valid combination exists:

```text
YES: k elements add up to T.
```

Otherwise:

```text
NO: No k elements add up to T.
```
