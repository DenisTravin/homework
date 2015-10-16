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

void addNewElement(listHead *list, int elementNum);
void printList(listHead *list);
void delElement(listHead *list, int elementNum);
