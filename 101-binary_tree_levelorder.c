#include "binary_trees.h"

/**
 * binary_tree_levelorder - binary tree using level-order traverse
 * @tree: traverse tree
 * @func: pointer to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t level, tree_height;

	if (!tree || !func)
		return;

	tree_height = binary_tree_height(tree) + 1;

	for (level = 1; level <= tree_height; level++)
		btlo_helper(tree, func, level);
}

/**
 * btlo_helper - binary tree using post-order traverse
 * @tree: traverse tree
 * @func: pointer to call  node
 * @level: tree to call func
 */
void btlo_helper(const binary_tree_t *tree, void (*func)(int), size_t level)
{
	if (level == 1)
		func(tree->n);
	else
	{
		btlo_helper(tree->left, func, level - 1);
		btlo_helper(tree->right, func, level - 1);
	}
}

/**
 * binary_tree_height - height of a binary tree
 * @tree: measure the height
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
