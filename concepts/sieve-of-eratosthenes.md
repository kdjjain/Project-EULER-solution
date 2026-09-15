# Sieve of Eratosthenes

## Purpose

The Sieve of Eratosthenes efficiently finds all prime numbers up to a given limit `N`. It is the standard technique when many primes are needed, rather than testing each number individually.

## Intuition

Every composite number has a prime factor. If we start from the smallest prime and remove all of its multiples, then move to the next remaining number and repeat, only primes are left unmarked. Each composite is eliminated by its prime factors before we ever reach it.

## Algorithm

1. Create a boolean array `isPrime[0..N]` initialised to `true`.
2. Mark `isPrime[0]` and `isPrime[1]` as `false`.
3. For each `i` from `2` to `sqrt(N)`:
   - If `isPrime[i]` is still `true`, mark every multiple of `i` starting from `i * i` as `false`.
4. All indices that remain `true` are prime.

Starting the inner loop at `i * i` is safe because smaller multiples of `i` were already marked by smaller primes.

## Complexity Analysis

- Time Complexity: `O(N log log N)`
- Space Complexity: `O(N)`

## Example

Sieving up to `N = 10`:

```text
Start:   2 3 4 5 6 7 8 9 10
i = 2 ? remove 4, 6, 8, 10
i = 3 ? remove 9
Primes:  2 3 5 7
```

## Common Use Cases

- Listing all primes below a limit.
- Counting primes in a range.
- Precomputing primes for factorisation or prime-related queries.
- Building a smallest-prime-factor table for fast factorisation.

## Reference Problems

- Project Euler #0007 - 10001st Prime
- Project Euler #0010 - Summation of Primes
- Project Euler #0035 - Circular Primes

## Useful Resources

- CP Algorithms: https://cp-algorithms.com/algebra/sieve-of-eratosthenes.html
- GeeksforGeeks: https://www.geeksforgeeks.org/sieve-of-eratosthenes/
- Wikipedia: https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
- Khan Academy: https://www.khanacademy.org/computing/computer-science/cryptography/comp-number-theory/a/the-sieve-of-eratosthenes

## Notes and Optimizations

- Start marking multiples from `i * i`, since smaller multiples are already handled.
- Use a bitset or `vector<bool>` to reduce memory usage.
- Sieve only odd numbers to roughly halve time and space.
- For very large limits, use a segmented sieve to keep memory bounded.
- A linear sieve (`O(N)`) can also compute smallest prime factors alongside the primes.
