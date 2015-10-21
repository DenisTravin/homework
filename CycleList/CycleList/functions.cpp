#include <iostream>
#include "functions.h"

using namespace std;

void printList(listHead *list, int num)//print out all list
{
	if (list->head == nullptr)
	{
		cout << "List is empty!" << endl;
		return;
	}
	listElement *temp = list->head->next;
	for (int i = 0; i < num; i++)
	{
		cout << temp->number << " ";
		temp = temp->next;
	}
	cout << temp->number << " " << endl;
}

void delElement(listElement *element)
{
	listHead keapNextElement;
	keapNextElement.head = element->next->next;
	delete element->next;
	element->next = keapNextElement.head;
}
