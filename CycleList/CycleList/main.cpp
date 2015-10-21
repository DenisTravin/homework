#include <iostream>
#include "functions.h"

using namespace std;

int n = 10;
const int m = 3;

void main()
{
	listHead list;
	listElement *newElement = new listElement;
	listElement *temp = newElement;
	list.head = newElement;
	newElement->next = nullptr;
	newElement->number = 0;
	for (int i = 1; i < n; i++)
	{
		listElement *newElement = new listElement;
		temp->next = newElement;
		temp = newElement;
		newElement->number = i;
	}
	temp->next = list.head;
	temp = list.head;
	temp->number = n;
	while (n > 1)
	{
		//printList(&list, n - 1); //if you want to check program work - uncomment
		for (int i = 0; i < m - 1; i++)
		{
			temp = temp->next;
		}
		if (list.head == temp->next)
		{
			list.head = temp->next->next;
		}
		delElement(temp);
		n--;
	}
	cout << "The last number is: " << temp->number << endl;
	delete temp;
	scanf("%*s");
}
/*
Test 1:
Input: n = 10; m = 3;
Output: k = 4;
Test 2:
Input: n = 5; m = 4;
Output: k = 1;
*/