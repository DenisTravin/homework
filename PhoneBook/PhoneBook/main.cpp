#include <iostream>
#include <fstream>
#include <string> 

using namespace std;

const int maxN = 100;

struct person
{
	string name;
	string number;
};
struct list
{
	int last;
	person array[maxN];
};

void main()
{
	list book;
	int userChoise = -1;
	book.last = -1;
	string findNum;
	bool havePerson = false;
	ifstream fin("out.txt");
	if (!fin.is_open())
		cout << "File can't be open" << endl;
	else
	{
		fin >> book.last;
		for (int i = 0; i <= book.last; i++)
		{
			fin >> book.array[i].name;
			fin >> book.array[i].number;
		}
	}
	fin.close();
	while (userChoise != 0)
	{
		std::cout << "0 - close program" << endl << "1 - add new person" << endl << "2 - find phone by person" << endl << "3 - find person by phone" << endl << "4 - save list" << endl;
		cin >> userChoise;
		switch (userChoise)
		{
		case 1:
			book.last++;
			cout << "Input name:";
			cin >> book.array[book.last].name;
			cout << "Input phone number:";
			cin >> book.array[book.last].number;
			break;
		case 2:
			havePerson = false;
			cout << "Input name: ";
			cin >> findNum;
			for (int i = 0; i <= book.last; i++)
			{
				if (findNum == book.array[i].name)
				{
					cout << "His/her number is: " << book.array[i].number << endl;
					havePerson = true;
					break;
				}
			}
			if (!havePerson)
				cout << "We don't have this person in our phonebook" << endl;
			break;
		case 3:
			havePerson = false;
			cout << "Input number: ";
			cin >> findNum;
			for (int i = 0; i <= book.last; i++)
			{
				if (findNum == book.array[i].number)
				{
					cout << "His/her name is: " << book.array[i].name << endl;
					havePerson = true;
					break;
				}
			}
			if (!havePerson)
				cout << "We don't have this person in our phonebook" << endl;
			break;
		case 4:
			ofstream fout;
			fout.open("out.txt");
			fout << book.last << endl;
			for (int i = 0; i <= book.last; i++)
			{
				fout << book.array[i].name << " " << book.array[i].number << endl;
			}
			cout << "List was saved" << endl;
			fout.close();
			break;
		}
	}
}
