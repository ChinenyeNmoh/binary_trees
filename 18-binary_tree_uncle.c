#include "binary_trees.h"

/**
 * binary_tree_uncle - function that finds the uncle of a node
 * @node: pointer to the node to find the uncle
 * Return: return a pointer to the uncle node
 * NULL If node is NULL
 * NULL If node has no uncles
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL ||
	 node->parent->parent == NULL ||
	 node->parent->parent->left == NULL ||
	 node->parent->parent->right == NULL)
		return (NULL);



	if (node->parent->parent->left->left == node ||
	node->parent->parent->left->right == node)
		return (node->parent->parent->right);
	return (node->parent->parent->left);
}
