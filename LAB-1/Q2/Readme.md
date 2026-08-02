# Question 2

This program simulates coin tosses to demonstrate how the observed probability of getting **Heads** converges to the actual probability as the number of tosses increases.

The program performs simulations for both a **fair coin** and a **biased coin**, allowing a comparison of their observed probabilities over different trial sizes.

## Files

```text
.
├── Q2.c
├── Q2.exe
└── README.md
```

## Features

- Simulates a **fair coin** (`P(Heads) = 0.50`).
- Simulates a **biased coin** (`P(Heads) = 0.75`).
- Runs experiments with different numbers of tosses:
  - 100
  - 1,000
  - 10,000
  - 100,000
  - 1,000,000
  - 10,000,000
- Displays the observed probability of Heads for each experiment.

## Notes

- Random numbers are generated using `rand()`.
- The random number generator is initialized using the current system time with `srand(time(NULL))`.
- As the number of tosses increases, the observed probability approaches the actual probability, illustrating the **Law of Large Numbers**.

## Compile

```bash
gcc Q2.c -o Q2
```

## Run

### Windows

```bash
Q2.exe
```

### Linux / macOS

```bash
./Q2
```