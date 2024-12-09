#include <iostream>
using namespace std;
template <class T>
class CircularQueue
{
	T* data;
	int capacity;
	int count;
	int frontVal;
	
public:
	void resize();
	CircularQueue(int size = 8);
	void enqueue(T item);
	void dequeue();
	T front();
	int size();
	template <class T>
	friend ostream& operator<<(ostream& out, CircularQueue<T>& c);
	
};
template <class T>
void CircularQueue<T>::resize()
{
	T* temp = new T[capacity * 2];
	for (int i = 0; i < count; i++)
	{
		int index = (frontVal + i) % capacity;
		temp[i] = data[index];
	}
	delete[] data;
	data = temp;
	frontVal = 0;
	capacity *= 2;
}
template <class T>
ostream& operator<<(ostream& out, CircularQueue<T>& c)
{
	for (int i = 0; i < c.capacity; i++)
	{
		if (i != 0)
			out << "|";
		out << c.data[i];
	}
	return out<<endl;
}
template <class T>
CircularQueue<T>::CircularQueue(int size)
{
	this->data = new T[size];
	capacity = size;
	count = frontVal = 0;
	for (int i = 0; i < size; i++)
	{
		data[i] = 0;
	}
}
template <class T>
void CircularQueue<T>::enqueue(T item)
{
	if (count < capacity)
	{
		int index = (frontVal + count) % capacity;
		this->data[index] = item;
		count++;
		
	}
	else
	{
		throw std::logic_error("Queue is full");
	}
	
}
template <class T>
void CircularQueue<T>::dequeue()
{	
	if (count > 0)
	{
		count--;
		data[frontVal] = 0;
		frontVal++;
		if (frontVal == capacity)
			frontVal = 0;
	}
}
template <class T>
T CircularQueue<T>::front()
{
	return data[frontVal];
}

template <class T>
int CircularQueue<T>::size()
{
	return count;
}