#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Left-rotates a binary tree.
 * @tree: A pointer to the root node of the tree to rotate.
 *
 * Return: A pointer to the new root node after rotation.
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *roter, *tmp;

	if (tree == NULL)
		return (NULL);
	if (tree->right)
	{
		tmp = tree->right->left;
		roter = tree->right;
		roter->parent = tree->parent;
		roter->left = tree;
		tree->parent = roter;
		tree->right = tmp;
		if (tmp)
			tmp->parent = tree;
		return (roter);
	}
	return (NULL);
}
