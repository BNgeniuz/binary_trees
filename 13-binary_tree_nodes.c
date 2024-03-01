#include "binary_trees.h"

/**
 * binary_tree_nodes - nodes with at least 1 child in a binary tree
 * @tree: input to count the nodes
 *
 * Return: number of nodes counted, or 0 if tree is NULL
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (tree->left != NULL || tree->right != NULL)
	{
		return (binary_tree_size(tree) - binary_tree_leaves(tree));
	}

	else
	{
		return (0);
	}

}
