#include <iostream>
#include <fstream>
#include "tree.h"

using namespace std;

void main()
{
	int userChoise = 0;
	treeHead tree;
	tree.head = nullptr;
	ifstream fin("in.txt"); // I use this tree, tree plan in folder
	if (!fin.is_open())
		cout << "File can't be open" << endl;
	else
	{
		int numOfElem;
		fin >> numOfElem;
		for (int i = 0; i < numOfElem; i++)
		{
			int tempNumber = 0;
			fin >> tempNumber;
			add(&tree.head, tempNumber);
		}
	}
	fin.close();
	printf("1 - add number, 2 - print increase, 3 - print decrease,\n 4 - find number, 5 - delete by number;\n\nYour choise is: ");
	scanf("%i", &userChoise);
	while (userChoise != 0)
	{

		if (userChoise == 1)
		{
			int num;
			printf("Input number: ");
			scanf("%i", &num);
			add(&tree.head, num);
		}
		if (userChoise == 2)
		{
			printTreeIncrease(tree.head);
		}
		if (userChoise == 3)
		{
			printTreeDecrease(tree.head);
		}
		if (userChoise == 4)
		{
			int num;
			printf("Input number: ");
			scanf("%i", &num);
			if (find(tree.head, num))
			{
				printf("Your number in tree!");
			}
			else
			{
				printf("Sorry, tree don't include your number");
			}
		}
		if (userChoise == 5)
		{
			int num;
			printf("Input number: ");
			scanf("%i", &num);
			del(tree.head, num);
		}
		printf("\n\nInput your choise: ");
		scanf("%i", &userChoise);
	}
}