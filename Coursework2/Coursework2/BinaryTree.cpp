// Author: Giacomo Lorenzi
// Implementation of a binary search tree class

#include "BinaryTree.h"
#include <iostream>
#include <string>
using namespace std;

// Constructor (creates an empty tree)
BinaryTree::BinaryTree()
{
	root = nullptr;
}

// Destructor
BinaryTree::~BinaryTree()
{
	delete_tree(root);
}

// Inserts a new identifier
void BinaryTree::insert(identifier& new_identifier)
{
	insert_helper(&root, new_identifier);
}

// Check for identifier's references to update
void BinaryTree::update(std::string word, std::string currentFunction)
{
	update_helper(&root, word, currentFunction);
}

// Prints a representation of the tree in alphabetical order
void BinaryTree::print_tree()
{
	print_tree_helper(root);
}

// Private insert helper
// Parameters: root, the root node of the tree; new_identifier, a struct with identfier's attributes
void BinaryTree::insert_helper(node** root, identifier& new_identifier)
{
	if (*root == nullptr)
	{
		// Add identifier to the new BST's node
		*root = new node();
		(*root)->left = nullptr;
		(*root)->right = nullptr;
		(*root)->data = new_identifier;
	}
	else
	{
		if (new_identifier.identifierName < (*root)->data.identifierName)
		{
			// The identifier's name comes before root alphabetically, so go left.
			insert_helper(&((*root)->left), new_identifier);
		}
		else
		{
			// The identifier's name comes after root alphabetically, so go right.
			insert_helper(&((*root)->right), new_identifier);
		}
	}
}

// Private upadte helper
// Parameters: root, the root node of the tree; word, to compare it with identifier's name; currentFunction, to compare it with identifier's scope
void BinaryTree::update_helper(node** root, string word, string currentFunction)
{
	if (*root == nullptr)
	{
		return;
	}
	else
	{
		size_t bracketPosition = (*root)->data.identifierName.find("(");	// If exists, save '(' position from identifier's name for later
		if (word == (*root)->data.identifierName)
		{
			// If identifier's name equals to the word increase identifier's reference counter
			(*root)->data.timesReferenced++;
		}
		else if (bracketPosition != string::npos &&
			word == (*root)->data.identifierName.substr(0, bracketPosition - 1) &&
			(*root)->data.identifierName.substr(bracketPosition + 1) == currentFunction + ")")
		{
			// If variable name equals to word and variable's function equals to current function increase identifier's reference counter
			(*root)->data.timesReferenced++;
		}
		else if (word < (*root)->data.identifierName)
		{
			//The identifier's name comes before root alphabetically, so go left.
			update_helper(&((*root)->left), word, currentFunction);
		}
		else
		{
			//The identifier's name comes after root alphabetically, so go right.
			update_helper(&((*root)->right), word, currentFunction);
		}
	}
}

// Private print_tree helper
// Parameters: root, the root node of the tree
void BinaryTree::print_tree_helper(node* root)
{
	if (root == nullptr)
	{
		return;
	}
	else {
		// Print a string representation of the tree in alphabetical order
		print_tree_helper(root->left);
		cout << root->data.identifierName << ", "
			<< "line " << to_string(root->data.lineNumber) << ", "
			<< root->data.whatIs << ", "
			<< root->data.identifierType << ", "
			<< "referenced " << to_string(root->data.timesReferenced) << endl;
		print_tree_helper(root->right);
	}
}

// Private delete_tree
// Deletes tree
void BinaryTree::delete_tree(node* root) {
	if (root == nullptr) {
		delete(root);
		return;
	}
	delete_tree(root->left);
	delete_tree(root->right);
}