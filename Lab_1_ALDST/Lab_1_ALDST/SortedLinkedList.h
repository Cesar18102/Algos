#pragma once
struct Node
{
	int data;
	Node* next;
	public:
		Node(void);
		Node(int item);
		Node(int item, Node* n);
};

class SortedLinkedList
{
	public:
		SortedLinkedList(void);
		bool isFull();
		bool isEmpty();
		void makeEmpty();
		int listSize();
		void printList();
		bool search(int item);
		int retrieve(int item);
		int deleteItem(int item);
		void addItem(int item);
		void appendOrdered(SortedLinkedList *L2);
		void concat(SortedLinkedList *L2);
		void concat(Node *p);
		void read();
		void copyList(SortedLinkedList *p);
		static SortedLinkedList readBuildList();
		bool contains(int item);
		SortedLinkedList intersection(SortedLinkedList *L2);
		SortedLinkedList merge(SortedLinkedList *list);
		SortedLinkedList part(int k, int j);
		Node* SortedLinkedList::sort();
	private:
		Node* firstNode;
		int count;
};

