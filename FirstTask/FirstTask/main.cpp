#include <iostream>
#include <fstream>

using namespace std;

struct listElement
{
	int element;
	listElement *next;
};

struct listHead
{
	int numOfElements;
	listElement *head;
};

const int a = 5;
const int b = 10;

void main()
{
	int numOfElem = 0;
	int currentElement = 0;

	listHead listBeforeA;
	listHead listBetweenAandB;
	listHead listAfterB;

	listElement *newElementLessA = new listElement;
	listBeforeA.head = newElementLessA;

	listElement *newElementMoreB = new listElement;
	listAfterB.head = newElementMoreB;

	listElement *newElementBetween = new listElement;
	listBetweenAandB.head = newElementBetween;

	listBeforeA.numOfElements = listBetweenAandB.numOfElements = listAfterB.numOfElements = 0;
	newElementLessA->element = newElementMoreB->element = newElementBetween->element = -1;
	newElementLessA->next = newElementMoreB->next = newElementBetween->next = nullptr;

	ifstream fin("f.txt");
	if (!fin.is_open())
		cout << "File can't be open" << endl;
	else
	{
		fin >> numOfElem;
		for (int i = 0; i < numOfElem; i++)
		{
			fin >> currentElement;
			listElement *newElement = new listElement;
			newElement->element = currentElement;
			if (currentElement < a)
			{
				newElementLessA->next = newElement;
				newElementLessA = newElement;
				listBeforeA.numOfElements++;
			}
			else if (currentElement > b)
			{
				newElementMoreB->next = newElement;
				newElementMoreB = newElement;
				listAfterB.numOfElements++;
			}
			else
			{
				newElementBetween->next = newElement;
				newElementBetween = newElement;
				listBetweenAandB.numOfElements++;
			}
			newElement->next = nullptr;
		}
	}
	fin.close();
	ofstream fout;
	fout.open("g.txt");
	fout << numOfElem << endl;
	for (int i = 0; i <= listBeforeA.numOfElements; i++)
	{
		if (i != 0)
		{
			fout << listBeforeA.head->element << " ";
		}
		listElement *temp = listBeforeA.head->next;
		delete listBeforeA.head;
		listBeforeA.head = temp;
	}
	for (int i = 0; i <= listBetweenAandB.numOfElements; i++)
	{
		if (i != 0)
		{
			fout << listBetweenAandB.head->element << " ";
		}
		listElement *temp = listBetweenAandB.head->next;
		delete listBetweenAandB.head;
		listBetweenAandB.head = temp;
	}
	for (int i = 0; i <= listAfterB.numOfElements; i++)
	{
		if (i != 0)
		{
			fout << listAfterB.head->element << " ";
		}
		listElement *temp = listAfterB.head->next;
		delete listAfterB.head;
		listAfterB.head = temp;
	}
	fout.close();
}
