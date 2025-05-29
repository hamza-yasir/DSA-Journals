#ifndef LINKED_STR_H
#define LINKED_STR_H

#include <iostream>
using namespace std;

template<class T>
class LinkedStr {
private:
	struct Node {
		T value;
		Node* next;
	};
	using NodePtr = Node * ;
	NodePtr head;

public:
	LinkedStr();
	~LinkedStr();
	void makeList(int count);
	void displayList() const;
	void removeValue(T val);
	void removeFirst();
	void removeLast();
};

template<class T>
LinkedStr<T>::LinkedStr() {
	head = nullptr;
}

template<class T>
LinkedStr<T>::~LinkedStr() {
	NodePtr current = head;
	while (current != nullptr) {
		NodePtr next = current->next;
		delete current;
		current = next;
	}
}

template<class T>
void LinkedStr<T>::makeList(int count) {
	head = nullptr;
	NodePtr tail = nullptr;

	for (int i = 0; i < count; ++i) {
		NodePtr newNode = new Node;
		cout << "Enter value for node " << i + 1 << ": ";
		cin >> newNode->value;
		newNode->next = nullptr;

		if (head == nullptr) {
			head = newNode;
			tail = newNode;
		}
		else {
			tail->next = newNode;
			tail = newNode;
		}
	}
}

template<class T>
void LinkedStr<T>::displayList() const {
	NodePtr current = head;
	while (current != nullptr) {
		cout << current->value;
		if (current->next) cout << " -> ";
		current = current->next;
	}
	cout << endl;
}

template<class T>
void LinkedStr<T>::removeValue(T val) {
	NodePtr current = head, prev = nullptr;

	while (current != nullptr && current->value != val) {
		prev = current;
		current = current->next;
	}

	if (current == nullptr) {
		cout << "Value not found.\n";
		return;
	}

	if (prev == nullptr) {
		head = head->next;
	}
	else {
		prev->next = current->next;
	}

	delete current;
}

template<class T>
void LinkedStr<T>::removeFirst() {
	if (head == nullptr) return;

	NodePtr temp = head;
	head = head->next;
	delete temp;
}

template<class T>
void LinkedStr<T>::removeLast() {
	if (head == nullptr) return;

	if (head->next == nullptr) {
		delete head;
		head = nullptr;
		return;
	}

	NodePtr current = head;
	while (current->next->next != nullptr) {
		current = current->next;
	}

	delete current->next;
	current->next = nullptr;
}

#endif