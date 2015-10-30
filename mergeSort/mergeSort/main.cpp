#include <iostream>
#include <fstream>
#include <string> 
#include "list.h"

using namespace std;


int numOfElem = 0;


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
		//case 2:
		//	/*havePerson = false;
		//	cout << "Input name: ";
		//	cin >> findNum;
		//	for (int i = 0; i <= book.last; i++)
		//	{
		//		if (findNum == book.array[i].name)
		//		{
		//			cout << "His/her number is: " << book.array[i].number << endl;
		//			havePerson = true;
		//			break;
		//		}
		//	}
		//	if (!havePerson)
		//		cout << "We don't have this person in our phonebook" << endl;*/
		//	break;
		//case 3:
		//	/*havePerson = false;
		//	cout << "Input number: ";
		//	cin >> findNum;
		//	for (int i = 0; i <= book.last; i++)
		//	{
		//		if (findNum == book.array[i].number)
		//		{
		//			cout << "His/her name is: " << book.array[i].name << endl;
		//			havePerson = true;
		//			break;
		//		}
		//	}
		//	if (!havePerson)
		//		cout << "We don't have this person in our phonebook" << endl;*/
		//	break;
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

