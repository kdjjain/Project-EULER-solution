# Big Number Arithmetic (Vector of Digits)

## Purpose

Some problems require numbers far larger than the native integer types (`int`, `long long`) can store, such as 1000-digit values or huge factorials. Big number arithmetic represents such numbers as a sequence of digits and implements arithmetic manually.

## Intuition

A number is just a list of digits. If we store those digits in a vector, we can perform the same column-by-column arithmetic we learned by hand, carrying over to the next column when a column overflows.

Storing digits **least significant digit first** (index 0 = units place) is convenient because carries naturally propagate towards higher indices, and the vector can grow at the end.

## Representation

```text
Number 1234  ->  vector {4, 3, 2, 1}
```

- Index 0 holds the units digit.
- The number of digits is simply the vector size.

## Addition

Add digit by digit from the least significant end, tracking a carry.

```cpp
vector<int> add(vector<int> a, vector<int> b)
{
    vector<int> result;
    int carry = 0;
    int n = max(a.size(), b.size());

    for (int i = 0; i < n; i++)
    {
        int digit = carry;
        if (i < (int)a.size()) digit += a[i];
        if (i < (int)b.size()) digit += b[i];

        result.push_back(digit % 10);
        carry = digit / 10;
    }

    while (carry > 0)
    {
        result.push_back(carry % 10);
        carry /= 10;
    }

    return result;
}
```

## Multiplication

Multiply a big number by an integer (or another big number) using the schoolbook method, again propagating a carry.

```cpp
vector<int> multiply(vector<int> a, int k)
{
    vector<int> result;
    int carry = 0;

    for (int i = 0; i < (int)a.size(); i++)
    {
        int prod = a[i] * k + carry;
        result.push_back(prod % 10);
        carry = prod / 10;
    }

    while (carry > 0)
    {
        result.push_back(carry % 10);
        carry /= 10;
    }

    return result;
}
```

## Complexity Analysis

Let `D` be the number of digits.

- Addition: `O(D)` time, `O(D)` space.
- Multiplication by an integer: `O(D)` time.
- Multiplication of two big numbers (schoolbook): `O(D1 * D2)` time.

## Example

```text
  99
+  1
----
 100

{9, 9} + {1}  ->  {0, 0, 1}   // reads as 100
```

## Common Use Cases

- Computing very large Fibonacci numbers.
- Factorials and their digit sums.
- Powers of large bases.
- Any problem where results exceed 64-bit integer range.

## Reference Problems

- Project Euler #0016 - Power Digit Sum
- Project Euler #0020 - Factorial Digit Sum
- Project Euler #0025 - 1000-digit Fibonacci Number

## Useful Resources

- CP Algorithms (Arbitrary-Precision Arithmetic): https://cp-algorithms.com/algebra/big-integer.html
- GeeksforGeeks (Big Number / BigInteger): https://www.geeksforgeeks.org/bigint-big-integers-in-c-with-example/
- Wikipedia (Arbitrary-precision arithmetic): https://en.wikipedia.org/wiki/Arbitrary-precision_arithmetic

## Notes and Optimizations

- Store multiple digits per element (e.g. base 10^9) to reduce vector size and speed up arithmetic.
- Keep digits least significant first so carries and growth append at the end.
- Remove leading zeros (highest indices) after subtraction to keep sizes minimal.
- For very large multiplications, Karatsuba or FFT-based multiplication reduces the `O(D^2)` cost.
