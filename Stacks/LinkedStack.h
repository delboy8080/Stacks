#include "DList.h"
#pragma once
template <class T>
class LinkedStack : private DList<T>
{
	//DList<T> items;
public:
	bool push(T& item);
	void pop();
	T& top();
	int count();
	void clear();
	bool isEmpty();
};

template <class T>
bool LinkedStack<T>::push(T& item)
{
	this->append(item);
	return true;
}
template <class T>
void LinkedStack<T>::pop()
{
	this->removeTail();
}
template <class T>
T& LinkedStack<T>::top()
{
	if(this->tail != nullptr)
		return this->tail->data;
	throw std::logic_error("Stack is empty");
}
template <class T>
int LinkedStack<T>::count()
{
	return this->size();
}
template <class T>
void LinkedStack<T>::clear()
{
	DListIterator<T> it = this->getIterator();
	while (it.isValid)
		it = this->remove(it);
}
template <class T>
bool LinkedStack<T>::isEmpty()
{
	return this->size()==0;
}