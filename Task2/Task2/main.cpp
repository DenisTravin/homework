#include <fstream>
#include <iostream>
#include <vector>
#include <string> 
#include "function.h"

using namespace std;

const int arrayNumber = 10;//кол-во элементов в массиве

int findMostPopularNum(int array[], int n)//находит наиболее часто встречающийся элемент в массиве
{
	int count = 0;
	int maxCount = 0;
	int num = array[0];
	for (int i = 0; i < n - 1; i++)
	{
		if (array[i] == array[i + 1])
		{
			count++;
		}
		else
		{
			count = 0;
		}
		if (count > maxCount)
		{
			maxCount = count;
			num = array[i];
		}
	}
	return num;
}

void main()
{
	int array[arrayNumber] = {};
	FILE *input = fopen("input.txt", "r");
	for (int i = 0; i < arrayNumber; i++)
	{
		fscanf(input, "%i", &array[i]);
	}
	quickSort(array, 0, arrayNumber - 1, arrayNumber);
	printf("%i", findMostPopularNum(array, arrayNumber));
	scanf("%*s");
	fclose(input);
}

/*
Test 1:
input:1 2 3 4 5 6 6 8 8 8
output:8
Test 2:
input:1 2 2 2 3 4 4 4 4 4
output:4
*/