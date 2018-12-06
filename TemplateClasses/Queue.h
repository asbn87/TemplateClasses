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
		if (this->queue.size() == 0)
		{
			this->queue.push_back(data);
			this->indexOfFirst = 0;
			this->indexOfLast = 0;
		}
		else if (this->indexOfFirst < this->indexOfLast || this->indexOfFirst == this->indexOfLast)
		{
			if (this->indexOfLast + 1 == this->queue.size() && this->queue[0] != NULL)
			{
				this->queue.push_back(data);
				this->indexOfLast++;
			}
			else if (this->indexOfLast + 1 == this->queue.size() && this->queue[0] == NULL)
			{
				this->queue[0] = data;
				this->indexOfLast = 0;
			}
			else
			{
				this->queue[this->indexOfLast + 1] = data;
				this->indexOfLast++;
			}
		}
		else if (this->indexOfLast < this->indexOfFirst)
		{
			if (this->queue[this->indexOfLast + 1] == NULL)
			{
				this->queue[this->indexOfLast + 1] = data;
			}
			else
			{
				this->queue.insert(this->queue.begin() + (this->indexOfLast + 1), data);
			}
			this->indexOfLast++;
		}
	}

	T Pop()
	{
		T temp = this->queue[this->indexOfFirst];
		this->queue[this->indexOfFirst] = NULL;
		if (this->indexOfFirst + 1 == queue.size())
		{
			this->indexOfFirst = 0;
		}
		else
		{
			this->indexOfFirst++;
		}
		return temp;
	}
};
