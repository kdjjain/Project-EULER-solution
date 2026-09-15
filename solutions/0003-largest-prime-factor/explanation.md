# Problem 0003 - Largest Prime Factor

## Problem

Find the largest prime factor of the number 600851475143.

## Approach

Repeatedly divide the number by the smallest divisor starting from 2.

For each divisor `i`:
- While `i` divides the number, record it as the largest factor and divide the number by `i`.
- Only check divisors up to the square root of the remaining number.

If anything greater than 1 remains at the end, it is itself a prime factor and the largest one.

## Complexity

Time Complexity: O(sqrt(N))

Space Complexity: O(1)
