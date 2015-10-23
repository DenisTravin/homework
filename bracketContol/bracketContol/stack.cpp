#include <iostream>
#include "stack.h"

using namespace std;

void stackPush(Stack *stack, int number)
{
	StackElement *newElement = new StackElement;
	newElement->value = number;
	newElement->next = stack->head;
	stack->head = newElement;
}

void stackPop(Stack *stack)//int stackPop(Stack *stack) // if you need to have pop element - uncomment
{
	if (stack->head == nullptr)
	{
		return;//return - 1 // if you need to have pop element - uncomment
	}
	//int value = stack->head->value; // if you need to have pop element - uncomment
	StackElement *temp = stack->head->next;
	delete stack->head;
	stack->head = temp;
	return; // return value; // if you need to have pop element - uncomment
}

void stackDelete(Stack *stack)
{
	while (stack->head != nullptr)
	{
		StackElement *temp = stack->head;
		stack->head = stack->head->next;
		delete temp;
	}
}

int stackHead(Stack *stack)
{
	return stack->head->value;
}

bool stackEmpty(Stack *stack)
{
	return stack->head == nullptr;
}