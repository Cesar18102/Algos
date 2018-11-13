#include<iostream>
#include"SortedLinkedList.h"
using namespace std;
int main()
{
	/*SortedLinkedList mL = SortedLinkedList();
	mL.read();
	mL.printList();*/
	SortedLinkedList realList = SortedLinkedList::readBuildList();
	SortedLinkedList realList2 = SortedLinkedList::readBuildList();
	SortedLinkedList C = SortedLinkedList();
		C = realList.merge(&realList2);
		C.printList();

		SortedLinkedList D = SortedLinkedList();
		D = C.part(1, 4);
		D.printList();

	SortedLinkedList myList = SortedLinkedList();
	int lengthL1;
	cout << "Input count of elements you want to add to the list\n";
	cin >> lengthL1;
	for(int i = 0; i < lengthL1; i++){
		int item;
		cout << "Input an item to be added to the list\n";
		cin >> item;
		myList.addItem(item);
		myList.printList();
	}

	/*SortedLinkedList inter = mL.intersection(&myList);
	cout << "Intersection of the lists is: ";
	inter.printList();*/

	SortedLinkedList myList2 = SortedLinkedList();
	myList.copyList(&myList2);
	int lengthL2;
	cout << "Input count of elements you want to add to the second list\n";
	cin >> lengthL2;
	for(int i = 0; i < lengthL2; i++){
		int item;
		cout << "Input an item to be added to the second list\n";
		cin >> item;
		myList2.addItem(item);
		myList2.printList();
	}

	myList.appendOrdered(&myList2);
	cout << "Concat of the lists is: ";
	myList.printList();

	int deleted;
	cout << "Input an item to be deleted from the list\n";
	cin >> deleted;
	myList.deleteItem(deleted);
	myList.printList();

	int retrieved;
	cout << "Input an item to be retrieved in the list\n";
	cin >> retrieved;
	cout << myList.retrieve(retrieved) << endl;
	myList.printList();

	int searched;
	cout << "Input an item to search in the list\n";
	cin >> searched;
	myList.printList();

	cout << (myList.search(searched)? "The item is in the list" : "The item is not in the list") << endl;

	cout << (myList.isEmpty()? "List is empty" : "List is not empty") << endl;

	cout << (myList.isFull()? "List is full" : "List is not full") << endl;

	cout << "Length of the list is " << myList.listSize() << endl;
	system("pause");
}