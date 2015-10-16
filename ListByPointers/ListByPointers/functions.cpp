#include <iostream>
#include "functions.h"

using namespace std;

void addNewElement(listHead *list, int elementNum)//add new element in list
{
	listElement *newElement = new listElement;

	bool sortFlag = false;
	if (list->head == nullptr)
	{
		list->head = newElement;
		newElement->next = nullptr;
	}
	else
	{
		listElement *tmp = list->head;
		if (tmp->value >= elementNum)
		{
			newElement->next = list->head;
			list->head = newElement;
			newElement->value = elementNum;
			return;
		}
		while (tmp->next != nullptr)
		{
			if (tmp->next->value >= elementNum)
			{
				newElement->next = tmp->next;
				tmp->next = newElement;
				sortFlag = true;
				break;
			}
			tmp = tmp->next;
		}
		if (!sortFlag)
		{
			tmp->next = newElement;
			newElement->next = nullptr;
		}
	}
	newElement->value = elementNum;
	return;
}
void printList(listHead *list)//print out all list
{
	listElement *temp;
	if (list->head == nullptr)
	{
		cout << "List is empty!" << endl;
		return;
	}
	temp = list->head;
	while (temp->next != nullptr)
	{
		cout << temp->value << " ";
		temp = temp->next;
	}
	cout << temp->value << " " << endl;
}
void delElement(listHead *list, int elementNum)//delete elements from list with value = elementNum
{
	listElement *tmp;
	listHead keapNextElement;
	while (list->head != nullptr && list->head->value == elementNum)
	{
		keapNextElement.head = list->head->next;
		delete list->head;
		list->head = keapNextElement.head;
	}
	if (list->head == nullptr)
	{
		return;
	}
	tmp = list->head;
	while (tmp->next != nullptr)
	{
		if (tmp->next->value == elementNum)
		{
			keapNextElement.head = tmp->next->next;
			delete tmp->next;
			tmp->next = keapNextElement.head;
		}
		tmp = tmp->next;
	}
	return;
}
