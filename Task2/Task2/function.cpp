#include <iostream>
#include "function.h"

using namespace std;

void insertSort(int array[], int n, int left, int right)//реализация сортировки выбором
{
	for (int i = left; i <= right; i++)
	{
		for (int j = i; j > 0; j--)
		{
			if (array[j] < array[j - 1])
			{
				swap(array[j], array[j - 1]);
			}
			else
			{
				break;
			}
		}
	}
}

int sortArrayForOneNumber(int array[], int middleNumber, int left, int right)/*выстраивание массива относительно  middleNumber элемента,
																			 меньшие числа - в левую часть, большие - в правую*/
{
	int position = 0;
	int i = left;
	swap(array[middleNumber], array[i]);
	for (i = left; i < right; i++)
	{
		if (array[i - position] > array[i - position + 1])
		{
			swap(array[i - position], array[i - position + 1]);
		}
		else
		{
			swap(array[i - position + 1], array[right - position - 1]);
			position++;
		}

	}
	return (i - position);
}

void quickSort(int array[], int left, int right, int n)//реализация быстрой сортировки
{
	int i = 0;
	int middleNum = left;
	int k = 0;
	if (right - left <= 10)
	{
		insertSort(array, n, left, right);
		return;
	}
	if (array[left] == array[right])
	{
		for (i = left; i <= right; i++)
		{
			if (array[i] != array[left])
			{
				middleNum = i;
				break;
			}
		}
		if (left == middleNum)
		{
			return;
		}
		if (left > middleNum)
		{
			middleNum = left;
		}
	}
	else if (array[left] > array[right])
	{
		middleNum = left;
	}
	else
	{
		middleNum = right;
	}
	k = sortArrayForOneNumber(array, middleNum, left, right);
	quickSort(array, left, k - 1, n);
	quickSort(array, k, right, n);
}

