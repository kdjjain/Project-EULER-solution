# Problem 0019 - Counting Sundays

## Problem

Project Euler Problem #19

Problem Link:
https://projecteuler.net/problem=19

## Approach

Count how many months in the 20th century (1 Jan 1901 to 31 Dec 2000) began on a Sunday.

Track the weekday of the first day of each month by accumulating the number of days modulo 7. The known anchor is that 1 Jan 1900 was a Monday, so the count starts at 1900 (using Monday = 0, Sunday = 6) but months are only counted from 1901 onward.

For each month:
- If the year is at least 1901 and the current weekday is Sunday, increment the counter.
- Advance the weekday by the number of days in that month, where February has 29 days in a leap year.

A year is a leap year if it is divisible by 400, or divisible by 4 but not by 100.

## Complexity

Time Complexity: O(1)

Space Complexity: O(1)

The number of months is fixed (about 1200).
