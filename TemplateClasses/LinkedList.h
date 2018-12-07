#pragma once

template <class T>
class Node {
private:
	T data;
	Node<T>* next;
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
	void setNext(Node<T>* next) { this->next = next; };
	Node<T>* getNext() { return next; };
};

template <class T>
class LinkedList
{
private:
	Node<T>*head, *tail;
	void setHead(Node<T> *head) { this->head = head; };
	void setTail(Node<T> *tail) { this->tail = tail; };
public:
	~LinkedList() {};
	LinkedList() : head{ NULL }, tail{ NULL } {};
	Node<T>* Front() { return head; };
	Node<T>* Back() { return tail; };
	void PushFront(const T& data)
	{
		Node<T>* node = new Node<T>(data);

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
	Node<T>* PopFront()
	{
	};
	Node<T>* PopBack()
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
	Node<T>* GetNode()
	{
	};
};