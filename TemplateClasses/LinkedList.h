#pragma once

template <class T>
class LinkedList
{
public:
	class Node {
	private:
		T data;
		LinkedList<T>::Node* next;
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
		void setNext(LinkedList<T>::Node* next) { this->next = next; };
		LinkedList<T>::Node* getNext() { return next; };
	};
private:
	LinkedList<T>::Node* head, *tail;
	void setHead(LinkedList<T>::Node* head) { this->head = head; };
	void setTail(LinkedList<T>::Node* tail) { this->tail = tail; };
public:
	~LinkedList() {};
	LinkedList() : head{ NULL }, tail{ NULL } {};
	LinkedList<T>::Node* Front() { return head; };
	LinkedList<T>::Node* Back() { return tail; };
	void PushFront(T data)
	{
		LinkedList<T>::Node* node = new LinkedList<T>::Node(data);

		if (head == NULL)
		{
			setHead(node);
			setTail(node);
		}
		else
		{
			node->setNext(head);
			setHead(node);
		}
	};
	void PushBack(T data)
	{
		LinkedList<T>::Node* node = new LinkedList<T>::Node(data);

		if (head == NULL)
		{
			setHead(node);
			setTail(node);
		}
		else
		{
			tail->setNext(node);
			setTail(node);
		}
	};
	T PopFront()
	{
		LinkedList<T>::Node* node = this->head;
		T data = node->getData();
		if (node->next != NULL)
		{
			setHead(this->head->next);
		}
		else
		{
			setHead(NULL);
			setTail(NULL);
		}
		delete node;
		return data;
	};
	T PopBack()
	{
		LinkedList<T>::Node* curr = this->head;
		LinkedList<T>::Node* prev = curr;
		LinkedList<T>::Node* node = this->tail;
		T data = node->getData();
		if (curr->next != NULL)
		{
			while (curr->next != NULL)
			{
				prev = curr;
				curr = curr->next;
			}
		}
		prev->next = NULL;
		setTail(prev);
		delete node;
		return data;
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
	LinkedList<T>::Node* GetNode(T data)
	{
	};
};