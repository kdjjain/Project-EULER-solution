# Problem 0054 - Poker Hands

## Problem

Project Euler Problem #54

Problem Link:
https://projecteuler.net/problem=54

## Approach

Read 1000 lines from `poker.txt`; each line has ten cards, the first five for Player 1 and the last five for Player 2. Count how many hands Player 1 wins.

Each hand is reduced to a comparable score:

- Card faces are mapped to numbers (T=10, J=11, Q=12, K=13, A=14).
- The value frequencies determine the category (pairs, trips, four of a kind, full house), while suit equality gives a flush and consecutive values give a straight.
- These are combined into a rank from 1 (high card) to 9 (straight flush / royal flush).

The score is stored as a vector beginning with the rank, followed by the card values ordered by group size and then by value. Comparing two such vectors lexicographically automatically handles tie-breaking: equal ranks fall back to the most significant group (for example the pair value), then to the kickers in descending order.

Player 1 wins a hand when its score vector is greater than Player 2's.

## Complexity

Time Complexity: O(N)

Space Complexity: O(1)

Where `N` is the number of hands (1000). Each hand uses a constant amount of work.
