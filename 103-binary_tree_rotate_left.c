#include "binary_trees.h"

/**
 * binary_tree_rotate_left - left-rotation on a binary tree
 * @tree: input ptr root node of the tree
 *
 * Return: NULL upon failure
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *pmt = NULL, *parent_root;

	if (!tree || !tree->right)
		return (NULL);
	pmt = tree;
	parent_root = tree->parent;
	tree = tree->right;
	tree->parent = NULL;
	if (tree->left)
	{
		pmt->right = tree->left;
		tree->left->parent = pmt;
	}
	else
		pmt->right = NULL;
	pmt->parent = tree;
	tree->left = pmt;
	if (parent_root)
		parent_root->right = tree;
	tree->parent = parent_root;
	return (tree);
}
