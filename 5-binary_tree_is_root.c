#include "binary_trees.h"

/**
 * binary_tree_is_root - if a node is a root
 * @node: node to input
 *
 * Return: 1 if node is a root, 0 for NULL or no root
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	if (node == NULL || node->parent != NULL)
	{
		return (0);
	}
	else
	{
		return (1);
	}
}
