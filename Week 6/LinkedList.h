#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>

template<class T>
class LinkedList {
protected:
	struct Node {
		T value;
		Node* next;
	};
	using NodePtr = Node * ;
	NodePtr head;

public:
	LinkedList();
	~LinkedList();

	bool isEmpty();
	void insertAfter(T targetValue, T newValue);
	void deleteValue(T targetValue);
	void pushFront(T newValue);
	T popFront();
};

template<class T>
LinkedList<T>::LinkedList() {
	head = nullptr;
}

template<class T>
LinkedList<T>::~LinkedList() {
	NodePtr current = head;
	while (current != nullptr) {
		NodePtr nextNode = current->next;
		delete current;
		current = nextNode;
	}
}

template<class T>
bool LinkedList<T>::isEmpty() {
	return (head == nullptr);
}

template<class T>
void LinkedList<T>::insertAfter(T targetValue, T newValue) {
	NodePtr current = head;
	while (current != nullptr && current->value != targetValue) {
		current = current->next;
	}

	if (current == nullptr) {
		std::cerr << "Value not found in the list.\n";
		exit(1);
	}

	NodePtr newNode = new Node;
	newNode->value = newValue;
	newNode->next = current->next;
	current->next = newNode;
}

template<class T>
void LinkedList<T>::deleteValue(T targetValue) {
	NodePtr current = head;
	NodePtr previous = nullptr;

	while (current != nullptr && current->value != targetValue) {
		previous = current;
		current = current->next;
	}

	if (current == nullptr) {
		std::cerr << "Value not found in the list.\n";
		exit(1);
	}

	if (previous == nullptr) {
		head = current->next;
	}
	else {
		previous->next = current->next;
	}

	delete current;
}

template<class T>
void LinkedList<T>::pushFront(T newValue) {
	NodePtr newNode = new Node;
	newNode->value = newValue;
	newNode->next = head;
	head = newNode;
}

template<class T>
T LinkedList<T>::popFront() {
	if (isEmpty()) {
		std::cerr << "Error: The list is empty.\n";
		exit(1);
	}

	NodePtr temp = head;
	T valueToReturn = temp->value;
	head = head->next;
	delete temp;
	return valueToReturn;
}

#endif