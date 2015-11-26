#include <iostream>
#include <cstring>

using namespace std;

const int p = 31;

long long powNum(int a, int n)
{
	long long res = 1;
	for (int i = 0; i < n; i++)
	{
		res *= (long long)a;
	}
	return res;
}

long long hashFunc(string source, int first, int last)
{
	long long res = 0;
	for (int i = first; i < last; i++)
	{
		res += (long long)(source[i] - 'a' + 1) * powNum(p, last - i - 1);
	}
	return res;
}

int funcRabinCarp(string text, string sub)
{
	int res = 0;
	int subLen = sub.length();
	long long hsub = hashFunc(sub, 0, subLen);
	long long hs = hashFunc(text, 0, subLen);
	for (int i = 1; i <= (int)text.length() - subLen + 1; i++)
	{
		if (hsub == hs)
		{
			bool checkEq = true;
			for (int j = 0; j < subLen; j++)
			{
				if (sub[j] != text[i + j - 1])
				{
					checkEq = false;
					break;
				}
			}
			if (checkEq)
			{
				return i;
			}
		}
		//hs = hashFunc(text, i + 0, subLen + i);
		hs = (hs - (text[i - 1] - 'a' + 1) * powNum(p, subLen - 1)) * p + (text[i - 1 + subLen] - 'a' + 1);
	}
	return 0;
}

void main()
{
	string sub = "aba";
	string text = "abbabvaba";
	if (funcRabinCarp(text, sub) == 0)
	{
		printf("Sub don't found");
	}
	else
	{
		printf("Sub found!");
	}
	scanf("%*s");
}