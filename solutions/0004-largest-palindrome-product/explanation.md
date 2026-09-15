# Problem 0004 - Largest Palindrome Product

## Problem

Find the largest palindrome made from the product of two 3-digit numbers.

## Approach

Try every pair of 3-digit numbers.

For each product:
- Check whether it reads the same forwards and backwards by reversing its digits.
- Keep track of the largest palindrome found.

The second loop starts at `a` to avoid checking the same pair twice.

## Complexity

Time Complexity: O(N^2)

Space Complexity: O(1)
