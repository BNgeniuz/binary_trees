#include "binary_trees.h"
#include <limits.h>
/**
 * binary_tree_is_avl - binary tree is an avl
 * @tree: root node of the tree
 *
 * Return: 1 if tree is avl, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (btia_helper(tree, INT_MIN, INT_MAX));
}

/**
 * btia_helper - finds if a binary tree is an avl
 * @tree: root node of the tree
 * @min: least value
 * @max: max value
 *
 * Return: 1 if tree is avl, 0 otherwise
 */
int btia_helper(const binary_tree_t *tree, int min, int max)
{
	int path_lft, path_rgt;

	if (!tree)
		return (1);
	if (tree->n < min || tree->n > max)
		return (0);

	path_lft = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	path_rgt = tree->right ? 1 + binary_tree_height(tree->right) : 0;

	if (abs(path_lft - path_rgt) > 1)
		return (0);

	return (btia_helper(tree->left, min, tree->n - 1) &&
		btia_helper(tree->right, tree->n + 1, max));
	/* This is part of the BST check logic */
}

/**
 * binary_tree_height - height of a binary tree
 * @tree: tree  height
 *
 * Return: height of the tree, 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_lft = 0;
	size_t height_rgt = 0;

	if (!tree)
		return (0);

	height_lft = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	height_rgt = tree->right ? 1 + binary_tree_height(tree->right) : 0;
	return (height_lft > height_rgt ? height_lft : height_rgt);
}
