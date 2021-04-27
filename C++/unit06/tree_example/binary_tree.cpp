#include <iostream>

using namespace std;

struct node
{
	int data;
	node* left;
	node* right;
};

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
	}else{
		inorder(root->left);
		cout << "value: " << root->data << endl;
		inorder(root->right);
	}
}

int main(int argc, char** argv)
{
	node* root = nullptr;
	while (true)
	{
		int num;
		cout << "Enter number ( -1 to exit ): ";
		cin >> num;

		if (num == -1) {
			break;
		}
		insert(&root, num);
	}
	inorder(root);
	cout << endl;
	delete_tree(root);
	return 0;
}