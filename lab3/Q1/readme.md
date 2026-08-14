# Binary Search vs Ternary Search in C

## 📌 Aim

To implement **Binary Search** and **Ternary Search** on a sorted array and compare their performance. The program demonstrates that although ternary search divides the array into three parts, binary search is generally more efficient because it performs fewer comparisons per iteration.

---

## 📖 Problem Statement

Implement a C program to search for an element `x` in a sorted array of size `n` using:

- Binary Search
- Ternary Search

Compare both algorithms based on:
- Number of comparisons
- Time complexity
- Practical performance

---

## 🛠️ Algorithms

### 1. Binary Search

Binary Search divides the array into **two nearly equal halves**.

**Steps:**
1. Find the middle element.
2. If the key equals the middle element, return the index.
3. If the key is smaller, search the left half.
4. Otherwise search the right half.
5. Repeat until the element is found or the search space becomes empty.

**Time Complexity:** `O(log₂ n)`

---

### 2. Ternary Search

Ternary Search divides the array into **three nearly equal parts**.

**Steps:**
1. Compute two middle indices.
2. Compare the key with both middle elements.
3. Decide which one of the three segments may contain the key.
4. Repeat until found or the search space becomes empty.

**Time Complexity:** `O(log₃ n)`

---

## Why Binary Search is Better?

Although ternary search reduces the search space into three parts, each iteration performs **more comparisons**.

| Binary Search | Ternary Search |
|---------------|----------------|
| 1 middle element | 2 middle elements |
| Fewer comparisons | More comparisons |
| Faster in practice | Slightly slower |
| Simpler implementation | More complex |

Binary Search generally performs better because:
- It requires only one comparison point per iteration.
- Less computational overhead.
- Better cache performance.
- Widely used in real-world libraries.

---

## Time Complexity

| Algorithm | Best | Average | Worst |
|----------|---------|----------|---------|
| Binary Search | O(1) | O(log n) | O(log n) |
| Ternary Search | O(1) | O(log n) | O(log n) |

---

## Space Complexity

Both algorithms use:

```
O(1)
```

(for iterative implementation)

---

## Sample Input

```
Enter number of elements: 10

Enter sorted elements:
2 4 6 8 10 12 14 16 18 20

Enter element to search:
14
```

---

## Sample Output

```
Binary Search:
Element found at index 6
Comparisons = 3

Ternary Search:
Element found at index 6
Comparisons = 4

Binary Search performed fewer comparisons.
```

---

## Conclusion

Although Ternary Search divides the array into three parts, it performs more comparisons in each iteration. Binary Search requires fewer comparisons and is therefore faster in practical applications.

Hence, **Binary Search is better than Ternary Search for searching in sorted arrays.**

---

## Author

Manavendra Gupta