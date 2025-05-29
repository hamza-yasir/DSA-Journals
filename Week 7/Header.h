#pragma once

#include<iostream>
#include<conio.h>
using namespace std;

template<class T>
class Double{
	struct node {
		T data;
		node* prev;
		node* next;
		node (T t,node*p,node*n):data(t),prev(p),next(n){}
	};
	node* head;
	node* tail;

public:
	Double() :head(0), tail(0) {}

	template<int N>
	Double(T(&arr)[N]) : head(0), tail(0) {
		for (int i(0); i != N; ++i)
			push_back(arr[i]);
	}

	bool empty()const{ return (!head||!tail) }
	operator bool() const { return !empty(); }

	void push_back(T);
	void push_front(T);

	T pop_back();
	T pop_front();

	~Double() {
		while (head) {
			node*temp(head);
			head = head->next;
			delete temp;

		}
	}
};

template<class T>
void Double<T>::push_back(T data) {
	tail = new node(data, tail, 0);
	if (tail->prev)
		tail->prev->next = tail;

	if (empty())
		head = tail;
}

template<class T>
void Double<T>::push_front(T data) {
	head = new node(data, 0, head);
	if (head->next)
		head->next->prev = head;
	if (empty())
		tail = head;
}

template<typename T>
T Double<T>::pop_back() {
	if (empty())
		throw("Double : list empty");
}