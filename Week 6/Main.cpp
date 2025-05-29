#include "LinkedList.h"
#include "LinkedStr.h"
#include <iostream>
#include <string>

using namespace std;

void displayMenu() {
	cout << "\n=========== MENU ===========\n";
	cout << " 1. Test LinkedList Functions (Exercise 6.1)\n";
	cout << " 2. Reverse a String using Stack (Exercise 6.2)\n";
	cout << " 3. Manipulate Linked Structure (Exercise 6.3)\n";
	cout << "============================\n";
	cout << "Enter your choice (1-3): ";
}

int main() {
	int choice;
	displayMenu();
	cin >> choice;
	cin.ignore();  // To handle newline after cin

	switch (choice) {
	case 1: {
		cout << "\n--- Exercise 6.1: LinkedList Function Test ---\n";
		LinkedList<int> myList;
		myList.pushFront(10);
		myList.pushFront(20);
		myList.pushFront(30);
		cout << "Initial list: 30 -> 20 -> 10\n";

		cout << "Inserting 25 after 20:\n";
		myList.insertAfter(20, 25);
		cout << "List is now: 30 -> 20 -> 25 -> 10\n";

		cout << "Deleting 20:\n";
		myList.deleteValue(20);
		cout << "List is now: 30 -> 25 -> 10\n";

		cout << "Final popped values: ";
		while (!myList.isEmpty()) {
			cout << myList.popFront() << " ";
		}
		cout << endl;
		break;
	}
	case 2: {
		cout << "\n--- Exercise 6.2: Reverse a String ---\n";
		LinkedList<char> charStack;
		string inputStr;
		cout << "Enter a string to reverse: ";
		getline(cin, inputStr);

		for (char ch : inputStr) {
			charStack.pushFront(ch);
		}

		cout << "Reversed string: ";
		while (!charStack.isEmpty()) {
			cout << charStack.popFront();
		}
		cout << endl;
		break;
	}
	case 3: {
		cout << "\n--- Exercise 6.3: Linked Structure Manipulation ---\n";
		LinkedStr<int> intList;
		int count;
		cout << "Enter number of nodes: ";
		cin >> count;
		intList.makeList(count);

		cout << "Initial list:\n";
		intList.displayList();

		int valToDelete;
		cout << "Enter value to delete: ";
		cin >> valToDelete;
		intList.removeValue(valToDelete);

		cout << "After deleting " << valToDelete << ":\n";
		intList.displayList();

		cout << "After deleting first node:\n";
		intList.removeFirst();
		intList.displayList();

		cout << "After deleting last node:\n";
		intList.removeLast();
		intList.displayList();
		break;
	}
	default:
		cout << "Invalid choice. Please run the program again and select a valid option.\n";
	}

	return 0;
}
