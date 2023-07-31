/**
 * binary_tree_is_full - function that checks if a binary tree is full
 * @tree:  is a pointer to the root node of the tree to measure
 * the balance factor
 * Return: If tree is NULL, the function must return 0
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (!tree->right && !tree->left)
		return (1);

	if (tree->right && tree->left)
		return (binary_tree_is_full(tree->left) &&
			binary_tree_is_full(tree->right));

	return (0);
}
