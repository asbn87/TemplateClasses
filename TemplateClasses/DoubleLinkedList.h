#pragma once

template <class T>
class DoubleLinkedList
{
public:
	class Node {
	private:
		T data;
		DoubleLinkedList<T>::Node* next;
	public:
		Node() {};
		Node(T data)
		{
			this->data = data;
			this->next = NULL;
		};
		~Node() {};
		void setData(T data) { this->data = data; };
		T getData() { return data; };
		void setNext(DoubleLinkedList<T>::Node* next) { this->next = next; };
		DoubleLinkedList<T>::Node* getNext() { return next; };
	};
private:
	DoubleLinkedList<T>::Node* head, *tail;
	void setHead(DoubleLinkedList<T>::Node* head) { this->head = head; };
	void setTail(DoubleLinkedList<T>::Node* tail) { this->tail = tail; };
public:
	DoubleLinkedList() : head{ NULL }, tail{ NULL } {};
	~DoubleLinkedListhead() {};
	DoubleLinkedList<T>::Node* Front() { return head; };
	DoubleLinkedList<T>::Node* Back() { return tail; };
	void PushFront(const T& data)
	{
		DoubleLinkedList<T>::Node* node = new DoubleLinkedList<T>::Node(data);

		if (head == NULL)
		{
			setHead(node);
			setTail(node);
		}
		else
		{
			node->setNext(head);
			head = node;
		}
	};
	void PushBack(const T& data)
	{
	};
	DoubleLinkedList<T>::Node* PopFront()
	{
	};
	DoubleLinkedList<T>::Node* PopBack()
	{
	};
	int Length()
	{
	};
	void Insert()
	{
	};
	void Delete()
	{
	};
	DoubleLinkedList<T>::Node* GetNode(T data)
	{
	};
};
