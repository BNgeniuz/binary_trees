#include "binary_trees.h"

/**
 * binary_tree_is_complete - binary tree is completed
 * @tree: input ptr root node of the tree
 *
 * Return: 1 if the tree is complete, 0 if the tree is not complete
 * 0 if tree is NULL
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t size;

	if (!tree)
		return (0);
	size = binary_tree_size(tree);

	return (btic_helper(tree, 0, size));
}

/**
 * btic_helper -binary tree is completed
 * @tree: input ptr root node of the tree
 * @index: node input
 * @size: nodes in the tree
 *
 * Return: 1 if the tree is complete, 0 if the tree is not complete
 * 0 if tree is NULL
 */
int btic_helper(const binary_tree_t *tree, size_t index, size_t size)
{
	if (!tree)
		return (1);

	if (index >= size)
		return (0);

	return (btic_helper(tree->left, 2 * index + 1, size) &&
		btic_helper(tree->right, 2 * index + 2, size));
}

/**
 * binary_tree_size - size of a binary tree
 * @tree: tree ptr to size
 *
 * Return: size of the tree, 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_size(tree->left) +
		binary_tree_size(tree->right) + 1);
}
