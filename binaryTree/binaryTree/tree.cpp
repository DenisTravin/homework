#include <cstdio>
#include "tree.h"

bool findElement(treeElement* source, int num)//function try to find element in tree
{
	if (source == nullptr)
	{
		return 0;
	}
	if (num == source->number)
	{
		return 1;
	}
	else if (num > source->number)
	{
		if (findElement(source->right, num))
		{
			return 1;
		}
	}
	else
	{
		if (findElement(source->left, num))
		{
			return 1;
		}
	}
	return 0;
}

treeElement* makeNewElement(int num)//function to give memory for new element and party of inicialisation
{
	treeElement* newElement = new treeElement;
	newElement->number = num;
	newElement->left = nullptr;
	newElement->right = nullptr;
	return newElement;
}

void addElement(treeElement** source, int num)//function add elemenet in tree(double pointer for source, it's for adding element then tree is empty)
{
	if ((*source) == nullptr)
	{
		treeElement* newElement = makeNewElement(num);
		newElement->parent = nullptr;
		*source = newElement;
		return;
	}
	else if ((*source)->number == num)
	{
		return;
	}
	else if (num > (*source)->number)
	{
		if ((*source)->right == nullptr)
		{
			treeElement* newElement = makeNewElement(num);
			newElement->parent = (*source);
			(*source)->right = newElement;
			return;
		}
		addElement(&(*source)->right, num);
	}
	else
	{
		if ((*source)->left == nullptr)
		{
			treeElement* newElement = makeNewElement(num);
			newElement->parent = (*source);
			(*source)->left = newElement;
			return;
		}
		addElement(&(*source)->left, num);
	}
}

treeElement* delWithBothChildrenLeft(treeElement* source)//seacching tree element with empty right tree
{
	if (source->right == nullptr)
	{
		return source;
	}
	else
	{
		return delWithBothChildrenLeft(source->right);
	}
}

treeElement* delWithBothChildrenRight(treeElement* source)//seacching tree element with empty left tree
{
	if (source->left == nullptr)
	{
		return source;
	}
	else
	{
		return delWithBothChildrenRight(source->left);
	}
}

void deleteElementByNumber(treeElement* source, int num, treeHead* tree)//delete elelement by number(realy hard to write it, but i try and it works, read comment's)
{
	if (source == nullptr)//if tree is empty, all is nice
	{
		return;
	}
	else
	{
		if (num > source->number)//find number, what we need to delete
		{
			deleteElementByNumber(source->right, num, tree);
		}
		else if (num < source->number)
		{
			deleteElementByNumber(source->left, num, tree);
		}
		else//we find it! GO delete
		{
			if (source->left == nullptr && source->right == nullptr)//if tree element with this number don't have any children, we can just delete him
			{
				if (source->parent->left != nullptr && source->parent->left->number == num)
				{
					source->parent->left = nullptr;
				}
				else
				{
					source->parent->right = nullptr;
				}
				if (tree->head == source)
				{
					tree->head = nullptr;
				}
				delete source;
			}
			else if (source->left == nullptr)//if this element have only right child
			{
				if (source->parent->left != nullptr && source->parent->left->number == num)
				{
					source->parent->left = source->right;
				}
				else
				{
					source->parent->right = source->right;
				}
				source->right->parent = source->parent;
				if (tree->head == source)
				{
					tree->head = source->right;
				}
				delete source;
			}
			else if (source->right == nullptr)//if this element have only left child
			{
				if (source->parent->left != nullptr && source->parent->left->number == num)
				{
					source->parent->left = source->left;
				}
				else
				{
					source->parent->right = source->left;
				}
				source->left->parent = source->parent;
				if (tree->head == source)
				{
					tree->head = source->left;
				}
				delete source;
			}
			else//now this element have both child
			{

				if (source->right->left == nullptr)//if this element don't have ->right->left tree
				{
					if (source->left->right == nullptr)
					{
						source->left->right = source->right;
						source->right->parent = source->left;
						if (tree->head == source)
						{
							tree->head = source->left;
						}
					}
					else
					{
						treeElement* temp = delWithBothChildrenLeft(source->left->right);
						temp->parent->right = nullptr;
						temp->right = source->right;
						temp->left = source->left;
						source->right->parent = temp;
						source->left->parent = temp;
						temp->parent = source->parent;
						if (tree->head == source)
						{
							tree->head = temp;
						}
						else
						{
							if (source->parent->left != nullptr && source->number == source->parent->left->number)
							{
								source->parent->left = temp;
							}
							else
							{
								source->parent->right = temp;
							}
						}
					}
					delete source;
				}
				//OK, now GO do else
				else
				{
					if (source->right->left == nullptr)//if source don't have ->right->left tree
					{
						source->right->left = source->left;
						source->left->parent = source->right;
						if (tree->head == source)
						{
							tree->head = source->right;
						}
					}
					else
					{
						treeElement* temp = delWithBothChildrenRight(source->right->left);
						temp->parent->left = nullptr;
						temp->left = source->left;
						temp->right = source->right;
						source->left->parent = temp;
						source->right->parent = temp;
						temp->parent = source->parent;
						if (tree->head == source)
						{
							tree->head = temp;
						}
						else
						{
							if (source->parent->left != nullptr && source->number == source->parent->left->number)
							{
								source->parent->left = temp;
							}
							else
							{
								source->parent->right = temp;
							}
						}
					}
					delete source;
				}
			}
		}
	}
}

void printTreeIncrease(treeElement* source)
{
	if (source == nullptr)
	{
		return;
	}
	else
	{
		printTreeIncrease(source->left);
		printf("%i ", source->number);
		printTreeIncrease(source->right);
	}
}

void printTreeDecrease(treeElement* source)
{
	if (source == nullptr)
	{
		return;
	}
	else
	{
		printTreeDecrease(source->right);
		printf("%i ", source->number);
		printTreeDecrease(source->left);
	}
}

void deleteAllTree(treeElement* source)
{
	if (source->left == nullptr && source->right == nullptr)
	{
		delete source;
	}
	else
	{
		if (source->left != nullptr)
		{
			deleteAllTree(source->left);
		}
		if (source->right != nullptr)
		{
			deleteAllTree(source->right);
		}
		delete source;
	}
}