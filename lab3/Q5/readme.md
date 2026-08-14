# Special Pattern Matrix Multiplication using Divide and Conquer (O(n²))

## Aim

Implement multiplication of two special-pattern square matrices using the Divide and Conquer approach in **O(n²)** time.

---

## Problem Statement

Given two `n × n` matrices (`n = 2^k`) having the recursive structure

```
| M1 M2 |
| M2 M1 |
```

where

- Diagonal blocks are identical (`M1`)
- Off-diagonal blocks are identical (`M2`)
- Every block again follows the same recursive structure until size `1 × 1`

Multiply the two matrices efficiently using Divide and Conquer.

---

## Algorithm

1. If matrix size is `1 × 1`, multiply the two numbers.
2. Divide each matrix into four equal blocks.
3. Since the matrix has the special form

```
| A1 A2 |
| A2 A1 |
```

and

```
| B1 B2 |
| B2 B1 |
```

only four recursive multiplications are required:

- P = A1 × B1
- Q = A2 × B2
- R = A1 × B2
- S = A2 × B1

4. Construct the answer as

```
Top Left     = P + Q
Top Right    = R + S
Bottom Left  = R + S
Bottom Right = P + Q
```

5. Return the final matrix.

---

## Time Complexity

At every recursive level,

```
T(n) = 4T(n/2) + O(n²)
```

Applying the Master Theorem,

```
a = 4
b = 2

n^(log₂4) = n²
```

Therefore,

```
T(n) = O(n²)
```

---

## Space Complexity

```
O(n²)
```

(extra matrices created during recursion)

---

## Sample Input

```
Enter matrix size:
2

Matrix A

1 2
2 1

Matrix B

3 4
4 3
```

---

## Sample Output

```
11 10
10 11
```

---

## Features

- Divide and Conquer implementation
- Exploits the recursive special matrix structure
- Reduces computation compared to normal matrix multiplication
- Time Complexity: **O(n²)**
- Recursive implementation in C

---

## Applications

- Recursive matrix computations
- Signal processing
- Parallel computing
- Scientific computing
- Divide and Conquer algorithm design
```