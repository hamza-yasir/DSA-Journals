#include "Implementation.h"
#include <string>
using namespace std;

int main() {
	Stack s;
	int item;
	

	for (int i = 0; i < 20; i++) {
		s.Push(i);
	}
	
	s.Pop(item);

	cout << "top value is : " << s.Peek() << endl << endl;

	for (int i = 0; i < 19; i++) {
		int item;
		s.Pop(item);
		cout << item << " " ;
		}
	

	//string
	string original = "Daddy" ; 
	
	string reversed = ReverseString(original);

	cout << "\n\nString reversal" << endl;
	cout << "\nOriginal string: " << original << endl;
	cout << "Reversed string: " << reversed << endl;

	//Parenthesis balancing
	
	string equation = "((9+5)/(2*7))" ;
	cout << "\n\nexpression : " << equation;
	if (IsBalanced(equation)) {
		cout << "\nparenthesized expression is balanced\n";
	}else
		cout << "\nparenthesized expression is not balanced\n";

	//Infix to Postfix

	string Postfix = InfixToPostfix(equation);
	cout << "Postfix for the equation is : " << Postfix << endl;

	//Evaluation
	cout << "\nEvaluation of expression gives: " << Evaluate(Postfix) << endl;	


	return 0;
}