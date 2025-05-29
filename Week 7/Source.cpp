#include <iostream>
using namespace std;

template <class T>
class DoublyLinkedList {
private:
	struct Node {
		T value;
		Node* prev;
		Node* next;
	};

	using NodePtr = Node * ;
	NodePtr head;

public:
	DoublyLinkedList();
	~DoublyLinkedList();

	void display() const;
	void insertAtFront(T item);
	void deleteFromFront();
	void insertAtEnd(T item);
	void deleteFromEnd();
	void insertAfterValue(T target, T newValue);
};

// Constructor
template <class T>
DoublyLinkedList<T>::DoublyLinkedList() {
	head = nullptr;
}

// Destructor
template <class T>
DoublyLinkedList<T>::~DoublyLinkedList() {
	NodePtr current = head;
	while (current != nullptr) {
		NodePtr next = current->next;
		delete current;
		current = next;
	}
}

// Insert at front
template <class T>
void DoublyLinkedList<T>::insertAtFront(T item) {
	NodePtr newNode = new Node{ item, nullptr, head };

	if (head != nullptr) {
		head->prev = newNode;
	}

	head = newNode;
}

// Display list
template <class T>
void DoublyLinkedList<T>::display() const {
	if (head == nullptr) {
		cout << "The list is empty.\n";
		return;
	}

	NodePtr current = head;
	int index = 1;

	while (current != nullptr) {
		cout << "Node " << index++ << ": " << current->value << endl;
		current = current->next;
	}
}

// Delete from front
template <class T>
void DoublyLinkedList<T>::deleteFromFront() {
	if (head == nullptr) {
		cout << "The list is empty.\n";
		return;
	}

	NodePtr toDelete = head;
	head = head->next;

	if (head != nullptr) {
		head->prev = nullptr;
	}

	delete toDelete;
}

// Insert at end
template <class T>
void DoublyLinkedList<T>::insertAtEnd(T item) {
	NodePtr newNode = new Node{ item, nullptr, nullptr };

	if (head == nullptr) {
		head = newNode;
		return;
	}

	NodePtr current = head;
	while (current->next != nullptr) {
		current = current->next;
	}

	current->next = newNode;
	newNode->prev = current;
}

// Delete from end
template <class T>
void DoublyLinkedList<T>::deleteFromEnd() {
	if (head == nullptr) {
		cout << "The list is empty.\n";
		return;
	}

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

// Insert after specific value
template <class T>
void DoublyLinkedList<T>::insertAfterValue(T target, T newValue) {
	if (head == nullptr) {
		cout << "List is empty. Inserting node with new value.\n";
		head = new Node{ newValue, nullptr, nullptr };
		return;
	}

	NodePtr current = head;
	while (current != nullptr && current->value != target) {
		current = current->next;
	}

	if (current == nullptr) {
		cout << "Value " << target << " not found in the list.\n";
		return;
	}

	NodePtr newNode = new Node{ newValue, current, current->next };

	if (current->next != nullptr) {
		current->next->prev = newNode;
	}

	current->next = newNode;
}