#pragma once

template <class T>
class LinkedList
{
private:
	class Node 
	{
	public:
		T data;
		LinkedList<T>::Node* next;

		Node() : data{}, next{ nullptr } {}
		Node(T data)
		{
			this->data = data;
			this->next = nullptr;
		}
		~Node() {}
	};

	LinkedList<T>::Node* head, *tail;

	LinkedList<T>::Node* GetNode(int index)
	{
		LinkedList<T>::Node* current = this->head;
		int count{ 0 };
		while (count != index)
		{
			if (current->next != nullptr)
			{
				current = current->next;
				count++;
			}
			else 
			{ 
				return nullptr;
			}
		}
		return current;
	}

public:
	LinkedList() : head{ nullptr }, tail{ nullptr } {}

	~LinkedList() 
	{
		Node* current = this->head;
		if (current == nullptr)
		{
			return;
		}
		Node* next = this->head->next;
		while (current != nullptr)
		{
			delete current;
			current = next;
			next = next->next;
		}
	}

	void PushFront(T data)
	{
		LinkedList<T>::Node* node = new LinkedList<T>::Node(data);

		if (head == nullptr)
		{
			this->head = node;
			this->tail = node;
		}
		else
		{
			node->next = head;
			this->head = node;
		}
	}

	void PushBack(T data)
	{
		LinkedList<T>::Node* node = new LinkedList<T>::Node(data);

		if (this->head == nullptr)
		{
			this->head = node;
			this->tail = node;
		}
		else
		{
			this->tail->next = node;
			this->tail = node;
		}
	}

	T PopFront()
	{
		T data{};
		LinkedList<T>::Node* node = this->head;
		if (node != nullptr)
		{
			data = node->data;
			if (node->next != nullptr)
			{ 
				this->head = this->head->next; 
			}
			else
			{
				this->head = nullptr;
				this->tail = nullptr;
			}
			delete node;
		}
		return data;
	}

	T PopBack()
	{
		T data{};
		LinkedList<T>::Node* current = this->head;
		LinkedList<T>::Node* previous = current;
		LinkedList<T>::Node* node = this->tail;
		if (current != nullptr && node != nullptr)
		{
			data = node->data;
			if (current->next == nullptr)
			{
				this->head = nullptr;
				this->tail = nullptr;
				return data;
			}
			while (current->next != nullptr)
			{
				previous = current;
				current = current->next;
			}
			previous->next = nullptr;
			this->tail = previous;
			delete node;
		}
		return data;
	}

	int Size()
	{
		LinkedList<T>::Node* current = this->head;
		int size{ 0 };
		while (current != nullptr)
		{
			current = current->next;
			size++;
		}
		return size;
	}

	void Insert(int index, T data)
	{
		if (index >= this->Size() || index < 0)
		{
			return;
		}
		if (index > 0)
		{
			LinkedList<T>::Node* node = new LinkedList<T>::Node(data);
			LinkedList<T>::Node* previous = GetNode(index - 1);
			node->next = previous->next;
			previous->next = node;
		}
		else 
		{ 
			PushFront(data); 
		}
	}

	void Delete(int index)
	{
		if (index >= this->Size() || index < 0)
		{
			return;
		}
		if (index > 0)
		{
			LinkedList<T>::Node* node = GetNode(index);
			LinkedList<T>::Node* previous = GetNode(index - 1);
			previous->next = node->next;
			delete node;
		}
		else 
		{ 
			PopFront(); 
		}
	}

	T Get(int index)
	{
		T data{};
		LinkedList<T>::Node* node = GetNode(index);
		if(node != nullptr)
		{ 
			return node->data;
		}
		return data;
	}
};