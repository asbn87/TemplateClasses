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
		T em = stack.back(); 
		stack.erase(stack.end() - 1); 
		return em;
	};
	int Size() { return stack.size(); };
	bool Empty() { return stack.empty(); };
};