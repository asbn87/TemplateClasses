#pragma once
#include <vector>

template <class T>
class Queue
{
private:
	std::vector<T> queue;
	int indexOfFirst;
	int indexOfLast;

	public:
	Queue(){}
	~Queue(){}

	int Size()
	{
		if (this->indexOfFirst > this->indexOfLast)
		{
			return this->queue.size() - (this->indexOfFirst - this->indexOfLast) + 1;
		}
		return this->queue.size() - this->indexOfFirst;
	}

	void Push(T data)
	{
		if (this->indexOfFirst < this->indexOfLast)
		{
			if (this->indexOfLast + 1 == this->queue.size() && this->queue[0] != nullptr)
			{
				this->queue.push_back(data);
				this->indexOfLast += 1;
			}
			else if (this->indexOfLast + 1 == this->queue.size() && this->queue[0] == nullptr)
			{
				this->queue[0] = data;
				this->indexOfLast = 0;
			}
			else
			{
				this->queue[this->indexOfLast + 1] = data;
				this->indexOfLast += 1;
			}
		}
		if (this->indexOfLast < this->indexOfFirst)
		{
			if (this->queue[indexOfLast + 1] == nullptr)
			{
				this->queue[indexOfLast + 1] = data;
			}
			else
			{
				this->queue.insert(this->indexOfLast + 1, data);
			}
		}
	}

	T Pop()
	{
		T temp = this->queue[this->indexOfFirst];
		this->queue[this->indexOfFirst] = nullptr;
		if (this->indexOfFirst + 1 == queue.size())
		{
			this->indexOfFirst = 0;
		}
		else
		{
			this->indexOfFirst += 1;
		}
		return temp;
	}
};
