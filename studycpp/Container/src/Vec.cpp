#include "Vec.h"
using namespace Container;

template<class T>
inline Container::Vec<T>::Vec()
{
	size = 0;
	address = new T[3];
}

template<class T>
Container::Vec<T>::Vec(const Vec & target)
{
	target->address = new T[size];
	for (size_t i = 0; i < size; i++)
	{
		target->address[i] = address[i];
	}
	target->size = size;
	target->currentPos = currentPos;
}

template<class T>
Container::Vec<T>::~Vec()
{
	delete[] address;
}

template<class T>
T & Container::Vec<T>::operator[](int i)
{
	return this->address[i];
}

template<class T>
void Container::Vec<T>::push_back(T value)
{
	if (currentPos % 3 != 0 || currentPos == 0)
		address[currentPos] = value;
	else
	{
		T* newaddress = new T[currentPos + 3];
		T* temp = address;
		for (int i = 0; i < size; i++)
			newaddress[i] = address[i];
		address = newaddress;
		delete[] temp;
		address[currentPos] = value;
	}
	currentPos++;
	size++;
}

template<class T>
void Container::Vec<T>::pop_back()
{
	if (size == 0) return;
	currentPos--;

}

template<class T>
T & Container::Vec<T>::front()
{
	if(size!=0) return  address[0];
}

template<class T>
T & Container::Vec<T>::back()
{
	if (size != 0) return address[currentPos - 1];
}

template<class T>
T& Container::Vec<T>::at(int i)
{
	return address[i];
}

