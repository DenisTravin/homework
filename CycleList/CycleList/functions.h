#pragma once

struct listElement
{
	int number;
	listElement *next;
};

struct listHead
{
	listElement *head;
};

void printList(listHead *list, int num);
void delElement(listElement *element);
