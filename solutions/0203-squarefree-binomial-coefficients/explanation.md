# Problem 0203 - Squarefree Binomial Coefficients

## Problem

Project Euler Problem #203

Problem Link:
https://projecteuler.net/problem=203

## Approach

Find the sum of the distinct squarefree numbers in the first 51 rows of Pascal's triangle.

The entire triangle up to row 50 is generated using Pascal's rule. The largest value, C(50, 25), is about 1.26 * 10^14, so every value fits comfortably in a 64-bit integer.

All values are collected into a set to keep only the distinct ones. Each distinct value is then tested for squarefreeness by checking that no prime square (up to 51) divides it, and the squarefree values are summed.

See [Binomial Coefficients](../../concepts/binomial-coefficients.md) for the triangle construction.

## Complexity

Time Complexity: O(N^2 * sqrt(N))

Space Complexity: O(N^2)

Where `N` is the number of rows (51).
