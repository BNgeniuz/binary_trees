#include "binary_trees.h"

/**
 * binary_tree_delete - entire binary tree deletion
 * @tree: tree to be deleted
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (!tree)
		return;
	binary_tree_delete(tree->right);
	binary_tree_delete(tree->left);
	free(tree);
}
