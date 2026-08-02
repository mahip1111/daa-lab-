# Question 4

This program solves the **Tower of Hanoi** problem using recursion. It calculates the total number of moves required to transfer all disks from the source rod to the destination rod for different numbers of disks.

The program stores the results in a CSV file, which can be used to generate a graph showing how the number of moves grows as the number of disks increases. :contentReference[oaicite:0]{index=0}

## Files

```text
.
├── Q4.c
├── Q4.exe

├── Q4hanoi_moves.csv
├── Q4hanoi.png

└── README.md
```

## Features

- Solves the Tower of Hanoi problem using recursion.
- Calculates the number of moves for **1 to 20 disks**.
- Stores the results in a CSV file.
- Visualizes the exponential growth of the number of moves using a graph.

## Notes

- The program counts the total number of moves without printing each move.
- The maximum number of disks can be changed by modifying the `maxDiscs` variable in `Q4.c`.

## Compile

```bash
gcc Q4.c -o Q4
```

## Run

### Windows

```bash
Q4.exe
```

### Linux / macOS

```bash
./Q4
```