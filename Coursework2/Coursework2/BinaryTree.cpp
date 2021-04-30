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
void BinaryTree::insert(identifier& new_identifier, string currentFunction)
{
	insert_helper(&root, new_identifier, currentFunction);
}

//Returns a string representation of the tree in alphabetical order (in order)
void BinaryTree::print_tree()
{
	print_tree_helper(root);
}

//Private insert helper
//Parameters: root -- the root node of the tree; new_identifier, a struct with word info to insert
void BinaryTree::insert_helper(node** root, identifier& new_identifier, string currentFunction)
{
	if (*root == nullptr)
	{
		*root = new node();
		(*root)->left = nullptr;
		(*root)->right = nullptr;
		(*root)->data = new_identifier;
		cout << "Node inserted" << endl;
	}
	else
	{
		size_t bracketPosition = new_identifier.identifierName.find("(");
		cout << currentFunction << " - " << new_identifier.identifierName << " - " << (*root)->data.identifierName << endl;
		if ((*root)->data.identifierName == new_identifier.identifierName) {
			(*root)->data.timesReferenced++;
		}
		else if (bracketPosition != string::npos &&
			(*root)->data.identifierName == new_identifier.identifierName.substr(0, bracketPosition - 1) &&
			new_identifier.identifierName.substr(bracketPosition + 1) == currentFunction + ")") {
			(*root)->data.timesReferenced++;
		}
		else if (new_identifier.identifierName < (*root)->data.identifierName)
		{
			//The new word comes before root alphabetically, so go left.
			//cout << "Moved to left" << endl;
			insert_helper(&((*root)->left), new_identifier, currentFunction);
		}
		else
		{
			//The new word comes after root alphabetically, so go right.
			//cout << "Moved to right" << endl;
			insert_helper(&((*root)->right), new_identifier, currentFunction);
		}
	}
}

//Private print_tree helper
//Returns a string representation of the tree in alphabetical order
void BinaryTree::print_tree_helper(node* root)
{
	/*
	if (root != nullptr) {
		string informations = "";
		informations += root->data.identifierName + ", ";
		informations += to_string(root->data.lineNumber) + ", ";
		informations += root->data.whatIs + ", ";
		informations += root->data.identifierType + ", ";		
		informations += to_string(root->data.timesReferenced) + "\n";		
		return informations;
	}
		
	if (root != nullptr)
	{
		print_tree_helper(root->left, informations);
		informations += root->data.identifierName + ", ";
		informations += to_string(root->data.lineNumber) + ", ";
		informations += root->data.whatIs + ", ";
		informations += root->data.identifierType + ", ";
		informations += to_string(root->data.timesReferenced) + "\n";
		print_tree_helper(root->right, informations);
	}
	else
	{
		return informations;
	}
	*/
	if (root == nullptr)
	{
		return;
	}
	else {
		print_tree_helper(root->left);
		cout << root->data.identifierName << ", "
			<< to_string(root->data.lineNumber) << ", "
			<< root->data.whatIs << ", "
			<< root->data.identifierType << ", "
			<< "referenced " << to_string(root->data.timesReferenced) << endl;
		print_tree_helper(root->right);
	}
}

void BinaryTree::delete_tree(node* root) {
	if (root == nullptr) {
		return;
	}
	delete_tree(root->left);
	delete_tree(root->right);
}