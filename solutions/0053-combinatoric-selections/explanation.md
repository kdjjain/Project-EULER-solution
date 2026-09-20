# Problem 0053 - Combinatoric Selections

## Problem

Project Euler Problem #53

Problem Link:
https://projecteuler.net/problem=53

## Approach

Count how many values of C(n, r) for 1 <= n <= 100 are greater than one million.

For a fixed n, C(n, r) increases as r goes from 0 to n/2 and then decreases, and it is symmetric: C(n, r) = C(n, n - r). So once C(n, r) first exceeds one million at some r = k, every r from k up to n - k also exceeds it. That contributes `n - 2k + 1` values for this n.

This lets us stop at the first r (up to n/2) whose value passes the limit, so the enormous middle coefficients are never computed and overflow is avoided. The running value is built with the recurrence `C(n, r) = C(n, r - 1) * (n - r + 1) / r`.

See [Binomial Coefficients](../../concepts/binomial-coefficients.md) for the underlying combinatorics.

## Complexity

Time Complexity: O(N^2)

Space Complexity: O(1)

Where `N` is 100.
