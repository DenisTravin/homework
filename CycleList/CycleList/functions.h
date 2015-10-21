#pragma once
struct listElement
{
	int value;
	listElement *next;
};

struct listHead
{
	listElement *head;
};

void delElement(listElement *element);
void addNewElement(listHead *list, int elementNum);
void printList(listHead *list);
void delElementByNumber(listHead *list, int elementNum);
void removeAll(listHead *element);
