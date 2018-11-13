#pragma once
class List
{
	private: int* arr;
			 int last;
			 int max;

	public: List(int max);
			bool isEmpty();
			bool isFull();
			void printList();
			void HeapSort(int L[], int n);
			void addItem(int item);
			void deleteItem(int item);
			int deleteTop();
			void Find_k_max(int k);
			void CreateHeap(int L[], int root, int last);
			void Sort();
			int size();
};

