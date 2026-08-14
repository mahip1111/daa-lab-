# Search the Defective Coin Using Divide and Conquer

## Aim

To design and implement a **Divide and Conquer algorithm** to identify a defective (lighter) coin from a collection of `n` coins using the concept of a balance weighing scale. If all coins have the same weight, the program reports that no defective coin exists.

---

## Problem Statement

A collection contains `n` coins where all coins have the same weight except **at most one coin**, which may be lighter due to excessive shaping during manufacturing. The defective coin is never heavier than the others.

The objective is to determine:

- The position of the lighter (defective) coin, if one exists.
- Otherwise, report that all coins have equal weight.

The solution should use the **Divide and Conquer** technique.

---

## Algorithm

1. Read the number of coins and their weights.
2. Determine the standard (normal) weight by finding the maximum weight among all coins.
3. Divide the array of coins into two halves.
4. Calculate the total weight of both halves.
5. Compare the actual weight of each half with its expected weight.
6. If the left half is lighter, recursively search the left half.
7. If the right half is lighter, recursively search the right half.
8. If neither half is lighter, conclude that no defective coin exists.
9. Continue until only one coin remains.
10. If that coin is lighter than the normal weight, report it as defective.

---

## Divide and Conquer Strategy

- **Divide:** Split the coins into two equal halves.
- **Conquer:** Recursively search only the half that has a lower total weight.
- **Combine:** No combining step is required because only one half can contain the defective coin.

---

## Time Complexity

| Case | Complexity |
|------|------------|
| Best Case | O(log₂ n) |
| Average Case | O(log₂ n) |
| Worst Case | O(log₂ n) *(assuming balance comparison is O(1))* |

---

## Space Complexity

- Recursive Call Stack: **O(log₂ n)**

---

## Sample Input

```
Enter number of coins: 8

Enter weights of the coins:
10 10 10 9 10 10 10 10
```

### Output

```
Defective (lighter) coin found at position 4 (1-based index).
```

---

## Sample Input 2

```
Enter number of coins: 8

Enter weights of the coins:
10 10 10 10 10 10 10 10
```

### Output

```
No defective coin found. All coins have equal weight.
```

---

## Features

- Uses the Divide and Conquer paradigm.
- Recursive implementation.
- Detects a lighter coin if present.
- Reports when all coins have equal weight.
- Simple and easy-to-understand implementation.

---

## Applications

- Manufacturing quality control.
- Fault detection systems.
- Divide and Conquer algorithm demonstrations.
- Computer Science laboratory assignments.

---

## Conclusion

This project demonstrates how the **Divide and Conquer** technique can efficiently locate a defective (lighter) coin by repeatedly dividing the search space into smaller halves. Instead of checking every coin individually, the algorithm eliminates half of the remaining coins at each recursive step, making it significantly more efficient than a linear search. It also correctly reports when no defective coin exists.