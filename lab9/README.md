# DAA Lab-09 — Super Easy C Programs

These beginner-friendly C programs are based on the 10 questions in the supplied **DAA Lab-09** sheet.

## How to compile and run

Use GCC:

```bash
gcc q01_fractional_knapsack.c -o q01
./q01
```

On Windows, run `q01.exe` after compiling. Change the filename and output name for the other programs.

Each program is kept separate so it is easy to compile, understand, and demonstrate in a lab.

## Programs

| File | Problem | Typical time complexity |
|---|---|---|
| `q01_fractional_knapsack.c` | Fractional knapsack with deterioration rate | `O(n log n)` |
| `q02_huffman_canonical.c` | Huffman code + canonical codebook | `O(n^2)` in this simple version |
| `q03_minimum_refuels.c` | Minimum refuelling stops (reverse greedy) | `O(n^2)` |
| `q04_connect_sticks.c` | Minimum cost to connect sticks | `O(n^2)` |
| `q05_candy_distribution.c` | Candy distribution | `O(n)` |
| `q06_reorganize_k_distance.c` | Reorganise string so equal letters are K apart | `O(n * 26)` |
| `q07_minimize_deviation.c` | Minimise deviation in an array | `O(n * log M)` heap-based idea; this simple version uses scans |
| `q08_meeting_rooms.c` | Minimum meeting rooms | `O(n^2)` in this simple version |
| `q09_hu_tucker_simulation.c` | Small-input merge simulation (educational approximation) | Exponential/limited brute force is not implemented; see note |
| `q10_greedy_superstring.c` | Greedy superstring heuristic | Depends on string lengths and number of strings |

> **Important:** Question 9 asks for the Hu–Tucker algorithm for an optimal alphabetic tree. The included file is a small educational *merge-pattern simulation*, not a full Hu–Tucker implementation and does not claim optimality. Question 10 is explicitly described in the lab sheet as an open problem; the included program demonstrates the classic maximum-overlap greedy heuristic, not an exact solver.

## Notes

- Inputs are intentionally small and entered from the keyboard.
- These are learning/demo implementations, not production-grade code.
- For Question 1, the sheet does not fully specify how an item's value changes while it is being consumed. This implementation assumes each item is processed in a chosen order and its effective value per unit weight at time `t` is `value/weight - decay*t`; it greedily picks the largest current density and advances time by the amount of weight consumed. This is a clear simulation of the stated rule, but a proof of global optimality would require a precise model.
- Question 2 outputs canonical codes ordered by code length and then symbol.
