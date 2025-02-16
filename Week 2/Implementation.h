#pragma once

#include"stack.h"
using namespace std;

Stack::Stack()
{
	top = -1;
}
int Stack::IsEmpty() const
{
	return (top == -1);
}
int Stack::IsFull() const
{
	return (top == MAX_ITEMS - 1);
}
void Stack::Push(itemType newItem)
{
	if (IsFull()) {
		cout << "Stack Overflow " << endl;

	}

	items[++top] = newItem;
}
void Stack::Pop(itemType& item)
{
	if (IsEmpty())
	{
		cout << "Stack Underflow " << endl;
		exit(1);
	}
	item = items[top--];

}int Stack::Peek() {

	if (IsEmpty())
	{
		cout << "Stack Underflow " << endl;
		exit(1);
	}
	return items[top];
}

// Non Class Functions

string ReverseString(const string& str) {
	
	Stack s;

	for (int i = 0; i < str.length() ;i++) {
		char  ch = str[i];
		s.Push(ch);
	}


	string reversed = "";
	int item;

	while (!s.IsEmpty()) {
		s.Pop(item);
		reversed += item;
	}

	return reversed;
}

bool IsBalanced(const string& par) {
	Stack s;
	int leftPar = 0, rightPar = 0;

	for (int i = 0; i < par.length(); i++) {
		char ch= par[i];
		if ( ch == '(') {
			s.Push(ch);
			leftPar++;
		}
		else if (ch == ')') {
			if (s.IsEmpty()) {
				return false; 
			}
			itemType temp;
			s.Pop(temp);
			rightPar++;

		}
	}

	if (leftPar == rightPar) {
		return s.IsEmpty();
	}
	else
		return false;
}

int Precedence(char op) {

	if (op == '*' || op == '/') return 2;	// higher precendece
	if (op == '+' || op == '-') return 1;	// lower precedence

	return 0;
}


bool IsOperator(char ch) {
	return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}


string InfixToPostfix(const string& infix) {
	Stack s;
	string postfix = "";

	for (int i = 0; i < infix.length(); i++) {
		char ch = infix[i];

		if (isalnum(ch)) {
			
			postfix += ch;
		}
		else if (ch == '(') {
			
			s.Push(ch);
		}
		else if (ch == ')') {
			
			itemType temp;
			while (!s.IsEmpty() && s.Peek() != '(') {
				s.Pop(temp);
				postfix += temp;
			}
			s.Pop(temp); 
		}
		else if (IsOperator(ch)) {
			
			itemType temp;

			while (!s.IsEmpty() && Precedence(s.Peek()) >= Precedence(ch)) {
				s.Pop(temp);
				postfix += temp;
			}
			s.Push(ch);
		}
	}

	
	itemType temp;

	while (!s.IsEmpty()) {
		s.Pop(temp);
		postfix += temp;
	}

	return postfix;
}

int Evaluate(const string& expression) {
	Stack s;
	int operand1, operand2, result;

	for (int i = 0; i < expression.length(); i++) {
		char ch = expression[i];

		if (isdigit(ch)) {
			
			s.Push(ch - '0');
		}
		else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
			
			int op2, op1;
			s.Pop(op2);
			s.Pop(op1);

			
			switch (ch) {

			case '+':
				result = op1 + op2;
				break;
			case '-':
				result = op1 - op2;
				break;
			case '*':
				result = op1 * op2;
				break;
			case '/':
				result = op1 / op2;
				break;
			}

			
			s.Push(result);
		}
	}

	
	s.Pop(result);
	return result;
}