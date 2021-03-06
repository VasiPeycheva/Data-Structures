#ifndef __SINGLY__LINKED__LIST__
#define __SINGLY__LINKED__LIST__

#include <iostream>
template<class TYPE>
class LinkedList
{
public:

	//Г4
	LinkedList();
	~LinkedList();
	LinkedList(const LinkedList &);
	LinkedList& operator=(const LinkedList &);

	//interface
	void pushFront(const TYPE &);
	void pushBack(const TYPE &);

	void popAt(int index);
	void popFront();
	void popBack();

	const TYPE& front();
	const TYPE& back();
	const TYPE& elementAt(int index);

	const void print() const;
	bool search(const TYPE &) const;
	void sort();

	int getSize() const;

private:
	//help functions
	void copy(const LinkedList &);
	void clean();
	bool isEmpty() const;

private:
	struct node
	{
		TYPE data;
		node* pNext;
		node(TYPE input_data, node* ptrNext = nullptr)
		{
			data = input_data;
			pNext = ptrNext;
		}
	};

	node* pHead;
	node* pTail;
	int currentSize;
};


#include "singlyLinkedListFunctions.h"

#endif // !__SINGLY__LINKED__LIST__
#pragma once
