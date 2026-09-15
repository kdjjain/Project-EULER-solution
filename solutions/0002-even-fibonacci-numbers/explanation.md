# Problem 0002 - Even Fibonacci Numbers

## Problem

Find the sum of the even-valued terms in the Fibonacci sequence whose values do not exceed four million.

## Approach

Generate Fibonacci numbers one by one starting from 1 and 2.

For each term:
- Stop once the value exceeds four million.
- If the term is even, add it to the answer.

Finally, print the accumulated sum.

## Complexity

Time Complexity: O(log N)

Space Complexity: O(1)
