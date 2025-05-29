#include<iostream>
#include<string>
#include "BST.h"
using namespace std;

int main() {
	
	cout << "-----------TASK 1-----------\n";
	string names[] = { "Kashf", "Adeel", "Hamza", "Farkhanda", "brian" };
	int size = sizeof(names) / sizeof(names[0]);

	SortStrings(names, size);

	cout << "Sorted Strings:\n";
	for (int i = 0; i < size; i++) {
		cout << names[i] << endl;
	}
	return 0;
}