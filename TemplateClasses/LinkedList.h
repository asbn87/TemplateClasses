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

		Node() {}
		Node(T data)
		{
			this->data = data;
			this->next = NULL;
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
			if (current->next != NULL)
			{
				current = current->next;
				count++;
			}
			else 
			{ 
				return NULL; 
			}
		}
		return current;
	}

public:
	LinkedList() : head{ NULL }, tail{ NULL } {}

	~LinkedList() 
	{
		Node *current = this->head;
		if (current == NULL)
		{
			return;
		}
		Node *next = this->head->next;
		while (current != NULL)
		{
			delete current;
			current = next;
			next = next->next;
		}
	}

	void PushFront(T data)
	{
		LinkedList<T>::Node* node = new LinkedList<T>::Node(data);

		if (head == NULL)
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

		if (this->head == NULL)
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
		LinkedList<T>::Node* node = this->head;
		T data;
		if (node != NULL)
		{
			data = node->data;
			if (node->next != NULL) 
			{ 
				this->head = this->head->next; 
			}
			else
			{
				this->head = NULL;
				this->tail = NULL;
			}
			delete node;
			return data;
		}
		return data;
	}

	T PopBack()
	{
		LinkedList<T>::Node* current = this->head;
		LinkedList<T>::Node* previous = current;
		LinkedList<T>::Node* node = this->tail;
		T data;
		if (current != NULL && node != NULL)
		{
			data = node->data;
			if (current->next == NULL)
			{
				this->head = NULL;
				this->tail = NULL;
				return data;
			}
			else
			{
				while (current->next != NULL)
				{
					previous = current;
					current = current->next;
				}
			}
			previous->next = NULL;
			this->tail = previous;
			delete node;
		}
		return data;
	}

	int Size()
	{
		LinkedList<T>::Node* current = this->head;
		int size{ 0 };
		while (current != NULL)
		{
			current = current->next;
			size++;
		}
		return size;
	}

	void Insert(int index, T data)
	{
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
		T data;
		LinkedList<T>::Node* node = GetNode(index);
		if(node != NULL) 
		{ 
			return node->data; 
		}
		else 
		{ 
			return data; 
		}
	}
};