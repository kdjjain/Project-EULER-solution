# Problem 0007 - 10001st Prime

## Problem

Project Euler Problem #7

https://projecteuler.net/problem=7

## Approach

Use the Sieve of Eratosthenes to mark all primes up to a sufficiently large limit.

Since the 10001st prime is 104743, a limit of 200000 comfortably contains it.

After building the sieve, iterate through the numbers and count primes until the 10001st is reached, then print it.

## Complexity

Time Complexity: O(N log log N)

Space Complexity: O(N)
