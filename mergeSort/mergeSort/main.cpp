#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "list.h"

using namespace std;

int numOfElem = 0;

int stringComp(string a, string b)//string compare
{
	int minSize = min(a.size(), b.size());
	for (int i = 0; i < minSize; i++)
	{
		if (a[i] != b[i])
			return (int)(b[i] - a[i]);
	}
}

listElement* mergeFunc(listElement *a, listElement *b, int userChoise)//return smallest element of part of the list, reccursion with next element
{
	listElement *result = nullptr;
	int cmpResult = 0;
	if (a == nullptr)
	{
		return(b);
	}
	else if (b == nullptr)
	{
		return(a);
	}
	if (userChoise == 2)
	{
		cmpResult = stringComp(a->human.name, b->human.name);
	}
	else
	{
		cmpResult = stringComp(a->human.number, b->human.number);
	}
	if (cmpResult >= 0)
	{
		result = a;
		result->next = mergeFunc(a->next, b, userChoise);
	}
	else
	{
		result = b;
		result->next = mergeFunc(a, b->next, userChoise);
	}
	return result;
}

void mergeSort(listElement **headSource, int userChoise)//split the list and sort both parts
{
	listElement *head = *headSource;
	listElement *firstList;
	listElement *secondList;
	if (head == nullptr || head->next == nullptr)
	{
		return;
	}
	splitList(head, &firstList, &secondList);
	mergeSort(&firstList, userChoise);
	mergeSort(&secondList, userChoise);
	*headSource = mergeFunc(firstList, secondList, userChoise);
}

void main()
{
	listHead list;
	int userChoise = -1;
	string findNum;
	bool havePerson = false;
	ifstream fin("out.txt");
	if (!fin.is_open())
		cout << "File can't be open" << endl;
	else
	{
		fin >> numOfElem;
		listElement *newElement = new listElement;
		listElement *temp = newElement;
		list.head = newElement;
		newElement->next = nullptr;
		fin >> newElement->human.name;
		fin >> newElement->human.number;
		for (int i = 1; i <= numOfElem; i++)
		{
			listElement *newElement = new listElement;
			temp->next = newElement;
			temp = newElement;
			fin >> newElement->human.name;
			fin >> newElement->human.number;
			if (i == numOfElem)
			{
				newElement->next = nullptr;
			}
		}
	}
	fin.close();
	printList(&list, numOfElem);
	while (userChoise != 0)
	{
		cout << "0 - close program" << endl << "1 - add new person" << endl << "2 - sort by name" << endl
			 << "3 - sort by numbers"  << endl << "4 - save list and close program" << endl;
		cin >> userChoise;
		switch (userChoise)
		{
			case 1:
			{
				numOfElem++;
				listElement *newElement = new listElement;
				listElement *temp = list.head;
				list.head = newElement;
				newElement->next = temp;
				cout << "Input name:";
				cin >> newElement->human.name;
				cout << "Input phone number:";
				cin >> newElement->human.number;
				printList(&list, numOfElem);
				break;
			}
			case 2:
			{
				mergeSort(&list.head, userChoise);
				printList(&list, numOfElem);
				break;
			}
			case 3:
			{
				mergeSort(&list.head, userChoise);
				printList(&list, numOfElem);
				break;
			}
			case 4:
			{
				ofstream fout;
				fout.open("out.txt");
				fout << numOfElem << endl;
				for (int i = 0; i <= numOfElem; i++)
				{
					fout << list.head->human.name << " " << list.head->human.number << endl;
					listElement *temp = list.head->next;
					delete list.head;
					list.head = temp;
				}
				cout << "List was saved" << endl;
				fout.close();
				userChoise = 0;
				break;
			}
		}
	}
}
