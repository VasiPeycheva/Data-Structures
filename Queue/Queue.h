#ifndef __QUEUE__
#define __QUEUE__
#include <iostream>

template <class TYPE>
class Queue {
public:
	//Big 4
	Queue();
	Queue(int capacity);
	~Queue();
	Queue(const Queue & copy);
	Queue& operator=(const Queue & copy);

	//interface
	void push(const TYPE &);
	bool pop();
	void peek(TYPE&);

	const TYPE& operator[](int index) const;
	TYPE& operator[](int index);
private:
	//help functions
	void copy(const Queue & to_copy);
	void clean();
private:
	TYPE* data;
	int capacity;
	short front;
	short rear;
	bool isEmpty;

};

template<class TYPE>
inline Queue<TYPE>::Queue()
{
	data(NULL);
	capacity = 0;
	front = 0;
	rear = 0;
	isEmpty = 1;
}

template<class TYPE>
inline Queue<TYPE>::Queue(int capacity)
{
	if(capacity >= 2)
	try
	{
		data = new TYPE[capacity];
	}
	catch (bad_alloc & e)
	{
		capacity /= 2;
		data = new TYPE[capacity];
	}
	
}

template<class TYPE>
inline Queue<TYPE>::~Queue()
{
	clean();
}

template<class TYPE>
inline Queue<TYPE>::Queue(const Queue<TYPE> & to_copy)
{
	copy(to_copy);
}

template<class TYPE>
inline Queue<TYPE>& Queue<TYPE>::operator=(const Queue<TYPE> & to_copy)
{
	if (this != &to_copy)
	{	
		clean();
		copy();
	}
	return *this;
}


template<class TYPE>
inline void Queue<TYPE>::push(const TYPE & element)
{
	if ((rear == front) && !isEmpty)
		return;

	data[rear++] = element;

	if (rear == capacity)
		rear = 0;
	isEmpty = 0;
}

template<class TYPE>
inline bool Queue<TYPE>::pop()
{
	if (isEmpty)
		return false;

	front++;

	if (front == capacity)
		front = 0;
	if (front == rear)
		isEmpty = 1;

	return true;
}

template<class TYPE>
inline void Queue<TYPE>::peek(TYPE& element)
{
	if (isEmpty)
		return;

	element = data[front];
}

template<class TYPE>
inline void Queue<TYPE>::copy(const Queue<TYPE> & to_copy)
{
	for (int i = 0; i < capacity; i++)
		data[i] = to_copy.data[i];
	front = to_copy.front;
	rear = to_copy.rear;
	isEmpty = to_copy.isEmpty;

}

template<class TYPE>
inline void Queue<TYPE>::clean()
{
	delete[] data;
	front = 0;
	rear = 0;
	isEmpty = true;
}


#endif // !__QUEUE__
