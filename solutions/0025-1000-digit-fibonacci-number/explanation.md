# Problem 0025 - 1000-digit Fibonacci Number

## Problem

Project Euler Problem #25

Problem Link:
https://projecteuler.net/problem=25

## Approach

Find the index of the first Fibonacci number that has 1000 digits.

A 1000-digit number is far larger than what `int` or `long long` can hold, so the numbers are stored as vectors of decimal digits (least significant digit first). This makes carrying during addition simple.

Starting from F? = 1 and F? = 1, repeatedly add the two previous terms using big-number addition until a term reaches 1000 digits. The number of digits is simply the size of the vector, so the loop stops as soon as `size() >= 1000` and prints the current index.

See [Big Number Arithmetic](../../concepts/big-number-arithmetic.md) for the digit-vector addition technique.

## Complexity

Time Complexity: O(N * D)

Space Complexity: O(D)

Where `N` is the index of the answer and `D` is the number of digits (up to 1000).
