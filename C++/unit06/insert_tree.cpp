void insert(node **tree, int value)
{
	if (*tree == nullptr)
	{
		*tree = new node;
		(*tree)->data = value;
		(*tree)->left = nullptr;
		(*tree)->right = nullptr;
	}
}