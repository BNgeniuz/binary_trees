#include "binary_trees.h"

/**
 * binary_tree_rotate_right - right-rotation on a binary tree
 * @tree: input ptr root node of the tree
 *
 * Return: NULL upon failure
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *pmt = NULL, *parent;

	if (!tree || !tree->left)
		return (NULL);
	pmt = tree;
	parent = tree->parent;
	tree = tree->left;
	tree->parent = NULL;
	if (tree->right)
	{
		pmt->left = tree->right;
		tree->right->parent = pmt;
	}
	else
		pmt->left = NULL;
	pmt->parent = tree;
	tree->right = pmt;
	if (parent)
		parent->left = tree;
	tree->parent = parent;
	return (tree);
}
