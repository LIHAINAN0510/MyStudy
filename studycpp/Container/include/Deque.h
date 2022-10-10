#ifndef _DEQUE_H_
#define _DEQUE_H_

namespace Container
{
	class _declspec(dllexport) MyCircularDeque {
	public:
		MyCircularDeque(int k);

		bool insertFront(int value);

		bool insertLast(int value);


		bool deleteFront();

		bool deleteLast();

		int getFront();

		int getRear();

		bool isEmpty();

		bool isFull();
	private:
		int deque_Size = 0;
		int max_size = 0;
		int *address;
		int back = 0;


	};
}

#endif // _Deque_H_
