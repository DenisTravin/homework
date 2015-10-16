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
	if (list->head == nullptr)
	{
		cout << "List is empty!" << endl;
		return;
	}
	listElement *temp = list->head;
	while (temp->next != nullptr)
	{
		cout << temp->value << " ";
		temp = temp->next;
	}
	cout << temp->value << " " << endl;
}

void delElement(listElement *element)
{
	listHead keapNextElement;
	keapNextElement.head = element->next->next;
	delete element->next;
	element->next = keapNextElement.head;
}

void delElementByNumber(listHead *list, int elementNum)//delete elements from list with value = elementNum
{
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
	listElement *tmp = list->head;
	while (tmp->next != nullptr)
	{
		if (tmp->next->value == elementNum)
		{
			delElement(tmp);
		}
		tmp = tmp->next;
	}
	return;
}

void removeAll(listHead *list)
{
	if (list->head == nullptr)
	{
		return;
	}
	listElement *tmp = list->head;
	listElement *nextTmp = tmp->next;
	while (tmp->next != nullptr)
	{
		nextTmp = tmp->next;
		delete tmp;
		tmp = nextTmp;
	}
	delete tmp;
	return;
}