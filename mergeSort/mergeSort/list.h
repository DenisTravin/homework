#pragma once
#include <string> 

using namespace std;

struct person
{
	string name;
	string number;
};
struct listElement
{
	person human;
	listElement *next;
};

struct listHead
{
	listElement *head;
};

void printList(listHead *list, int num);
void delElement(listElement *element);

