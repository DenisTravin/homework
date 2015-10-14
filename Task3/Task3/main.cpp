#include <iostream>
#include <fstream>
#include <iostream>
#include <vector>
#include <string> 
using namespace std;
int main()
{
	int countOfEmpty = 0;
	ifstream file("test.txt", ios::in);
	if (!file.is_open())
	{
		cout << "File is not found" << endl;
		scanf("%*s");
		return 1;
	}
	vector<string> data;

	while (!file.eof())
	{
		string buffer;
		getline(file, buffer);
		data.push_back(buffer);
	}
	file.close();
	for (string const &line : data)
	{
		bool isEmpty = true;
		for (int i = 0; i < line.size(); i++)
			if (line[i] != ' ' && line[i] != '\n')
			{
				isEmpty = false;
			}
		if (isEmpty)
		{
			countOfEmpty++;
		}
	}
	printf("%i", countOfEmpty);
	scanf("%*s");
	return 0;
}
/*
Test 1:
input:
"
check

check

check


"
output:6
*/