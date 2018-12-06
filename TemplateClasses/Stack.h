#pragma once
#include <vector>

template <class T>
class Stack
{
private:
	std::vector<T> stack;
public:
	Stack() {};
	~Stack() {};
	void Push(T data) { stack.push_back(data); };
	T Pop()
	{ 
		T data = stack.back(); 
		stack.pop_back();
		return data;
	};
	T Top()
	{
		T data = stack.back();
		return data;
	}
	int Size() { return stack.size(); };
	bool Empty() { return stack.empty(); };
};