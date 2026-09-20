# Binomial Coefficients (Pascal's Triangle)

## Purpose

Binomial coefficients `C(n, r)` count the number of ways to choose `r` items from `n` without regard to order. They appear in combinatorics, probability, and many counting problems.

## Intuition

`C(n, r)` can be built from smaller values using Pascal's rule: a chosen item is either included or excluded.

```text
C(n, r) = C(n - 1, r - 1) + C(n - 1, r)
```

Arranged in rows, these values form Pascal's triangle, where each entry is the sum of the two entries directly above it.

## Key Properties

- Symmetry: `C(n, r) = C(n, n - r)`.
- Row boundaries: `C(n, 0) = C(n, n) = 1`.
- Unimodal: for a fixed `n`, values rise to the middle and then fall.
- Multiplicative recurrence: `C(n, r) = C(n, r - 1) * (n - r + 1) / r`.

## Algorithm

Two common ways to compute them:

1. **Pascal's triangle (table)** — fill a 2D array row by row using Pascal's rule. `O(n^2)` time and space.
2. **Multiplicative formula (single value)** — build `C(n, r)` iteratively with the recurrence above. `O(r)` time and `O(1)` space.

```cpp
// Single value using the multiplicative recurrence
long long binomial(int n, int r)
{
    long long result = 1;
    for (int i = 1; i <= r; i++)
    {
        result = result * (n - i + 1) / i;
    }
    return result;
}
```

## Complexity Analysis

- Pascal's triangle: `O(n^2)` time, `O(n^2)` space (or `O(n)` with a rolling row).
- Single value: `O(r)` time, `O(1)` space.

## Example

```text
n = 4:  1 4 6 4 1
C(4, 2) = 6
```

## Common Use Cases

- Counting subsets and combinations.
- Probability and expected-value problems.
- Expanding `(a + b)^n` (binomial theorem).
- Dynamic programming on grids and path counting.

## Reference Problems

- Project Euler #0015 - Lattice Paths
- Project Euler #0053 - Combinatoric Selections

## Useful Resources

- CP Algorithms (Binomial Coefficients): https://cp-algorithms.com/combinatorics/binomial-coefficients.html
- GeeksforGeeks (Binomial Coefficient): https://www.geeksforgeeks.org/binomial-coefficient-dp-9/
- Wikipedia (Pascal's Triangle): https://en.wikipedia.org/wiki/Pascal%27s_triangle

## Notes and Optimizations

- The intermediate product in the multiplicative recurrence stays an integer at every step, so integer division is safe.
- Values grow very quickly; cap them or use big integers / modular arithmetic when they exceed the required range.
- Exploit symmetry (`r = min(r, n - r)`) to reduce work.
- For repeated queries modulo a prime, precompute factorials and modular inverses.
