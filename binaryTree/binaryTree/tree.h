#pragma once

struct treeElement
{
	int number;
	treeElement *left;
	treeElement *right;
	treeElement *parent;
};

struct treeHead
{
	treeElement *head;
};

bool find(treeElement* source, int num);
void add(treeElement** source, int num);
void del(treeElement* source, int num);
void printTreeIncrease(treeElement* source);
void printTreeDecrease(treeElement* source);