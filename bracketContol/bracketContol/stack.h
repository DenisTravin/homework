#pragma once
struct StackElement
{
	int value;
	StackElement *next;
};

struct Stack
{
	StackElement *head;
};

void stackPush(Stack *stack, int number);
void stackPop(Stack *stack);
void stackDelete(Stack *stack);
int stackHead(Stack *stack);
bool stackEmpty(Stack *stack);