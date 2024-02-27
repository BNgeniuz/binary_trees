#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts left-child of another node
 * @parent: input node to insert the left-child
 * @value: node value
 *
 * Return: 0 (on success)
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *fresh;

	if (!parent)
		return (NULL);

	fresh = malloc(sizeof(binary_tree_t));
	if (!fresh)
		return (NULL);

	fresh->n = value;
	fresh->parent = parent;
	fresh->right = NULL;
	fresh->left = parent->left;
	parent->left = fresh;
	if (fresh->left)
		fresh->left->parent = fresh;
	return (fresh);
}
