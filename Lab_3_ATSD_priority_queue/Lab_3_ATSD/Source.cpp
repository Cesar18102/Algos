#include"List.h"
#include<iostream>
using namespace std;
int main()
{
	int n;
	cout << "\nInput count of items you want to add to the list: ";
	cin >> n;

	List a = List(n);
	for(int i = 0; i < n; i++)
	{
		int item, priority;
		cout << "\nInput value of the item you want to add to the list: ";
		cin >> item;
		cout << "\nInput priority of the item you want to add to the list: ";
		cin >> priority;
		a.addItem(Item(item, priority));
		a.printList();
	}

	a.Sort();
	cout << "After sorting list: ";
	a.printList();

	Item deq = a.dequeueMax();
	cout << "Dequeued max item value is " << deq.Value << "; priority was " << deq.Priority << endl;
	a.printList();

	deq = a.dequeueMax();
	cout << "Dequeued max item value is " << deq.Value << "; priority was " << deq.Priority << endl;
	a.printList();

	cout << "\nInput count of items you want to delete from the list: ";
	cin >> n;
	system("pause");
	return 0;
}