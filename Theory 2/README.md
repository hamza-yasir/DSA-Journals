# Data Analysis and Recursion


### Problem Statement
Implement a C++ program to perform recursive operations on a dynamically (randomly) allocated dataset. The operations include Maximum, Minimum, Range, Sum, Product, Mean, Median, Mode, Standard Deviation, Sorting, and Searching. The results must be recorded for different values of N.

### Objectives
- Implement recursive functions for data analysis.
- Utilize dynamic memory allocation for storage.
- Handle large datasets and observe performance.
- Analyze and report computational limitations such as stack overflow.

### Program Structure
The program is divided into three files:
- **`Claass.h`**: Contains the class definition with function prototypes.
- **`Implementation.h`**: Contains function implementations.
- **`killer.cpp`**: Contains the `main()` function, which executes the program.

### Program Details
- The program uses `rand()` to generate random numbers for dataset initialization. To ensure different results in each run, `srand(time(0))` is used for seeding. The numbers are restricted within a range using `rand() % 30 + 1`, ensuring values between **1 and 30**.
- The program dynamically allocates an array using `new` and deallocates it in the destructor using `delete[]` to manage memory efficiently.
- **Recursive functions** are implemented for various operations such as finding the **maximum, minimum, sum, product, sorting, and searching**.
- The **product function** is particularly problematic due to **integer overflow** when handling large values, resulting in **wrap-around** of values and a **negative answer**. Hence, `long long` is used by making it a **template function**.

### Libraries Used
- `<iostream>` for input/output operations.
- `<cstdlib>` for random number generation.
- `<ctime>` to seed the random function.
- `<cmath>` for mathematical operations like square root calculation.


### Result Table

| N      | Max | Min | Sum  | Product  | Mean  | SD   | Mode | Median |
|--------|-----|-----|------|----------|-------|------|------|--------|
| 50     | 28  | 2   | 134  | 10697319360 | 13.4  | 9.1  | 28   | 10     |
| 100    | 30  | 1   | 1586 | 0        | 15.86 | 9.02 | null | null   |
| 500    | 30  | 1   | 7732 | 0        | 15.464| 8.75 | null | null   |
| 1000   | 30  | 1   | 15557| 0        | 15.557| 8.67 | null | null   |
| 10000  | -   | -   | -    | -        | -     | -    | -    | -      |
| 50000  | -   | -   | -    | -        | -     | -    | -    | -      |

**Note:** The program crashed upon exceeding `N = 1000`, and the system displayed a **low resources** warning.

### Conclusion
The recursive approach works well for small datasets but leads to **stack overflow** for large values of `N` due to deep recursion, especially in functions like **product calculation and sorting**. The **mode function** in particular resulted in a **stack overflow exception** that caused the program to stop once `N` exceeded **64**. For **10,000** and **50,000** values, the program did not execute and no output was obtained. To scale beyond `N = 64`, **iterative implementations** would be more efficient and avoid excessive memory usage. **Performance can be improved** by optimizing recursion depth or using hybrid approaches that combine recursion with iteration to manage memory more effectively.

