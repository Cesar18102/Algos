#include "SortedLinkedList.h"
#include <iostream>

SortedLinkedList::SortedLinkedList(void)
{
	count = 0;
	firstNode = NULL;
}

int SortedLinkedList::listSize()
{
	return count;
}

void SortedLinkedList::makeEmpty()
{
	Node *temp;
	while(firstNode != NULL)
	{ 
		temp = firstNode;
		firstNode = firstNode ->next;
		delete temp;
	}	
}

bool SortedLinkedList::isEmpty()
{
	return (firstNode == NULL);
}

bool SortedLinkedList::isFull()
{
	bool result = false;
	Node *temp = new Node();
	if(temp == NULL)
		result = temp == NULL;
	delete temp;
	return result;
}

bool SortedLinkedList::search(int item)
{
	for(Node* i = firstNode; i != NULL && i->data <= item; i = i->next)
		if(i->data == item)
			return true;
	return false;
}

int SortedLinkedList::retrieve(int item)
{
	for(Node* i = firstNode; i != NULL && i->data <= item; i = i->next)
		if(i->data == item)
			return i->data;
	std::cout << "Item wasn't found\n";
	return -999999;
}

int SortedLinkedList::deleteItem(int item)
{
	count--;
	if(firstNode == NULL)
	{
		std::cout << "List is empty. Not able to delete the item\n";
		return -999999;
	}
	else if(firstNode->data == item)
	{
		Node* t = firstNode->next;
		int data = firstNode->data;
		delete firstNode;
		firstNode = t;
		return data;
	}
	Node* i = firstNode;
	for( ; i != NULL && i->data < item; i = i->next);
	if(i == NULL){
		std::cout << "Item wasn't found and wasn't deleted\n";
		return -999999;
	}
	int data = i->data;
	Node* t = i->next;
	delete i->next;
	i->next = t;
	return data;
}

void SortedLinkedList::addItem(int item)
{
	if(isFull())
	{
		std::cout << "List is overflow. Not able to add the item\n";
		return;
	}
	count++;
	if(firstNode == NULL){
		firstNode = new Node(item);
		return;
	}
	if(item < (*firstNode).data){
		firstNode = new Node(item, firstNode);
		return;
	}
	Node* i = firstNode;
	for( ; i->next != NULL && i->next->data < item; i = i->next);
	Node* t = i->next;
	i->next = new Node(item, t);
}

void SortedLinkedList::appendOrdered(SortedLinkedList *L2)
{
	this->concat(L2);
	this->firstNode = this->sort();
}

void SortedLinkedList::copyList(SortedLinkedList *L)
  {
    if (count == 0)
      std::cout << "list is empty.\n";
	L->firstNode = new Node();
	Node *q = L->firstNode;
	Node *p = firstNode;
    for( ; p != NULL; p = p->next){
		q->data = p->data;
		q->next = new Node();
        q = q->next;
    }
  }

Node* SortedLinkedList::sort()
{
	if(firstNode == NULL || firstNode->next == NULL)
		return firstNode;

	SortedLinkedList more = SortedLinkedList();
	SortedLinkedList less = SortedLinkedList();
	Node *mid = new Node(firstNode->data);

	for(Node* j = firstNode; j->next != NULL; j = j->next)
		if(j->next->data > firstNode->data)
			more.concat(new Node(j->next->data));
		else
			less.concat(new Node(j->next->data));

	less.sort();
	less.concat(mid);
	more.sort();
	less.concat(&more);
	return less.firstNode;
}

void SortedLinkedList::concat(SortedLinkedList *L2)
{
	if(L2->isEmpty())
		return;

	if(this->isEmpty())
	{
		firstNode = new Node(L2->firstNode->data);
		Node* lastNode = firstNode;

		for(Node* i = L2->firstNode->next; i != NULL; i = i->next){
			lastNode->next = new Node(i->data);
			lastNode = lastNode->next;
		}
		count = L2->count;
		return;
	}

	Node* lastNode = firstNode;
	for( ; lastNode->next != NULL; lastNode = lastNode->next);

	for(Node* i = L2->firstNode; i != NULL; i = i->next){
		lastNode->next = new Node(i->data);
		lastNode = lastNode->next;
	}
	count += L2->count;
}

void SortedLinkedList::concat(Node *p)
{
	if(p == NULL)
		return;

	if(firstNode == NULL)
	{
		firstNode = new Node(p->data);
		return;
	}

	Node* lastNode = firstNode;
	for( ; lastNode->next != NULL; lastNode = lastNode->next);
	lastNode->next = new Node(p->data);
	count++;
}

void SortedLinkedList::printList()
{
	for(Node* i = firstNode; i != NULL; i = i->next)
		std::cout << i->data << ' ';
	std::cout << "\n";
}

SortedLinkedList SortedLinkedList::readBuildList()
{
	SortedLinkedList result = SortedLinkedList();
	std::cout << "Input items you want to add to the list(break value is -999): ";
	int input;
	std::cin >> input;
	while(input != -999)
	{
		result.addItem(input);
		std::cin >> input;
	}
	return result;
}

void SortedLinkedList::read()
{
	std::cout << "Input items you want to add to the list(break value is -999): ";
	int input;
	std::cin >> input;
	while(input != -999)
	{
		this->addItem(input);
		std::cin >> input;
	}
}

bool SortedLinkedList::contains(int item)
{
	for(Node* i = firstNode; i != NULL; i = i->next)
		if(i->data == item)
			return true;
	return false;
}

SortedLinkedList SortedLinkedList::intersection(SortedLinkedList *L2)
{
	if(L2->firstNode == NULL)
		return *this;

	if(this->firstNode == NULL)
		return *L2;

	SortedLinkedList result = SortedLinkedList();

	Node *i = firstNode;
	for( ; i != NULL; i = i->next)
		if(!L2->contains(i->data))
		{
			result.firstNode = new Node(i->data);
			break;
		}

	if(i == NULL)
		return result;

	Node *cNode = result.firstNode;

	for(i = i->next; i != NULL; i = i->next)
		if(!L2->contains(i->data)){
			cNode->next = new Node(i->data);
			cNode = cNode->next;		
		}

	return result;
}

SortedLinkedList SortedLinkedList::merge(SortedLinkedList *list)
{
		SortedLinkedList resList;


		Node *firstl = firstNode;
		Node *second = list->firstNode;

		for (int i = 0; firstl != nullptr || second != nullptr; i++)
		{
				if (firstl == nullptr)
				{
						resList.addItem(second->data);
						second = second->next;
				}
				else if (second == nullptr)
				{
						resList.addItem(firstl->data);
						firstl = firstl->next;
				}
				else if (firstl->data < second->data)
				{
						resList.addItem(firstl->data);
						firstl = firstl->next;
				}
				else
				{
						resList.addItem(second->data);
						second = second->next;
				}
		}
		return resList;
}

SortedLinkedList SortedLinkedList::part(int k, int j)
{
		SortedLinkedList L2;
		Node *i = firstNode;
		int l = 0;
		for (; i != NULL && l < k; l++)
				i = i->next;
		for (; i != NULL && k <= j; k++)
		{
				L2.addItem(i->data);
				i = i->next;
		}
		return L2;
}

Node::Node()
{
	next = NULL;
}

Node::Node(int item)
{
	data = item;
	next = NULL;
}

Node::Node(int item, Node* n)
{
	data = item;
	next = n;
}
