#ifndef __SINGLY__LINKED__LIST__FUNCTIONS__
#define __SINGLY__LINKED__LIST__FUNCTIONS__

#include "singlyLinkedList.h"

template<class TYPE>
inline LinkedList<TYPE>::LinkedList()
	:pHead(nullptr)
	, pTail(nullptr)
	, currentSize(0)
{}

template<class TYPE>
inline LinkedList<TYPE>::~LinkedList()
{
	clean();
}

template<class TYPE>
inline LinkedList<TYPE>::LinkedList(const LinkedList<TYPE>& input)
	:pHead(nullptr)
	, pTail(nullptr)
	, currentSize(0)
{
	copy(input);
}


template<class TYPE>
inline LinkedList<TYPE>& LinkedList<TYPE>::operator=(const LinkedList<TYPE> & input)
{
	if (this != &input)
	{
		clean();
		copy(input);
	}
	return *this;
}


template<class TYPE>
inline void LinkedList<TYPE>::pushFront(const TYPE& element)
{
	if (isEmpty())
	{
		pHead = new node(element);
		pTail = pHead;
		currentSize++;
		return;
	}
	node* new_element = new node(element);
	new_element->pNext = pHead;
	pHead = new_element;
	currentSize++;
}

template<class TYPE>
inline void LinkedList<TYPE>::pushBack(const TYPE& element)
{
	if (isEmpty())
	{
		pHead = new node(element);
		pTail = pHead;
		currentSize++;
		return;
	}
	pTail->pNext = new node(element);
	pTail = pTail->pNext;
	currentSize++;
}
template<class TYPE>
inline void LinkedList<TYPE>::popAt(int index)
{
	if (index == 0)
		popFront();
	if (index == currentSize - 1)
		popBack();
	else
	{
		node* connector = pHead;
		node* removal = pHead->pNext;
		for (int i = 1; i < index; i++)
		{
			connector = connector->pNext;
			removal = removal->pNext;
		}

		connector->pNext = removal->pNext;
		delete removal;
		currentSize--;
	}
}
template<class TYPE>
inline void LinkedList<TYPE>::popFront()
{
	if (isEmpty())
		return;
	node* destroyer = pHead;
	pHead = pHead->pNext;
	delete destroyer;
	currentSize--;
}

template<class TYPE>
inline void LinkedList<TYPE>::popBack()
{
	if (isEmpty())
		return;
	if (currentSize == 1)
	{
		delete pHead;
		pHead = nullptr;
		pTail = nullptr;
		currentSize = 0;
		return;
	}
	node* destroyer = pHead;
	while (destroyer->pNext != pTail)
		destroyer = destroyer->pNext;
	delete pTail;
	pTail = destroyer;
	pTail->pNext = nullptr;
	currentSize--;
}

template<class TYPE>
inline const TYPE& LinkedList<TYPE>::front()
{
	if (isEmpty())
		throw "the list is empty!";
	return pHead->data;
}

template<class TYPE>
inline const TYPE& LinkedList<TYPE>::back()
{
	if (isEmpty())
		throw "the list is empty!";
	return pTail->data;
}

template<class TYPE>
inline const TYPE& LinkedList<TYPE>::elementAt(int index)
{
	if (index < 0 || index > currentSize)
		throw "invalid index";
	node* element = pHead;
	for (int i = 0; i < index; i++)
		element = element->pNext;
	return element->data;
}

template<class TYPE>
inline const void LinkedList<TYPE>::print() const
{
	node * it = pHead;
	for (int i = 0; i < currentSize; i++)
	{
		std::cout << it->data << " ";
		it = it->pNext;
	}
}

template <class TYPE>
inline bool LinkedList<TYPE>::search(const TYPE& element) const
{
	node * it = pHead;
	while (it != nullptr)
	{
		if (it->data == element)
			return true;
		it = it->pNext;
	}
	return false;
}

template<class TYPE>
inline void LinkedList<TYPE>::sort()
{
	node *i, *j;
	for (i = pHead; i != NULL; i = i->pNext)
	{
		node *min;
		min = i;
		for (j = i->pNext; j != NULL; j = j->pNext)
		{
			if (j->data < min->data)
				min = j;
		}
		if (min != i)
		{
			TYPE temp;
			temp = min->data;
			min->data = i->data;
			i->data = temp;
		}
	}
}

template<class TYPE>
inline int LinkedList<TYPE>::getSize() const
{
	return currentSize;
}

template<class TYPE>
inline void LinkedList<TYPE>::clean()
{
	node* destroyer;
	while (pHead != nullptr)
	{
		destroyer = pHead;
		pHead = pHead->pNext;
		delete destroyer;
	}

	pHead = nullptr;
	pTail = nullptr;
	currentSize = 0;
}

template<class TYPE>
inline void LinkedList<TYPE>::copy(const LinkedList<TYPE> & input)
{
	if (input.isEmpty())
		return;
	try
	{
		pHead = new node(input.pHead->data);
		node* toCopy = input.pHead;
		node* copier = pHead;

		while (toCopy->pNext != nullptr)
		{
			toCopy = toCopy->pNext;
			copier->pNext = new node(toCopy->data);
			copier = copier->pNext;
		}
		pTail = copier;
	}
	catch (std::bad_alloc & e)
	{
		clean();
		throw;
	}
	currentSize = input.currentSize;
}

template<class TYPE>
inline bool LinkedList<TYPE>::isEmpty() const
{
	return currentSize == 0;
}


#endif // !__SINGLY__LINKED__LIST__FUNCTIONS__
#pragma once
