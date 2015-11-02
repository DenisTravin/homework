#include <iostream>
#include <fstream>
#include <string> 
#include "list.h"

using namespace std;

int numOfElem = 0;

void splitList(listElement *source, listElement **front, listElement **back)
{
	listElement *current = source;
	if (numOfElem < 2)
	{
		*front = current;
		*back = nullptr;
	}
	else
	{
		for (int i = 0; i < (numOfElem - 1) / 2; i++)
		{
			current = current->next;
		}
		*front = source;
		*back = current;
		current->next = nullptr;
	}
}

void mergeSort(listElement **head, int sortChoise)
{
	listElement *a, *b;
	if (*head == nullptr || &(*head)->next == nullptr)
	{
		return;
	}
	splitList(*head, &a, &b);
	mergeSort(&a, sortChoise);
	mergeSort(&b, sortChoise);

}

void main()
{
	listHead list;
	int userChoise = -1;//yes, I try to ignor bin files
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
		}
	}
	fin.close();
	printList(&list, numOfElem);
	while (userChoise != 0)
	{
		cout << "0 - close program" << endl << "1 - add new person" << endl << "2 - find phone by person" << endl << "3 - find person by phone" << endl << "4 - save list" << endl;
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
			break;
		}
		}
	}
}
//i have problems with git!
