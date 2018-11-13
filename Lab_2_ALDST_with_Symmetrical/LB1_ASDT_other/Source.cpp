#include<iostream>
#include"BalancedBinarySearchTree.h"
using namespace std;
int main()
{
	//BalancedBinarySearchTree myBT = BalancedBinarySearchTree();//balanced
	BinarySearchTree myBT = BinarySearchTree();//extra task
	int count;
	cout << "Input count of items you want to add to the tree: ";
	cin >> count;

	for(int i = 0; i < count; i++)
	{
		int item;
		cout << "Input value of the item you want to add to the tree: ";
		cin >> item;
		//myBT.root = myBT.insert(myBT.root, item);//balanced
		myBT.addNode(item);//extra task
		myBT.preorder();
	}

	cout << "\nOriginal binary tree is: \n";
	myBT.preorder();

	BinaryTree btSymmetrical = myBT.SymmetricalBBST();
	cout << "\nSymmetrical binary tree is: \n";
	btSymmetrical.preorder();

	system("pause");
	return 0;
}