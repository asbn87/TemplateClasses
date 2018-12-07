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
		void setData(T data) { this->data = data; }
		T getData() { return this->data; }
		void setNext(DoubleLinkedList<T>::Node *next) { this->next = next; }
		void setPrevious(DoubleLinkedList<T>::Node *previous) { this->previous = previous; }
		DoubleLinkedList<T>::Node* getNext() { return next; }
		DoubleLinkedList<T>::Node* getPrevious() { return previous; }
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
			setHead(node);
			setTail(node);
		}
		else
		{
			this->head->setPrevious(node);
			node->setNext(head);
			this->head = node;
		}
	}
	void PushBack(T data)
	{
		DoubleLinkedList<T>::Node* node = new DoubleLinkedList<T>::Node(data);
		node->setPrevious(this->tail);
		this->tail->setNext(node);
		this->tail = node;
	}
	T PopFront()
	{
		DoubleLinkedList<T>::Node* node = this->head;
		T data = node->getData();
		if (node->next != NULL)
		{
			setHead(this->head->next);
			this->head->setPrevious(NULL);
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
		T data = node->getData();
		if (node->previous != NULL)
		{
			setTail(this->tail->previous);
			this->tail->setNext(NULL);
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
