#include "List.h"
#include "Item.h"
#include <iostream>
#include <queue>

List::List(int max)
{
	this->arr = new Item[max + 1];
	this->max = max + 1;
	this->last = 1;
}

void List::addItem(Item item)
{
	if(this->isFull())
	{
		max = (max - 1) * 2 + 1;
		Item *temp = new Item[max];
		for(int i = 0; i < last; i++)
			temp[i] = Item(arr[i].Value, arr[i].Priority);
		this->arr = temp;
	}
	this->arr[last++] = item;
}

void List::deleteItem(Item item)
{
	if(!isEmpty()){
		int i = 1;
		for( ; i < last && (arr[i].Value != item.Value || arr[i].Priority != item.Priority); i++);

		if(i == last)
			std::cout << "The item is not in the list\n";
		else{
			this->arr[i] = this->arr[--last];
			arr[last] = Item();
		}
		Sort();
	}
}

Item List::dequeueMax()
{
	if(isEmpty())
		return Item();

	int maxPriorityIndex = 1;
	for(int i = 1; i < last; i++)
		if(arr[i].Priority > arr[maxPriorityIndex].Priority)
			maxPriorityIndex = i;
	
	Item temp = Item(arr[maxPriorityIndex].Value, arr[maxPriorityIndex].Priority);
	deleteItem(arr[maxPriorityIndex]);
	return temp;
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
	std::cout << "List items are: \n";
	for(int i = 1; i < last; i++)
		std::cout << "Value: " << this->arr[i].Value << "; Priopity: " << this->arr[i].Priority << std::endl;
	std::cout << std::endl;
}

void List::CreateHeap(Item *L, int root, int last)
{
	int child, unsettled = root;
	while(2 * unsettled <= last){
		if(2 * unsettled < last && L[2 * unsettled + 1].Priority > L[2 * unsettled].Priority)
			child = 2 * unsettled + 1;
		else
			child = 2 * unsettled;
		if(L[unsettled].Priority < L[child].Priority){
			Item temp = Item(L[unsettled]);
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
	this->HeapSort(arr, this->last);
}

void List::HeapSort(Item *L, int n)
{
	int N = n - 1;
	for(int i = N / 2; i >= 1; i--)
		CreateHeap(L, i, N);
	for(int end = N - 1; end >= 1; end--){
		Item temp = Item(L[1]);
		L[1] = L[end + 1];
		L[end + 1] = temp;
		CreateHeap(L, 1, end);
	}
}