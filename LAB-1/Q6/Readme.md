# Question 6

This program checks whether an array contains duplicate elements using two different approaches:

- **Brute Force**
- **Sorting-Based Method**

It compares the execution time of both methods for arrays of different sizes to demonstrate the difference in their performance. :contentReference[oaicite:0]{index=0}

## Files

```text
.
├── Q6.c
├── Q6.exe

└── README.md
```

## Features

- Detects duplicate elements using **Brute Force**.
- Detects duplicate elements using **Sorting + Linear Scan**.
- Generates arrays with **unique elements** to test the worst-case scenario.
- Compares the execution time of both approaches for different input sizes.

## Notes

- Brute Force has a time complexity of **O(n²)**.
- The Sorting-Based method has a time complexity of **O(n log n)**.
- Both methods should produce the same result for every test case.

## Compile

```bash
gcc Q6.c -o Q6
```

## Run

### Windows

```bash
Q6.exe
```

### Linux / macOS

```bash
./Q6
```