# Selection Sort using Loop Invariant

## Aim

Implement the Selection Sort algorithm in C and verify its correctness using the concept of Loop Invariants.

---

## Algorithm (Pseudocode)

```
SelectionSort(A, n)

for i = 1 to n-1
    min = i

    for j = i+1 to n
        if A[j] < A[min]
            min = j

    swap(A[i], A[min])
```

---

## Loop Invariant

At the beginning of each iteration of the outer loop:

- The first `i` elements of the array are already sorted.
- These elements are the smallest `i` elements of the original array.

### Proof

### 1. Initialization

Before the first iteration (`i = 0`), no elements are sorted.

Therefore, the loop invariant is true.

---

### 2. Maintenance

During each iteration:

- Find the smallest element in the unsorted part.
- Place it at its correct position by swapping.

Now the sorted portion increases by one element.

Hence, the invariant remains true.

---

### 3. Termination

After completing `n-1` iterations:

- First `n-1` elements are sorted.
- The remaining last element is automatically the largest.

Therefore, the entire array is sorted.

---

## Why only (n − 1) iterations?

After placing the first `n−1` smallest elements in their correct positions,

the last remaining element is automatically in the correct position.

Hence, one extra iteration is unnecessary.

---

## Time Complexity

### Worst Case

Outer loop runs `n-1` times.

Inner loop comparisons:

```
(n-1) + (n-2) + ... + 1
```

Total comparisons:

```
n(n-1)/2
```

Therefore,

```
Worst Case = Θ(n²)
```

---

### Best Case

Even if the array is already sorted,

Selection Sort still checks every remaining element to find the minimum.

Therefore,

```
Best Case = Θ(n²)
```

Selection Sort does **not** become faster for an already sorted array.

---

## Space Complexity

```
Θ(1)
```

Only a few extra variables are used.

---

## Sample Input

```
Enter number of elements:
5

Enter elements:
64 25 12 22 11
```

---

## Sample Output

```
Original Array:
64 25 12 22 11

Sorted Array:
11 12 22 25 64
```

---

## Conclusion

- Selection Sort repeatedly selects the smallest element from the unsorted part.
- The loop invariant guarantees correctness by ensuring the sorted portion grows after each iteration.
- Only `n−1` iterations are needed because the last element is automatically sorted.
- Both the **best-case** and **worst-case** running times are **Θ(n²)**.
- The algorithm requires only **Θ(1)** extra space.