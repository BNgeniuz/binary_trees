#include "binary_trees.h"

/**
 * binary_tree_insert_right - right-child of another node
 * @parent: insert the right-child in
 * @value: node value
 *
 * Return: 0 (on success)
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *fresh;

	if (!parent)
		return (NULL);

	fresh = malloc(sizeof(binary_tree_t));
	if (!fresh)
		return (NULL);

	fresh->n = value;
	fresh->parent = parent;
	fresh->left = NULL;
	fresh->right = parent->right;
	parent->right = fresh;
	if (fresh->right)
		fresh->right->parent = fresh;
	return (fresh);
}
