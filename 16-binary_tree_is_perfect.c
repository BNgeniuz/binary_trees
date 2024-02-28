#include "binary_trees.h"

/**
 * binary_tree_is_perfect - binary tree is perfect
 * @tree: input root node of the tree to check
 *
 * Return: 1 if the tree is perfect, 0 if the tree is not perfect
 * 0 if tree is NULL
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int height_left, height_right;

	if (!tree)
		return (0);

	height_left = binary_tree_height(tree->left);
	height_right = binary_tree_height(tree->right);

	if (height_left == height_right)
	{
		if (!tree->left && !tree->right)
			return (1);

		return (binary_tree_is_perfect(tree->left) &&
				binary_tree_is_perfect(tree->right));
	}

	return (0);
}


/**
 * binary_tree_height - height of a binary tree
 * @tree: input tree to measure height
 *
 * Return: height of the tree, or 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_l = 0;
	size_t height_r = 0;

	if (!tree)
		return (0);

	height_l = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	height_r = tree->right ? 1 + binary_tree_height(tree->right) : 0;
	return (height_l > height_r ? height_l : height_r);
}
