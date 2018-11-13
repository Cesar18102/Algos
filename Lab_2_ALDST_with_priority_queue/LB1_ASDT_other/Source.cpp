#include<iostream>
#include"BalancedBinarySearchTree.h"
#include"Item.h"

using namespace std;
int main()
{
	BinarySearchTree myBT = BinarySearchTree();
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

	system("pause");
	return 0;
}