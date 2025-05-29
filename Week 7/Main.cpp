#include <iostream>
#include "Source.cpp"  
using namespace std;

int main() {
	DoublyLinkedList<long> longList;
	int choice;
	long value, target;

	do {
		cout << "\n========== DOUBLY LINKED LIST MENU ==========\n";
		cout << "1. Insert at front\n";
		cout << "2. Insert at end\n";
		cout << "3. Delete from front\n";
		cout << "4. Delete from end\n";
		cout << "5. Insert after a specific value\n";
		cout << "6. Display list\n";
		cout << "0. Exit\n";
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
			cout << "Enter a long integer to insert at front: ";
			cin >> value;
			longList.insertAtFront(value);
			break;

		case 2:
			cout << "Enter a long integer to insert at end: ";
			cin >> value;
			longList.insertAtEnd(value);
			break;

		case 3:
			cout << "Deleting from front...\n";
			longList.deleteFromFront();
			break;

		case 4:
			cout << "Deleting from end...\n";
			longList.deleteFromEnd();
			break;

		case 5:
			cout << "Enter the value to insert after: ";
			cin >> target;
			cout << "Enter the new value to insert: ";
			cin >> value;
			longList.insertAfterValue(target, value);
			break;

		case 6:
			cout << "Displaying the list:\n";
			longList.display();
			break;

		case 0:
			cout << "Exiting the program.\n";
			break;

		default:
			cout << "Invalid choice. Please try again.\n";
		}
	} while (choice != 0);

	return 0;
}
