#include <iostream>
#include "functions.h"

using namespace std;

void main()
{
	listHead list;
	list.head = nullptr;
	int userChoise = -1;
	int elementNum = 0;
	while (userChoise != 0)
	{
		std::cout << "0 - close program" << endl << "1 - add new number" << endl << "2 - delete number from list" << endl << "3 - print list" << endl;
		cin >> userChoise;
		switch (userChoise)
		{
		case 1:
			cout << "Input number: ";
			cin >> elementNum;
			addNewElement(&list, elementNum);
			break;
		case 2:
			cout << "Input number: ";
			cin >> elementNum;
			delElement(&list, elementNum);
			break;
		case 3:
			printList(&list);
			break;
		}
	}
}