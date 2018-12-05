#pragma once
#include <iostream>
#include <cstdlib>

using namespace std;


template <class T>
class LinkedList{
private:
	typedef struct Node {
		int data;
		struct Node *next;
	}* Nodeptr;
	typedef struct Node* Nodeptr;

	Nodeptr head;
	Nodeptr curr;
	Nodeptr temp;
	template <class T>
	LinkedList() {
		head = NULL;
		curr = NULL;
		temp = NULL;
	}
public: 
	LinkedList();
	template <class T>
	void AddNode(T AddData) {
		Nodeptr n = new Node;
		n->next = NULL;
		n->data = AddData;

		if (head != NULL) {
			curr = head;
			while (curr->next != NULL) {
				curr = curr->next;
			}
			curr->next = n;
		}
		else {
			head = n;
		}
	}
	template<class T>
	void DeleteNode(T DelData) {
		Nodeptr delPtr = NULL;
		temp = head;
		curr = head;
		while (curr != NULL && curr->data != DelData) {
			temp = curr;
			curr = curr->next;
		}
		if (curr == NULL) {
			cout << "DelData " << "was not in the list \n" << endl;
			delete delPtr;
		}
		else {
			delPtr = curr;
			curr = curr->next;
			temp->next = curr;
			delete delPtr;
			cout << "The value " << DelData << "was deleted \n" << endl;

		}
	}
	template <class T>
	void PrintList() {
		curr = head;
		while (curr != NULL) {
			cout << curr->data << endl;
			curr = curr->next;
		}
	}


	

};

