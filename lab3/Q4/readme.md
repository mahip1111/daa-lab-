# Strassen's Matrix Multiplication (2×2) in C

## Overview
This program implements **Strassen's Matrix Multiplication Algorithm** for **2×2 matrices** in C. Strassen's algorithm is a Divide and Conquer technique that reduces the number of matrix multiplications from **8 to 7**, making it more efficient than the traditional matrix multiplication algorithm for large matrices.

> **Note:** This implementation is specifically designed for **2×2 matrices** to demonstrate the working of Strassen's algorithm in a simple and easy-to-understand manner.

---

## Features
- Accepts two **2×2 matrices** as input.
- Multiplies the matrices using **Strassen's Algorithm**.
- Displays the resulting matrix.
- Easy to understand and suitable for beginners.

---

## Algorithm

1. Read two 2×2 matrices from the user.
2. Compute the seven intermediate products:
   - M1 = (A11 + A22) × (B11 + B22)
   - M2 = (A21 + A22) × B11
   - M3 = A11 × (B12 − B22)
   - M4 = A22 × (B21 − B11)
   - M5 = (A11 + A12) × B22
   - M6 = (A21 − A11) × (B11 + B12)
   - M7 = (A12 − A22) × (B21 + B22)
3. Compute the final result matrix:
   - C11 = M1 + M4 − M5 + M7
   - C12 = M3 + M5
   - C21 = M2 + M4
   - C22 = M1 − M2 + M3 + M6
4. Display the resulting matrix.

---

## Time Complexity

- **Time Complexity:** O(1)

Since this implementation works only for fixed-size **2×2 matrices**, the execution time remains constant.

> For the recursive Strassen algorithm on **n × n** matrices, the time complexity is approximately **O(n²·⁸⁰⁷)**.

---

## Space Complexity

- **Space Complexity:** O(1)

Only a fixed amount of extra memory is used.

---

## Sample Input

```
Enter elements of Matrix A (2x2):
1 2
3 4

Enter elements of Matrix B (2x2):
5 6
7 8
```

## Sample Output

```
Result Matrix:
19 22
43 50
```

---

## Advantages

- Performs only **7 multiplications** instead of 8.
- Demonstrates the Divide and Conquer approach.
- Easy implementation for learning the basic concept of Strassen's algorithm.
- Good for academic demonstrations and viva examinations.

---

## Limitations

- Works only for **2×2 matrices**.
- Does not use recursion.
- Cannot multiply larger matrices directly.
- The full recursive Strassen algorithm is required for general **n × n** matrix multiplication.

---

## Applications

- Scientific Computing
- Computer Graphics
- Image Processing
- Machine Learning
- Large Matrix Computations
- Numerical Analysis

---

## Conclusion

This program demonstrates the basic idea of **Strassen's Matrix Multiplication Algorithm** using a simple 2×2 implementation. It reduces the number of multiplications from **8 to 7** by using additional additions and subtractions, illustrating the core optimization behind Strassen's method. While this implementation is intended for educational purposes, the recursive version of Strassen's algorithm is used for efficiently multiplying large matrices.