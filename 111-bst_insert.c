#include "binary_trees.h"

/**
 * bst_insert - inserts a value in a Binary Search Tree
 * @tree: a double pointer to the root node of the BST to insert the value
 * @value: the value to store in the node to be inserted
 * Return: A pointer to the created node
 *         NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *current, *newvalue;

	if (tree != NULL)
	{
		current = *tree;

		if (current == NULL)
		{
			newvalue = binary_tree_node(current, value);
			if (newvalue == NULL)
				return (NULL);
			return (*tree = newvalue);
		}

		if (value < current->n)
		{
			if (current->left != NULL)
				return (bst_insert(&current->left, value));

			newvalue = binary_tree_node(current, value);
			if (newvalue == NULL)
				return (NULL);
			return (current->left = newvalue);
		}
		if (value > current->n)
		{
			if (current->right != NULL)
				return (bst_insert(&current->right, value));

			newvalue = binary_tree_node(current, value);
			if (newvalue == NULL)
				return (NULL);
			return (current->right = newvalue);
		}
	}
	return (NULL);
}
