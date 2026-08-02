# Question 3

This program compares two implementations of the **Bubble Sort** algorithm:

- **Optimized Bubble Sort** (with early termination)
- **Naive Bubble Sort** (always performs all passes)

The comparison is performed for different input sizes, and the number of comparisons made by each algorithm is recorded. The generated data is stored in CSV files and visualized using graphs. :contentReference[oaicite:0]{index=0} :contentReference[oaicite:1]{index=1}

## Files

```text
.
├── Q3Bubble.c                  # Average-case comparison
├── Q3Bubble.exe

├── Q3BubbleBest.c              # Best-case comparison
├── Q3BubbleBest.exe

├── Q3results.csv               # Average-case results
├── Q3results_bestcase.csv      # Best-case results

├── Q3result.png                # Average-case graph
├── Q3results_bestcase.png      # Best-case graph

└── README.md
```

## Features

- Compares **Optimized** and **Naive** Bubble Sort.
- Measures the number of comparisons for different input sizes.
- Generates CSV files containing the experimental results.
- Visualizes the comparison using graphs.
- Demonstrates the effect of **early termination** in Bubble Sort.

## Cases Covered

- **Average Case** (Random arrays)
- **Best Case** (Already sorted arrays)

## Compile

### Average Case

```bash
gcc Q3Bubble.c -o Q3Bubble
```

### Best Case

```bash
gcc Q3BubbleBest.c -o Q3BubbleBest
```

## Run

### Windows

```bash
Q3Bubble.exe
Q3BubbleBest.exe
```

### Linux / macOS

```bash
./Q3Bubble
./Q3BubbleBest
```