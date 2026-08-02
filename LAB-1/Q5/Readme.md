# Question 5

This program finds the **partition point** in a binary array containing a sequence of `0`s followed by a sequence of `1`s.

It implements both **Binary Search** and **Linear Search** to find the index of the first occurrence of `1` and compares their results. :contentReference[oaicite:0]{index=0}

## Files

```text
.
├── Q5.c
├── Q5.exe

└── README.md
```

## Features

- Finds the first occurrence of `1` using **Binary Search**.
- Implements **Linear Search** for comparison.
- Handles edge cases such as:
  - Array containing all `0`s.
  - Array containing all `1`s.
- Demonstrates the efficiency of Binary Search for sorted binary arrays.

## Notes

- Binary Search has a time complexity of **O(log n)**.
- Linear Search has a time complexity of **O(n)**.

## Compile

```bash
gcc Q5.c -o Q5
```

## Run

### Windows

```bash
Q5.exe
```

### Linux / macOS

```bash
./Q5
```