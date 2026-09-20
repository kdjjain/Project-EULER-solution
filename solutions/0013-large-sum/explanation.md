# Problem 0013 - Large Sum

## Problem

Project Euler Problem #13

Problem Link:
https://projecteuler.net/problem=13

## Approach

Add one hundred fifty-digit numbers and report the first ten digits of the total.

The sum is far too large for native integer types, so each number is added into a running total stored as a vector of decimal digits (least significant digit first). This makes carry propagation straightforward.

After summing all numbers, the digits are read from the most significant end and the first ten are printed.

See [Big Number Arithmetic](../../concepts/big-number-arithmetic.md) for the digit-vector addition technique.

## Complexity

Time Complexity: O(N * D)

Space Complexity: O(D)

Where `N` is the number of inputs and `D` is the digit count of the running total.
