# Project Euler Solutions

This repository contains my solutions to Project Euler problems, written in C++.

The purpose of this repository is to:

- Maintain a record of the problems I have solved.
- Document the approach used for each problem.
- Build a long-term collection of mathematical and algorithmic problem-solving techniques.
- Keep every solution organised, searchable, and easy to revisit.

---

## Repository Structure

```text
solutions/
├── 0001-multiples-of-3-and-5/
│   ├── solution.cpp
│   └── explanation.md
│
├── 0002-even-fibonacci-numbers/
│   ├── solution.cpp
│   └── explanation.md
│
└── ...
```

Each problem has its own directory containing exactly two files:

- `solution.cpp`: The final working C++ solution.
- `explanation.md`: A concise explanation of the approach.

---

## Folder Naming Convention

Problem folders must follow this format:

```text
<four-digit-problem-number>-<problem-title>
```

Examples:

```text
0001-multiples-of-3-and-5
0002-even-fibonacci-numbers
0010-summation-of-primes
0100-arranged-probability
1000-problem-title
```

### Rules

- Pad the Project Euler problem number to four digits.
- Use the original problem title.
- Use lowercase letters for the title.
- Separate words using hyphens (`-`).
- Do not use spaces or underscores.

Four-digit numbering keeps the folders correctly sorted, including problems numbered 1000 and above.

---

## Solution Guidelines

The `solution.cpp` file should contain:

- A correct and complete solution.
- Clean and readable C++ code.
- The approach actually used to solve the problem.
- No abandoned experiments or unrelated code.

Example:

```cpp
#include <iostream>
using namespace std;

int main()
{
    // Solution
    return 0;
}
```

---

## Explanation Guidelines

The explanation should be concise and proportional to the difficulty of the problem.

Basic template:

```markdown
# Problem XXXX - Problem Title

## Problem

A brief description of the problem.

## Approach

An explanation of the approach used to solve it.

## Complexity

Time Complexity: O(...)

Space Complexity: O(...)
```

Additional sections may be included when they provide meaningful information:

```markdown
## Observations

## Mathematical Insight

## Optimisation

## Learnings
```

These sections are optional and should only be added when they represent a genuine observation, optimisation, or learning.

Do not add sections merely to make the explanation appear more detailed.

---

## Commit Convention

Follow the rule:

> One solved problem per commit.

Commit message format:

```text
Solve Project Euler #XXXX - Problem Title
```

Examples:

```text
Solve Project Euler #0001 - Multiples of 3 and 5
Solve Project Euler #0002 - Even Fibonacci Numbers
Solve Project Euler #0010 - Summation of Primes
Solve Project Euler #1000 - Problem Title
```

Each problem commit should include:

- The problem directory.
- `solution.cpp`.
- `explanation.md`.
- The README progress update, if applicable.

Do not include solutions for multiple problems in the same commit.

---

## Progress

| Problem | Title | Solution |
|:-------:|-------|:--------:|
| 0001 | Multiples of 3 and 5 | [View Solution](solutions/0001-multiples-of-3-and-5/) |
| 0002 | Even Fibonacci Numbers | [View Solution](solutions/0002-even-fibonacci-numbers/) |
| 0003 | Largest Prime Factor | [View Solution](solutions/0003-largest-prime-factor/) |
| 0004 | Largest Palindrome Product | [View Solution](solutions/0004-largest-palindrome-product/) |
| 0005 | Smallest Multiple | [View Solution](solutions/0005-smallest-multiple/) |
| 0006 | Sum Square Difference | [View Solution](solutions/0006-sum-square-difference/) |
| 0007 | 10001st Prime | [View Solution](solutions/0007-10001st-prime/) |
| 0013 | Large Sum | [View Solution](solutions/0013-large-sum/) |
| 0025 | 1000-digit Fibonacci Number | [View Solution](solutions/0025-1000-digit-fibonacci-number/) |

**Total problems solved: 9**

---

## Repository Philosophy

The repository documents the real problem-solving process.

The focus is on:

- Correctness
- Clear reasoning
- Readable code
- Concise and useful explanations
- Meaningful insights when they genuinely exist

Simple problems should have simple explanations. More detailed sections should be added only when the problem requires them.
