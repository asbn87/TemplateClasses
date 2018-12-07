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
	void setHead(DoubleLinkedList<T>::Node* head) { this->head = head; }
	void setTail(DoubleLinkedList<T>::Node* tail) { this->tail = tail; }
	DoubleLinkedList<T>::Node *GetNode(int index)
	{
		DoubleLinkedList<T>::Node *temp = this->head;
		int count = 0;
		while (count != index)
		{
			if (temp == NULL)
			{
				return NULL;
			}
			temp = temp->next;
			count++;
		}
		return temp;
	}

public:
	DoubleLinkedList() : head{ NULL }, tail{ NULL } {}
	~DoubleLinkedList() {}
	T Front() { return this->head->data; }
	T Back() { return this->tail->data; }
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
		node->previous = this->tail;
		this->tail->next = node;
		this->tail = node;
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
		DoubleLinkedList<T>::Node *temp = GetNode(index);
		return temp->data;
	}
	void Insert(int index, T data)
	{
		if (index == 0)
		{
			PushFront(data);
			return;
		}
		DoubleLinkedList<T>::Node *node = new DoubleLinkedList::Node();
		DoubleLinkedList<T>::Node *temp = GetNode(index);
		node->data = data;
		node->next = temp;
		node->previous = temp->previous;
		temp->previous = node;
	}
	void Delete(int index)
	{
		DoubleLinkedList<T>::Node *temp = GetNode(index);
		temp->previous->next = temp->next;
		temp->next->previous = temp->previous;
		delete temp;
	}
};
