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

bool findElement(treeElement* source, int num);
void addElement(treeElement** source, int num);
void deleteElementByNumber(treeElement* source, int num, treeHead* tree);
void printTreeIncrease(treeElement* source);
void printTreeDecrease(treeElement* source);
void deleteAllTree(treeElement* source);