#include "binary_trees.h"
/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: If tree is NULL, your function must return 0, else return height.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree != NULL)
	{
		size_t left = 0, right = 0;

		left = tree->left ? 1 + binary_tree_height(tree->left) : 0;
		right = tree->right ? 1 + binary_tree_height(tree->right) : 0;
		if (left > right)
			return (left);
		return (right);
	}
	return (0);
}

/**
 * binary_tree_size - Measures the size of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the size of.
 *
 * Return: The size of the tree.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		return (binary_tree_size(tree->left) +
			binary_tree_size(tree->right) + 1);
	}
}

/**
* binary_tree_is_perfect - A function that checks if a tree is perfect
* @tree: The tree in discussion
* Return: 0 or 1
*/
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t height = 0, psize = 0;

	if (tree == NULL)
		return (0);
	height = binary_tree_height(tree);
	psize = (1 << (height + 1)) - 1;
	if (psize == binary_tree_size(tree))
		return (1);
	else
		return (0);
}
