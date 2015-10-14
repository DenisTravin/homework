#include <iostream>

using namespace std;

void printBinNum(int num)
{
	bool flag = false;
	for (int i = sizeof(num) * 8; i > 0; i--)
	{
		if ((1 << (i - 1)) & num)
		{
			printf("1");
			flag = true;
		}
		else if (flag)
		{
			printf("0");
		}
	}
}

void main()
{
	int n = 0;
	int m = 0;
	setlocale(LC_ALL, "Russian");
	printf("������� n: ");
	scanf("%i", &n);
	printf("\n������� m: ");
	scanf("%i", &m);
	printf("\n� �������� ������� ���������: ");
	printf("\nn = ");
	printBinNum(n);
	printf("\nm = ");
	printBinNum(m);
	printf("\nn + m = ");
	printBinNum(n + m);
	printf("\n� ���������� ������� ��������� n + m = %i", n + m);
	scanf("%*s");
}
/*
Test 1:
intput: n = 5, m = 5;
output: � ��������: n = 101, m = 101, n + m = 1010;
n + m = 10
*/