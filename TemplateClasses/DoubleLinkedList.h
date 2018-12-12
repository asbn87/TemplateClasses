#pragma once

template <class T>
class DoubleLinkedList
{
private:
	class Node 
	{
	public:
		T data;
		DoubleLinkedList<T>::Node* next;
		DoubleLinkedList<T>::Node* previous;

		Node() : data{}, next{ nullptr }, previous{ nullptr } {}
		Node(T data)
		{
			this->data = data;
			this->next = nullptr;
			this->previous = nullptr;
		}
		~Node() {}
	};

	DoubleLinkedList<T>::Node* head, *tail;

	DoubleLinkedList<T>::Node* GetNode(int index)
	{
		DoubleLinkedList<T>::Node* temp = this->head;
		int count = 0;
		while (count != index)
		{
			if (temp == nullptr)
			{
				return nullptr;
			}
			temp = temp->next;
			count++;
		}
		return temp;
	}

public:
	DoubleLinkedList() : head{ nullptr }, tail{ nullptr } {}

	~DoubleLinkedList() 
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
		DoubleLinkedList<T>::Node* node = new DoubleLinkedList<T>::Node(data);

		if (head == nullptr)
		{
			this->head = node;
			this->tail = node;
		}
		else
		{
			this->head->previous = node;
			node->next = this->head;
			this->head = node;
		}
	}

	void PushBack(T data)
	{
		DoubleLinkedList<T>::Node* node = new DoubleLinkedList<T>::Node(data);
		if (head == nullptr)
		{
			this->head = node;
			this->tail = node;
		}
		else
		{
			node->previous = this->tail;
			this->tail->next = node;
			this->tail = node;
		}
	}

	T PopFront()
	{
		T data{};
		DoubleLinkedList<T>::Node* node = this->head;
		if (node != nullptr)
		{
			data = node->data;
			if (node->next != nullptr)
			{
				this->head = this->head->next;
				this->head->previous = nullptr;
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
		DoubleLinkedList<T>::Node* node = this->tail;
		if (node != nullptr)
		{
			data = node->data;
			if (node->previous != nullptr)
			{
				this->tail = this->tail->previous;
				this->tail->next = nullptr;
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

	int Size()
	{
		if (this->head == nullptr)
		{
			return 0;
		}
		DoubleLinkedList<T>::Node* temp = this->head;
		int size = 0;
		while (temp != nullptr)
		{
			temp = temp->next;
			size++;
		}
		return size;
	}

	T Get(int index)
	{
		T data{};
		DoubleLinkedList<T>::Node* node = GetNode(index);
		if (node != nullptr)
		{
			return node->data; 
		}
		return data;
	}

	void Insert(int index, T data)
	{
		if (index > 0)
		{
			DoubleLinkedList<T>::Node* node = new DoubleLinkedList::Node(data);
			DoubleLinkedList<T>::Node* temp = GetNode(index);
			node->next = temp;
			temp->previous->next = node;
			temp->previous = node;
			node->previous = temp->previous;
		}
		else 
		{
			PushFront(data); 
		}
	}

	void Delete(int index)
	{
		DoubleLinkedList<T>::Node* temp = GetNode(index);
		temp->previous->next = temp->next;
		temp->next->previous = temp->previous;
		delete temp;
	}
};
