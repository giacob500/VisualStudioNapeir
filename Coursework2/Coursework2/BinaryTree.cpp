#include <iostream>
#include <string>
#include "BinaryTree.h"

using namespace std;

struct node {
	string identifierName;
	int lineNumber = 0;
	string whatIs;
	string identifierType;
	int timesReferenced = 0;
	int data;
	node* left;
	node* right;
};

class BinaryTree {

	node* root;

public:
	// Not used
	BinaryTree() {
		this->root = nullptr;
	}

	~BinaryTree() {
		delete(root);
	}

	void populate(node** root, int value) {
		insert(root, value);
	}

	void insert(node** root, int value)
	{
		if (*root == nullptr)
		{
			*root = new node;
			(*root)->data = value;
			(*root)->left = nullptr;
			(*root)->right = nullptr;
		}
		else {
			if (value < (*root)->data) {
				insert(&(*root)->left, value);
			}
			else if (value > (*root)->data) {
				insert(&(*root)->right, value);
			}
			else
				return;
		}
	}

	void delete_tree(node* root) {
		if (root == nullptr) {
			return;
		}
		delete_tree(root->left);
		delete_tree(root->right);
	}

	void inorder(node* root)
	{
		if (root == nullptr)
		{
			return;
		}
		else {
			inorder(root->left);
			cout << "value: " << root->data << endl;
			inorder(root->right);
		}
	}
};