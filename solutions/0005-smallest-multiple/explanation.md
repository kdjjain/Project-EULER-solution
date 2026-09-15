# Problem 0005 - Smallest Multiple

## Problem

Find the smallest positive number that is evenly divisible by all numbers from 1 to 20.

## Approach

The smallest number divisible by all values is their least common multiple (LCM).

Compute the LCM incrementally:
- Start with 1.
- For each number `i` from 2 to 20, combine it with the running result using `lcm(a, b) = a / gcd(a, b) * b`.

The greatest common divisor is found using the Euclidean algorithm.

## Complexity

Time Complexity: O(N log M)

Space Complexity: O(1)
