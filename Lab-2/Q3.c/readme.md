# 🚀 Lab Question 3 – Merging K Sorted Arrays

<div align="center">

![Language](https://img.shields.io/badge/Language-C-blue.svg)
![Status](https://img.shields.io/badge/Status-Completed-success.svg)
![Algorithm](https://img.shields.io/badge/Algorithm-Merge%20Algorithm-orange.svg)
![Complexity](https://img.shields.io/badge/Time%20Complexity-Analysis-red.svg)

</div>

---

# 📌 Problem Statement

Suppose there are **k sorted arrays**, each containing **n elements**.

The task is to merge all of them into a single sorted array containing **k × n elements**.

Two different approaches are implemented and compared.

---

# 🧠 Method 1 (Sequential Merge)

### Idea

- Merge the first two arrays.
- Merge the obtained result with the third array.
- Merge the new result with the fourth array.
- Continue until every array is merged.

### Example

```
A1 + A2
      ↓
   Result + A3
            ↓
      Result + A4
               ↓
          ...
```

---

## Time Complexity

Each merge keeps increasing in size.

```
2n
3n
4n
...
kn
```

Total work

```
2n + 3n + 4n + ... + kn

= n(2 + 3 + ... + k)

= O(nk²)
```

### Worst Case

> **O(nk²)**

---

# 🧠 Method 2 (Pairwise Merge)

### Idea

Instead of merging one by one,

merge arrays in pairs.

Example

```
A1 + A2

A3 + A4

A5 + A6

...

↓

Merge the results again

↓

Repeat until only one array remains.
```

This is similar to the Merge Sort strategy.

---

## Time Complexity

At every level

- Every element is processed once.
- Total work per level = **O(nk)**

Number of levels

```
log₂(k)
```

Therefore

```
O(nk) × O(log k)

= O(nk log k)
```

### Worst Case

> **O(nk log k)**

---

# 📂 Files

```
Lab3/
│
├── method1.c
├── method2.c
└── README.md
```

---

# ▶️ Compilation

### Method 1

```bash
gcc method1.c -o method1
./method1
```

### Method 2

```bash
gcc method2.c -o method2
./method2
```

---

# 📊 Sample Output

```
Method 1

Merged Array:
1 2 3 4 5 6 7 8 9 10 11 12
Execution Time : 0.000002 sec
```

```
Method 2

Merged Array:
1 2 3 4 5 6 7 8 9 10 11 12
Execution Time : 0.000001 sec
```

---

# 📈 Complexity Comparison

| Method | Worst Case |
|----------|------------|
| Sequential Merge | **O(nk²)** |
| Pairwise Merge | **O(nk log k)** |

---

# 💡 Observation

- Method 1 repeatedly merges increasingly larger arrays, resulting in a quadratic dependency on **k**.
- Method 2 performs balanced merges similar to Merge Sort, significantly reducing the number of merge operations.
- Therefore, **Method 2 is more efficient** for large values of **k**.

---

# 📝 Note

The source code contains comments in **English + Hinglish** to make the implementation easier to understand during learning and revision.

---

<div align="center">

### ⭐ If you found this project useful, consider giving it a star.

Made with ❤️ for DAA Laboratory

</div>