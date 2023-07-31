#include "binary_trees.h"

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
	if (tree == NULL)
		return (0);

	if (binary_tree_size(tree) > 0)
		return (1);
	else
		return (0);
}
