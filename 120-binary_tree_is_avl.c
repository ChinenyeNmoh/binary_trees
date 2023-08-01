#include "binary_trees.h"
#include <limits.h>

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
 * isavl - helper that finds if a binary tree is an avl
 * @tree: pointer to the root node of the tree
 * @min: minimum value
 * @max: maximum value
 *
 * Return: 1 if tree is avl
 *         0 otherwise
 */
int isavl(const binary_tree_t *tree, int min, int max)
{
	int path_left, path_right;

	if (!tree)
		return (1);
	if (tree->n < min || tree->n > max)
		return (0);

	path_left = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	path_right = tree->right ? 1 + binary_tree_height(tree->right) : 0;

	if (abs(path_left - path_right) > 1)
		return (0);

	return (isavl(tree->left, min, tree->n - 1) &&
		isavl(tree->right, tree->n + 1, max));
}
/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is a valid AVL tree, and 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (isavl(tree, INT_MIN, INT_MAX));
}
