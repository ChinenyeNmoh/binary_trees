#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Right-rotates a binary tree.
 * @tree: A pointer to the root node of the tree to rotate.
 *
 * Return: A pointer to the new root node after rotation.
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *roter, *tmp;

	if (tree == NULL)
		return (NULL);
	if (tree->left)
	{
		tmp = tree->left->right;
		roter = tree->left;
		roter->parent = tree->parent;
		roter->right = tree;
		tree->parent = roter;
		tree->left = tmp;
		if (tmp)
			tmp->parent = tree;
		return (roter);
	}
	return (NULL);
}
