#include <cstdio>
#include "tree.h"

bool find(treeElement* source, int num)
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
		if (find(source->right, num))
		{
			return 1;
		}
	}
	else
	{
		if (find(source->left, num))
		{
			return 1;
		}
	}
	return 0;
}

void add(treeElement** source, int num)
{
	if ((*source) == nullptr)
	{
		treeElement* newElement = new treeElement;
		newElement->number = num;
		newElement->left = nullptr;
		newElement->right = nullptr;
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
			treeElement* newElement = new treeElement;
			newElement->number = num;
			newElement->left = nullptr;
			newElement->right = nullptr;
			newElement->parent = (*source);
			(*source)->right = newElement;
			return;
		}
		add(&(*source)->right, num);
	}
	else
	{
		if ((*source)->left == nullptr)
		{
			treeElement* newElement = new treeElement;
			newElement->number = num;
			newElement->left = nullptr;
			newElement->right = nullptr;
			newElement->parent = (*source);
			(*source)->left = newElement;
			return;
		}
		add(&(*source)->left, num);
	}
}

treeElement* delWithBothChildrenLeft(treeElement* source)
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

treeElement* delWithBothChildrenRight(treeElement* source)
{
	if (source->left == nullptr)
	{
		return source;
	}
	else
	{
		return delWithBothChildrenLeft(source->left);
	}
}

void del(treeElement* source, int num)//realy hard to write it, but i try and it works, read comment's
{
	if (source == nullptr)//if tree is empty, all is nice
	{
		return;
	}
	else
	{
		if (num > source->number)//find number, what we need to delete
		{
			del(source->right, num);
		}
		else if (num < source->number)
		{
			del(source->left, num);
		}
		else//we find it! GO delete
		{
			if (source->left == nullptr && source->right == nullptr)//if tree element with this number don't have any childrens, we can just delete him
			{
				if (source->parent->left->number == num)
				{
					source->parent->left = nullptr;
				}
				else
				{
					source->parent->right = nullptr;
				}
				delete source;
			}
			else if (source->left == nullptr)//if this element have right child
			{
				if (source->parent->left->number == num)
				{
					source->parent->left = source->right;
				}
				else
				{
					source->parent->right = source->right;
				}
				source->right->parent = source->parent;
				delete source;
			}
			else if (source->right == nullptr)//if this element have left child
			{
				if (source->parent->left->number == num)
				{
					source->parent->left = source->left;
				}
				else
				{
					source->parent->right = source->left;
				}
				source->left->parent = source->parent;
				delete source;
			}
			else//now this element have 2 child
			{

				if (source->right->left == nullptr)//if this element don't have ->right->left tree
				{
					if (source->left->right == nullptr)
					{
						source->left->right = source->right;
						source->right->parent = source->left;
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
						if (source->number == source->parent->left->number)
						{
							source->parent->left = temp;
						}
						else
						{
							source->parent->right = temp;
						}
					}
					delete source;
				}
				//OK, now GO do else
				else
				{
					if (source->right->left == nullptr)
					{
						source->right->left = source->left;
						source->left->parent = source->right;
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
						if (source->number == source->parent->right->number)
						{
							source->parent->right = temp;
						}
						else
						{
							source->parent->left = temp;
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