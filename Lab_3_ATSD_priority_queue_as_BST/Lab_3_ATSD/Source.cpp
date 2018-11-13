#include"List.h"
#include"Item.h"
#include"PriorityQueueAsBinarySearchTree.h"
#include<iostream>
using namespace std;
int main()
{
	PriorityQueueAsBinarySearchTree myBT = PriorityQueueAsBinarySearchTree();
	int count;
	cout << "Input count of items you want to add to the tree: ";
	cin >> count;

	for(int i = 0; i < count; i++)
	{
		cout << "Input value of next item of BST: ";
		int data;
		cin >> data;

		cout << "Input priority of the item of BST: ";
		int priority;
		cin >> priority;

		myBT.addNode(Item(data, priority));
		myBT.preorder();
	}

	myBT.preorder();
	Item dequeued = myBT.dequeueMax();
	cout << "\nDequeued item value is " << dequeued.Value << " priority was " << dequeued.Priority << endl;
	myBT.preorder();

	dequeued = myBT.dequeueMax();
	cout << "\nDequeued item value is " << dequeued.Value << " priority was " << dequeued.Priority << endl;
	myBT.preorder();

	/*int n;
	cout << "\nInput count of items you want to add to the list: ";
	cin >> n;

	List a = List(n);
	for(int i = 0; i < n; i++)
	{
		int item;
		cout << "\nInput an item you want to add to the list: ";
		cin >> item;
		a.addItem(item);
		a.printList();
	}

	a.Sort();
	cout << "After sorting list: ";
	a.printList();

	a.deleteTop();
	a.printList();

	a.Find_k_max(3);

	cout << "\nInput count of items you want to delete from the list: ";
	cin >> n;

	for(int i = 0; i < n; i++)
	{
		int item;
		cout << "\nInput an item you want to delete from the list: ";
		cin >> item;
		a.deleteItem(item);
		a.printList();
	}*/
	
	system("pause");
	return 0;
}