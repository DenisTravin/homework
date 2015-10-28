#include <iostream>
#include <string>
#include "stack.h"

using namespace std;

void main()
{
	string str = "5 4 - 1 + 2 /";
	Stack stack;
	stack.head = nullptr;

	for (int i = 0; i < str.size(); i += 2)
	{
		if (str[i] <= '9' && str[i] >= '0')
		{
			stackPush(&stack, str[i] - '0');
		}
		if (str[i] == '+')
		{
			int headValue = stack.head->value;
			stackPop(&stack);
			stack.head->value = stack.head->value + headValue;
		}
		if (str[i] == '*')
		{
			int headValue = stack.head->value;
			stackPop(&stack);
			stack.head->value = stack.head->value * headValue;

		}
		if (str[i] == '-')
		{
			int headValue = stack.head->value;
			stackPop(&stack);
			stack.head->value = stack.head->value - headValue;
		}
		if (str[i] == '/')
		{
			int headValue = stack.head->value;
			stackPop(&stack);
			stack.head->value = stack.head->value / headValue;
		}
	}
	printf("%i", stack.head->value);
	scanf("%*s");
}
/*
Test 1:
Input: 9 6 - 1 2 + *
Output: 9
Test 2:
Input: 5 4 - 1 + 2 /
Output: 1
*/