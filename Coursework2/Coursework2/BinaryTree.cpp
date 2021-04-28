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
void BinaryTree::insert(word_info& new_word)
{
	insert_helper(&root, new_word);
}

//Returns a string representation of the tree in alphabetical order (in order)
string BinaryTree::print_tree()
{
	return print_tree_helper(root);
}

//Private insert helper
//Parameters: root -- the root node of the tree; new_word, a struct with word info to insert
void BinaryTree::insert_helper(node** root, word_info& new_word)
{
	if (*root == nullptr)
	{
		*root = new node();
		(*root)->left = nullptr;
		(*root)->right = nullptr;
		(*root)->data = new_word;
	}
	else
	{
		if (new_word.word < (*root)->data.word)
		{
			//The new word comes before root alphabetically, so go left.
			insert_helper(&((*root)->left), new_word);
		}
		else
		{
			//The new word comes after root alphabetically, so go right.
			insert_helper(&((*root)->right), new_word);
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
			return root->data.word;
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