# Recursive Functions in C++

This document provides explanations and examples of various recursive functions implemented in C++. These examples demonstrate different recursive algorithms, including prime number checking, binomial coefficient calculation, the Ackermann function, power computation, and more.



## Exercise 3.3c: Prime Number Check

### Description

This program determines whether a given number is prime using recursion.

### Key Functions

- `IsPrime(int n, int divisor)`: Recursively checks divisibility.
- `PrimeCaller(int n)`: Calls `IsPrime()` to verify if `n` is prime.



## Binomial Coefficient Calculation

### Description

Computes the binomial coefficient using recursion, defined as:
\(C(n, k) = C(n-1, k-1) + C(n-1, k)\)

### Key Functions

- `BinomialCoefficient(int n, int k)`: Calculates C(n, k) recursively.


## Exercise 3.3a: Countdown from N to 0

### Description

This program prints numbers from N down to 0 recursively.

### Key Function

- `recursive(int N)`: Prints numbers in descending order.


## Example 3.4 and Exercise 3.2: Ackermann Function

### Description

The Ackermann function is a recursive mathematical function demonstrating deep recursion.

### Key Function

- `Ackermann(int m, int n)`: Computes Ackermann's function recursively.


## Example 3.3 and Exercise 3.1: Power Calculation

### Description

Computes \(x^N\) using recursion.

### Key Function

- `Power(int x, int N)`: Recursively computes the power of x raised to N.


## Example 3.2: Reverse String Input

### Description

Reads a string and prints it in reverse order using recursion.

### Key Function

- `rev()`: Recursively reads and outputs characters in reverse order.


## Example 3.1: Factorial Calculation

### Description

Calculates the factorial of a number using recursion.

### Key Function

- `fact(int n)`: Computes factorial recursively.



## Notes

- **Recursion Depth**: Some functions, like Ackermann, can reach deep recursion levels, leading to stack overflow.
- **Input Validation**: Handling invalid or negative inputs is crucial to avoid errors.



## Conclusion

These examples illustrate fundamental recursive programming techniques in C++. Understanding recursion is essential for tackling complex problems such as mathematical functions, data structures, and algorithm optimization.

---
