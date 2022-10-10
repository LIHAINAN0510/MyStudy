#ifndef _VEC_H_
#define _VEC_H_
#include <iostream>
using namespace std;
namespace Container
{
	template<class T>
	class _declspec(dllexport) Vec
	{
	public:
		explicit Vec();

		Vec(const Vec &target);

		~Vec();

		T& operator[](int i);

		void push_back(T value);

		void pop_back();

		T& front();

		T& back();

		T& at(int i);

	private:
		int currentPos = 0;
		int size = 0;
		T* address;
	};
}
#endif 
