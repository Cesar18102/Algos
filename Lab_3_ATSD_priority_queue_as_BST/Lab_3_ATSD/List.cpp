#include "List.h"
#include <iostream>
#include <queue>

List::List(int max)
{
	this->arr = new int[max + 1];
	this->max = max + 1;
	this->last = 1;
}

void List::addItem(int item)
{
	if(this->isFull())
	{
		max = (max - 1) * 2 + 1;
		int *temp = new int[max];
		for(int i = 0; i < last; i++)
			temp[i] = this->arr[i];
		this->arr = temp;
	}
	this->arr[last++] = item;
}

void List::deleteItem(int item)
{
	if(!isEmpty()){
		int i = 1;
		for( ; i < last && this->arr[i] != item; i++);

		if(i == last)
			std::cout << "The item is not in the list\n";
		else{
			this->arr[i] = this->arr[--last];
			arr[last] = NULL;
		}
	}
}

bool List::isEmpty()
{
	return (this->last == 1); 
}

bool List::isFull()
{
	return (this->last == this->max); 
}

int List::size()
{
	return this->last;
}

void List::printList()
{
	if(isEmpty()){
		std::cout << "List is empty\n";
		return;
	}
	std::cout << "List items are: ";
	for(int i = 1; i < last; i++)
		std::cout << this->arr[i] << " ";
	std::cout << std::endl;
}

void List::CreateHeap(int L[], int root, int last)
{
	int child, unsettled = root;
	while(2 * unsettled <= last){
		if(2 * unsettled < last && L[2 * unsettled + 1] > L[2 * unsettled])
			child = 2 * unsettled + 1;
		else
			child = 2 * unsettled;
		if(L[unsettled] < L[child]){
			int temp = L[unsettled];
			L[unsettled] = L[child];
			L[child] = temp;
			unsettled = child;
		}
		else 
			break;
	}
}

void List::Sort()
{
	this->HeapSort(this->arr, this->last);
}

void List::HeapSort(int L[], int n)
{
	int N = n - 1;
	for(int i = N / 2; i >= 1; i--)
		CreateHeap(L, i, N);
	for(int end = N - 1; end >= 1; end--){
		int temp = L[1];
		L[1] = L[end + 1];
		L[end + 1] = temp;
		CreateHeap(L, 1, end);
	}
}

int List::deleteTop()
{
	this->Sort();
	int res = this->arr[--last];
	this->arr[last] = NULL;
	this->Sort();
	return res;
}

void List::Find_k_max(int k)
{
	this->Sort();
	std::cout << k << " largest items in the list are: ";
	for(int i = last - 1; i >= last - k && i >= 0; i--)
		std::cout << this->arr[i] << " ";
	std::cout << std::endl;
}