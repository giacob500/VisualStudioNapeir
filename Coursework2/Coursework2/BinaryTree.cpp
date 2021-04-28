//Author: Giacomo Lorenzi
//Implementation of a binary search tree class

#include "BinaryTree.h"
#include <iostream>
#include <string>
using namespace std;

//Creates an empty tree
BinaryTree::BinaryTree()
{
	root = nullptr;
}

//Destructor
BinaryTree::~BinaryTree()
{
	delete_tree(root);
}

//Inserts a new word
void BinaryTree::insert(identifier& new_identifier)
{
	insert_helper(&root, new_identifier);
}

//Returns a string representation of the tree in alphabetical order (in order)
string BinaryTree::print_tree()
{
	return print_tree_helper(root);
}

//Private insert helper
//Parameters: root -- the root node of the tree; new_identifier, a struct with word info to insert
void BinaryTree::insert_helper(node** root, identifier& new_identifier)
{
	if (*root == nullptr)
	{
		*root = new node();
		(*root)->left = nullptr;
		(*root)->right = nullptr;
		(*root)->data = new_identifier;
	}
	else
	{
		if (new_identifier.identifierName < (*root)->data.identifierName)
		{
			//The new word comes before root alphabetically, so go left.
			insert_helper(&((*root)->left), new_identifier);
		}
		else
		{
			//The new word comes after root alphabetically, so go right.
			insert_helper(&((*root)->right), new_identifier);
		}
	}
}

//Private print_tree helper
//Returns a string representation of the tree in alphabetical order
string BinaryTree::print_tree_helper(node* root)
{
	if (root->left != nullptr)
		return print_tree_helper(root->left);
	else {
		if (root != nullptr) {
			return root->data.identifierName;
		}
		else
			//if (root->right != nullptr)
			return print_tree_helper(root->right);
	}
}

void BinaryTree::delete_tree(node* root) {
	if (root == nullptr) {
		return;
	}
	delete_tree(root->left);
	delete_tree(root->right);
}