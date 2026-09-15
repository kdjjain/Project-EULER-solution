# Problem 0006 - Sum Square Difference

## Problem

Find the difference between the square of the sum and the sum of the squares of the first one hundred natural numbers.

## Approach

Iterate from 1 to 100 while maintaining two running totals:
- The sum of the numbers.
- The sum of their squares.

Square the total sum, then subtract the sum of the squares to get the answer.

## Complexity

Time Complexity: O(N)

Space Complexity: O(1)
