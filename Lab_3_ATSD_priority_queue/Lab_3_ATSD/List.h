#pragma once
#include "Item.h";
class List
{
	private: Item* arr;
			 int last;
			 int max;

	public: List(int max);
			bool isEmpty();
			bool isFull();
			void printList();
			void HeapSort(Item *L, int n);
			void addItem(Item item);
			void deleteItem(Item item);
			Item dequeueMax();
			void CreateHeap(Item *L, int root, int last);
			void Sort();
			int size();
};

