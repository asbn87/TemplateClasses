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
	void Push(T data) { stack.push_back(data); }; //jag tycker det ser mer enhetligt ut med kodblocket på egna rader...
	T Pop()
	{ 
		T data = stack.back(); 
		stack.erase(stack.end() - 1); //går det inte bara att erasea stack.back()?
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