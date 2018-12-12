#pragma once

template <class T>
class DoubleLinkedList
{
private:
	class Node 
	{
	public:
		T data;
		DoubleLinkedList<T>::Node *next;
		DoubleLinkedList<T>::Node *previous;

		Node() {};
		Node(T data)
		{
			this->data = data;
			this->next = NULL;
			this->previous = NULL;
		};
		~Node() {};
	};

	DoubleLinkedList<T>::Node *head, *tail;
	DoubleLinkedList<T>::Node *GetNode(int index)
	{
		DoubleLinkedList<T>::Node *temp = this->head;
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
	DoubleLinkedList() : head{ NULL }, tail{ NULL } {}
	~DoubleLinkedList() 
	{
		Node *current = this->head;
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
		DoubleLinkedList<T>::Node* node = new DoubleLinkedList<T>::Node(data);

		if (head == NULL)
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
		if (head == NULL)
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
		DoubleLinkedList<T>::Node* node = this->head;
		T data = node->data;
		if (node->next != NULL)
		{
			this->head = this->head->next;
			this->head->previous = NULL;
		}
		else
		{
			this->head = NULL;
			this->tail = NULL;
		}
		delete node;
		return data;
	}

	T PopBack()
	{
		DoubleLinkedList<T>::Node* node = this->tail;
		T data = node->data;
		if (node->previous != NULL)
		{
			this->tail = this->tail->previous;
			this->tail->next = NULL;
		}
		else
		{
			this->head = NULL;
			this->tail = NULL;
		}
		delete node;
		return data;
	}

	int Size()
	{
		if (this->head == NULL)
		{
			return 0;
		}
		DoubleLinkedList<T>::Node* temp = this->head;
		int size = 0;
		while (temp != NULL)
		{
			temp = temp->next;
			size++;
		}
		return size;
	}

	T Get(int index)
	{
		T data;
		DoubleLinkedList<T>::Node* node = GetNode(index);
		if (node != NULL)
		{
			return node->data; 
		}
		else
		{
			return data; 
		}
	}

	void Insert(int index, T data)
	{
		if (index > 0)
		{
			DoubleLinkedList<T>::Node *node = new DoubleLinkedList::Node(data);
			DoubleLinkedList<T>::Node *temp = GetNode(index);
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
		DoubleLinkedList<T>::Node *temp = GetNode(index);
		temp->previous->next = temp->next;
		temp->next->previous = temp->previous;
		delete temp;
	}
};
