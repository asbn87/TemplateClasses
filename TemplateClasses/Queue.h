#pragma once
#include <vector>

template <class T>
class Queue
{
private:
	std::vector<T> queue;
public:
	Queue(){}
	~Queue(){}

	int Size() 
	{ 
		return queue.size(); 
	}

	void Push(T data) 
	{ 
		queue.insert(queue.end(), data); 
	}

	T Pop()
	{
		T data{};
		if (this->Size() <= 0)
		{
			return data;
		}
		data = queue.front();
		queue.erase(queue.begin());
		return data;
	}
};