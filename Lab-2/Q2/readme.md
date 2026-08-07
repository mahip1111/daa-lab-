# Lab 2: Merge Sort vs Modified Merge Sort

## Aim

To compare the performance of the standard Merge Sort with a modified Merge Sort that divides the array into three equal parts instead of two and validates their theoretical time complexity through experimentation.

---

## Problem Statement

Consider the following modification to Merge Sort:

- Divide the input array into **three equal parts** instead of two.
- Recursively sort each of the three parts.
- Merge the three sorted subarrays using a **three-way merge** procedure.

Analyze its worst-case running time and compare it with the standard Merge Sort.

---

## Theory

### Standard Merge Sort

The recurrence relation is:

```
T(n) = 2T(n/2) + O(n)
```

Using the Master Theorem,

```
T(n) = O(n log n)
```

---

### Modified Merge Sort

The recurrence relation becomes:

```
T(n) = 3T(n/3) + O(n)
```

Since the merge operation still processes each element only once, its cost remains linear.

Applying the Master Theorem,

```
T(n) = O(n log n)
```

---

## Conclusion

Both algorithms have the same asymptotic worst-case complexity:

```
O(n log n)
```

However, the modified Merge Sort performs:

- Three recursive calls instead of two.
- A more complicated three-way merge.

Because of these larger constant factors, the standard Merge Sort is generally faster in practice even though both belong to the same complexity class.

---

## Program Features

- Implements the standard Merge Sort.
- Implements the modified three-way Merge Sort.
- Generates random input arrays.
- Measures execution time using `clock()`.
- Stores the results in a CSV file.
- Allows plotting and comparison of both algorithms.

---

## Output

The program generates:

```
merge_sort_analysis.csv
```

Example format:

```
InputSize,MergeSort,ModifiedMergeSort
1000,0.000112,0.000143
3000,0.000391,0.000505
5000,0.000684,0.000882
...
```

The CSV file can be used to plot the order of growth using Excel, Google Sheets, or Python.

---

## Time Complexity

| Algorithm | Worst Case |
|-----------|------------|
| Merge Sort | O(n log n) |
| Modified Merge Sort | O(n log n) |

---

## Space Complexity

| Algorithm | Auxiliary Space |
|-----------|-----------------|
| Merge Sort | O(n) |
| Modified Merge Sort | O(n) |

---

## Note

For my understanding, I have included comments in both **English** and **Hinglish** throughout the code to make the implementation easier to follow while studying.

---

**Author:** Manavendra Gupta