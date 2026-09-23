# Problem 0030 - Digit Fifth Powers

## Problem

Project Euler Problem #30

Problem Link:
https://projecteuler.net/problem=30

## Approach

Find the sum of all numbers that equal the sum of the fifth powers of their digits.

Take a number of `L` digits written as `abc...xyz`. Its value is:

```
a*10^(L-1) + b*10^(L-2) + ... + z*10^0
```

and we want this to equal:

```
a^5 + b^5 + ... + z^5
```

The right side can be at most `L * 9^5` (every digit is 9), while the left side is at least `10^(L-1)` (the smallest `L`-digit number). So equality is only possible while:

```
10^(L-1) <= L * 9^5
```

Since `9^5 = 59049`, at `L = 7` the biggest possible sum is `7 * 59049 = 413343`, which is smaller than the smallest 7-digit number `1000000`. So no number with 7 or more digits can work, and the search only needs to go up to `6 * 9^5 = 354294`.

Every number from 10 up to that bound is checked by summing the fifth powers of its digits (using a precomputed table) and comparing with the number itself. Matching numbers are summed (1 is excluded because it is not a sum).

## Complexity

Time Complexity: O(N * D)

Space Complexity: O(1)

Where `N` is the upper bound and `D` is the number of digits.
