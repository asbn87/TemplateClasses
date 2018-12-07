#pragma once

template <class T>
class LinkedList
{
private:
	class Node {
	public:
		T data;
		LinkedList<T>::Node* next;
		Node() {};
		Node(T data)
		{
			this->data = data;
			this->next = NULL;
		};
		~Node() {};
	};
	LinkedList<T>::Node* head, *tail;
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
			this->head = node;
			this->tail = node;
		}
		else
		{
			node->next = head;
			this->head = node;
		}
	};
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
	};
	T PopFront()
	{
		LinkedList<T>::Node* node = this->head;
		T data = node->data;
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
	};
	T PopBack()
	{
		LinkedList<T>::Node* curr = this->head;
		LinkedList<T>::Node* prev = curr;
		LinkedList<T>::Node* node = this->tail;
		T data = node->data;
		if (curr->next != NULL)
		{
			while (curr->next != NULL)
			{
				prev = curr;
				curr = curr->next;
			}
		}
		prev->next = NULL;
		this->tail = prev;
		delete node;
		return data;
	};
	int Size()
	{
		LinkedList<T>::Node* curr;
		int size{ 0 };
		if (this->head != NULL)
		{
			curr = this->head;
			size++;
			if (curr->next != NULL)
			{
				curr = curr->next;
				size++;
			}
		}
		return size;
	};
	void Insert(int index, T data)
	{
		if (index > 0)
		{
			LinkedList<T>::Node* node = new LinkedList<T>::Node(data);
			LinkedList<T>::Node* prev = GetNode(index - 1);
			node->next = prev->next;
			prev->next = node;
		}
		else
		{
			pushFront(data);
		}
	};
	void Delete(int index)
	{
		if (index > 0)
		{
			LinkedList<T>::Node* node = GetNode(index);
			LinkedList<T>::Node* prev = GetNode(index - 1);
			node->next = prev->next;
			delete node;
		}
		else
		{
			popFront(data);
		}
	};
	LinkedList<T>::Node* GetNode(int index)
	{
		LinkedList<T>::Node* curr = this->head;
		int count{ 0 };
		while (count != index)
		{
			if (curr->next != NULL)
			{
				curr = curr->next;
				count++;
			}
			else
			{
				return NULL;
			}
		}
		return curr;
	};
};