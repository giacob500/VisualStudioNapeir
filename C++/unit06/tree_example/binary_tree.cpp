#include <iostream>

using namespace std;

struct node
{
	int data;
	node* left;
	node* right;
};

void insert(node** tree, int value)
{
	if (*tree == nullptr)
	{
		*tree = new node;
		(*tree)->data = value;
		(*tree)->left = nullptr;
		(*tree)->right = nullptr;
	}
	else {
		if (value < (*tree)->data) {
			insert(&(*tree)->left, value);
		}
		else if (value > (*tree)->data) {
			insert(&(*tree)->right, value);
		}
		else
			return;
	}
}

void delete_tree(node* tree) {
	if (tree == nullptr) {
		return;
	}
	delete_tree(tree->left);
	delete_tree(tree->right);
}

void inorder(node* tree)
{
	if (tree == nullptr)
	{
		return;
	}else{
		inorder(tree->left);
		cout << "value: " << tree->data << endl;
		inorder(tree->right);
	}
}

int main(int argc, char** argv)
{
	node* tree = nullptr;
	while (true)
	{
		int num;
		cout << "Enter number ( -1 to exit ): ";
		cin >> num;

		if (num == -1) {
			break;
		}
		insert(&tree, num);
	}
	inorder(tree);
	cout << endl;
	delete_tree(tree);
	return 0;
}