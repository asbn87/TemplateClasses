#pragma once
#include <vector>

template <class T>
class Stack
{
private:
	std::vector<T> stack;
public:
	Stack() {}
	~Stack() {}

	void Push(T data) 
	{ 
		stack.push_back(data); 
	}

	T Pop()
	{ 
		T data{};
		if (this->Size() <= 0)
		{
			return data;
		}
		data = stack.back(); 
		stack.pop_back();
		return data;
	}

	int Size() 
	{ 
		return stack.size();
	}
};