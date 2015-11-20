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

void splitList(listElement *source, listElement **front, listElement **back)//split the list to two list's
{
	listElement *current = source;
	int len = length(source);
	if (len < 2)
	{
		*front = current;
		*back = nullptr;
	}
	else
	{
		for (int i = 0; i < (len - 1) / 2; i++)
		{
			current = current->next;
		}
		*front = source;
		*back = current->next;
		current->next = nullptr;
	}
}

void printList(listHead *list, int num)
{
	cout << "Your phonebook: " << endl;
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

