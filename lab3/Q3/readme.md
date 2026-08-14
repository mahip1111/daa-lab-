# Max and Min using Divide and Conquer (C)

## Overview

This project implements the **Divide and Conquer** approach to find the **minimum** and **maximum** elements in an array. Instead of checking each element one by one, the array is recursively divided into smaller parts, and the results are combined to obtain the final minimum and maximum values.

This approach reduces the number of comparisons to approximately **3n/2**, making it more efficient than the simple linear approach.

---

## Algorithm

1. Read the number of elements and the array.
2. Divide the array into two halves recursively.
3. If there is only one element:
   - It is both the minimum and maximum.
4. If there are two elements:
   - Compare them once.
   - Assign the smaller value as the minimum and the larger value as the maximum.
5. Recursively find the minimum and maximum of the left half.
6. Recursively find the minimum and maximum of the right half.
7. Compare the results from both halves:
   - Overall minimum = smaller of the two minimum values.
   - Overall maximum = larger of the two maximum values.
8. Print the final minimum and maximum values.

---

## Flow of the Algorithm

```
Array
   │
   ▼
Divide into two halves
   │
   ▼
Recursively solve left half
   │
   ▼
Recursively solve right half
   │
   ▼
Compare left & right results
   │
   ▼
Print Minimum and Maximum
```

---

## Example

### Input

```
Enter number of elements: 6
Enter array elements:
7 2 9 1 5 8
```

### Output

```
Minimum = 1
Maximum = 9
```

---

## Time Complexity

- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

---

## Space Complexity

- **O(log n)** (due to recursive function calls)

---

## Advantages

- Fewer comparisons than the simple linear approach.
- Efficient recursive solution using Divide and Conquer.
- Time complexity remains linear.
- Suitable for learning recursion and Divide & Conquer techniques.

---

## Applications

- Finding the minimum and maximum values in large datasets.
- Data analysis and statistics.
- Competitive programming.
- Design and Analysis of Algorithms (DAA) laboratory experiments.
- Problems requiring efficient recursive solutions.

---

## Technologies Used

- **Language:** C
- **Concepts:** Divide and Conquer, Recursion, Pointers

---

## Author

**Manavendra Gupta**