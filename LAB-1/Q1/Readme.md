# Question 1

This program compares different mathematical functions and prints their values for a chosen value of `n`. The functions are arranged in increasing order of asymptotic growth to verify their theoretical order.

## Files

```text
.
├── Q1.c
├── Q1.exe
└── README.md
```

## Order of Growth

```text
1/n
<
log n
<
12√n
<
50√n
<
n^0.51
<
n log n
<
n² − 324
<
100n² + 6n
<
2n³
<
n^(log n)
<
3ⁿ
<
2^(32n)
```

## Notes

- The default value of `n` is **100** (can be changed in `Q1.c`).
- `3ⁿ` and `2^(32n)` become extremely large, so the program prints **log₂(value)** instead of the actual value.

## Compile

```bash
gcc Q1.c -o Q1.exe -lm
```

## Run

```bash
Q1.exe
```

> **Note:** On Linux/macOS, compile without the `.exe` extension:
>
> ```bash
> gcc Q1.c -o Q1 -lm
> ./Q1
> ```