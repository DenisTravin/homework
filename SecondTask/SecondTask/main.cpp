#include <iostream>
#include <fstream>

using namespace std;

struct listElement
{
	int element;
	listElement *next;
	listElement *before;
};

struct listHead
{
	listElement *head;
	listElement *tail;
};

void main()
{
	int numOfElem = 0;
	int currentElement = 0;
	bool isSym = true;

	listHead list;

	listElement *newElement = new listElement;
	list.head = newElement;
	list.tail = nullptr;

	newElement->element = -1;
	newElement->next = nullptr;
	newElement->before = nullptr;

	ifstream fin("in.txt");
	if (!fin.is_open())
		cout << "File can't be open" << endl;
	else
	{
		fin >> numOfElem;
		for (int i = 0; i < numOfElem; i++)
		{
			fin >> currentElement;
			listElement *newElementTemp = new listElement;
			newElementTemp->element = currentElement;
			newElementTemp->next = nullptr;
			newElementTemp->before = newElement;
			newElement->next = newElementTemp;
			newElement = newElementTemp;
		}
		list.tail = newElement;
	}
	fin.close();
	listElement *leftElement = list.head->next;
	listElement *rightElement = list.tail;
	for (int i = 0; i < numOfElem / 2 + 1; i++)
	{
		if (rightElement->element != leftElement->element)
		{
			isSym = false;
			break;
		}
		leftElement = leftElement->next;
		rightElement = rightElement->before;
	}
	if (!isSym)
	{
		cout << "List is not symmetric" << endl;
	}
	else
	{
		cout << "List is symmetric" << endl;
	}
	for (int i = 0; i <= numOfElem; i++)
	{
		listElement *temp = list.head->next;
		delete list.head;
		list.head = temp;
	}
	scanf("%*s");
}
