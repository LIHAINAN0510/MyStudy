#include "Deque.h"
using namespace Container;

MyCircularDeque::MyCircularDeque(int k)
{
	max_size = k;
	address = new int[k];
}

bool MyCircularDeque::insertFront(int value)
{
	if (deque_Size == max_size)
		return false;
	for (int i = deque_Size; i > 0; i--)
	{
		address[i + 1] = address[i];
	}
	address[0] = value;
	deque_Size++;
	back++;
	return true;
}

bool MyCircularDeque::insertLast(int value)
{
	if (deque_Size == max_size)
		return false;
	deque_Size++;
	back++;
	address[back] = value;
	return true;
}

bool MyCircularDeque::deleteFront()
{
	if (deque_Size == 0)
		return false;
	for (int i = 0; i < deque_Size; i++)
	{
		address[i] = address[i + 1];
	}
	deque_Size--;
	back--;
	return true;
}

bool MyCircularDeque::deleteLast()
{
	if (deque_Size == 0)
		return false;
	deque_Size--;
	back--;
	return true;
}

int MyCircularDeque::getFront()
{
	if (deque_Size == 0)
		return -1;
	return address[0];
}

int MyCircularDeque::getRear()
{
	if (deque_Size == 0)
		return -1;
	return address[back];
}

bool MyCircularDeque::isEmpty()
{
	if (deque_Size == 0)
		return true;
	return false;
}

bool MyCircularDeque::isFull()
{
	if (deque_Size == max_size)
		return true;
	return false;
}
