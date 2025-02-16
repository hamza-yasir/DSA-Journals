# Stack-Based Expression Handling in C++

This project implements various stack-based operations in C++, including string reversal, parenthesis balancing, infix-to-postfix conversion, and postfix expression evaluation.

## Project Structure

- stack.h – Header file defining the Stack class.

- Implementation.h – Implementation of the Stack class and helper functions.

- main.cpp – Main program file containing test cases.

## Features

#### 1. Stack Implementation

- A static stack using an array of fixed size (MAX_ITEMS = 100).

- Basic operations:

  -  Push(itemType newItem): Push an element onto the stack.

  - Pop(itemType &item): Remove the top element from the stack.

  - Peek(): Retrieve the top element without removing it.

  - IsEmpty(): Check if the stack is empty.

  - IsFull(): Check if the stack is full.

#### 2. String Reversal

- Reverses a given string using a stack.

#### 3. Parenthesis Balancing

- Checks whether a given parenthesized expression is balanced.

#### 4. Infix to Postfix Conversion

- Converts an infix expression (e.g., ((9+5)/(2*7))) to postfix notation.

- Uses operator precedence and stack operations.

#### 5. Postfix Expression Evaluation

- Evaluates a valid postfix expression.

- Supports basic arithmetic operators: +, -, *, and /.

## Example

#### Input Expression

((9+5)/(2*7))

#### Output

Parenthesized expression is balanced.
Postfix for the equation is: 95+27*/
Evaluation of expression gives: 1

## Notes

- The expression is hardcoded in main.cpp.

- Modify main.cpp to test different expressions.

---
