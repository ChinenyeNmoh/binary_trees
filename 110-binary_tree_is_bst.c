#include "binary_trees.h"
#include <limits.h>

/**
 * isBST - checks if a given tree is a BST
 * @tree: pointer to the root node of the tree to check
 * @min: INT_MIN
 * @max: INT_MAX
 * Return: If tree is NULL, your function must return 0
 */
int isBST(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);
	if (tree->n < min || tree->n > max)
		return (0);
	return (isBST(tree->left, min, tree->n - 1) &&
	isBST(tree->right, tree->n + 1, max));
}

/**
 * binary_tree_is_bst - function that checks if a binary tree
 * is a valid Binary Search Tree
 * @tree: pointer to the root node of the tree to check
 * Return: If tree is NULL, your function must return 0
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (isBST(tree, INT_MIN, INT_MAX));
}
