#pragma once
template <class T>
class ArrayedStack
{
	T* data;
	int _top;
	int capacity;
public:
	ArrayedStack(int size = 50);
	bool push(T &item);
	void pop();
	T& top();
	int count();
	void clear();
	bool isEmpty();
	~ArrayedStack();
};

template <class T>
ArrayedStack<T>::ArrayedStack(int size)
{
	this->data = new T[size];
	capacity = size;
	_top = 0;
}
template <class T>
bool ArrayedStack<T>::push(T& item)
{
	if (_top < capacity)
	{
		this->data[_top] = item;
		_top++;
		return true;
	}
	throw std::logic_error("Stack Full");
}
template <class T>
void ArrayedStack<T>::pop()
{
	if (_top > 0)
		_top--;
}
template <class T>
T& ArrayedStack<T>::top()
{
	if (_top > 0)
	{
		return this->data[_top - 1];
	}
	throw std::logic_error("Stack is empty");
}
template <class T>
int ArrayedStack<T>::count()
{
	return _top;
}
template <class T>
void ArrayedStack<T>::clear()
{
	_top = 0;
}
template <class T>
bool ArrayedStack<T>::isEmpty()
{
	return _top == 0;
}
template <class T>
ArrayedStack<T>::~ArrayedStack()
{
	delete[]data;
	data = nullptr;
}