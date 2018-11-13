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
	}
	
	system("pause");
	return 0;
}