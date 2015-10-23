#include <iostream>
#include <string>
#include "stack.h"

using namespace std;

bool isGood = true;

void bracketControl(int inputChar, Stack *stack)
{
	int outChar = NULL;
	switch (inputChar)
	{
	case ')':
	{
		outChar = '(';
		break;
	}
	case ']':
	{
		outChar = '[';
		break;
	}
	case '}':
	{
		outChar = '{';
		break;
	}
	}
	if (stackEmpty(stack) || stackHead(stack) != outChar)
	{
		isGood = false;
		return;
	}
	stackPop(stack);
	return;
}

void main()
{
	string str = "[({()})]";
	Stack stack;
	stack.head = nullptr;

	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '(' || str[i] == '{' || str[i] == '[')
		{
			stackPush(&stack, str[i]);
			continue;
		}
		bracketControl(str[i], &stack);
		if (!isGood)
		{
			break;
		}
	}
	if (isGood)
	{
		printf("Balance is nice");
	}
	else
	{
		printf("Balance is bad");
	}
	stackDelete(&stack);
	scanf("%*s");
}
/*
Test 1:
Input: [({)(})]
Output:Balance is bad
Test 2:
Input: [({()})]
Output:Balance is nice
*/