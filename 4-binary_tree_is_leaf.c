#include "binary_trees.h"

/**
 * binary_tree_is_leaf - if a node is a leaf
 * @node: node to input
 *
 * Return: 1 if node is a leaf, 0 for null or no leaf
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	return ((!node || node->left || node->right) ? 0 : 1);
}
