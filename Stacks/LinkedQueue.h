#include <iostream>
#include "DList.h"

template <class T>
class LinkedQueue
{
	DList<T> items;
public:
	void enqueue(T& item);
	void dequeue();
	T& front();
	int size();
};
template <class T>
void LinkedQueue<T>::enqueue(T& item)
{
	items.append(item);
}
template <class T>
void LinkedQueue<T>::dequeue()
{
	items.removeHead();
}
template <class T>
T& LinkedQueue<T>::front()
{
	if(items.head != nullptr)
		return items.head->data;
	throw std::logic_error("Queue is empty");
}
template <class T>
int LinkedQueue<T>::size()
{
	return items.size();
}