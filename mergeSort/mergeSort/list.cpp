#include <iostream>
#include "list.h"

using namespace std;

int length(listElement* head)
{
	int count = 0;
	listElement* current = head;
	while (current != nullptr)
	{
		count++;
		current = current->next;
	}
	return(count);
}
void printList(listHead *list, int num)
{
	if (list->head == nullptr)
	{
		cout << "List is empty!" << endl;
		return;
	}
	cout << list->head->human.name << " " << list->head->human.number << endl;
	listElement *temp = list->head->next;
	for (int i = 0; i < num - 1; i++)
	{
		cout << temp->human.name << " " << temp->human.number << endl;
		temp = temp->next;
	}
	cout << temp->human.name << " " << temp->human.number << endl;
}

void delElement(listElement *element)
{
	listHead keapNextElement;
	keapNextElement.head = element->next->next;
	delete element->next;
	element->next = keapNextElement.head;
}
