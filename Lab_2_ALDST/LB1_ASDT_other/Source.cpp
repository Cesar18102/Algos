#include<iostream>
#include"BalancedBinarySearchTree.h"
using namespace std;
int main()
{
	BalancedBinarySearchTree myBT = BalancedBinarySearchTree();
	int count;
	cout << "Input count of items you want to add to the tree: ";
	cin >> count;

	for(int i = 0; i < count; i++)
	{
		int item;
		cout << "Input value of the item you want to add to the tree: ";
		cin >> item;
		myBT.root = myBT.insert(myBT.root, item);
		myBT.preorder();
	}
	myBT.preorder();

	BalancedBinarySearchTree myBT2 = BalancedBinarySearchTree();
	cout << "Input count of items you want to add to the tree: ";
	cin >> count;

	for (int i = 0; i < count; i++)
	{
		int item;
		cout << "Input value of the item you want to add to the tree: ";
		cin >> item;
		myBT2.root = myBT2.insert(myBT2.root, item);
		myBT2.preorder();
	}
	myBT2.preorder();
	
	myBT.insertBBST(&myBT2);
	myBT.preorder();

	BalancedBinarySearchTree BBSTRMDP = myBT.deleteDuplicate();
	BBSTRMDP.preorder();
	system("pause");
	return 0;
}
