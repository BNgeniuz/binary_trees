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
	binary_tree_t *new_node;

	if (!parent)
		return (NULL);

	new_node = malloc(sizeof(binary_tree_t));
	if (!new_node)
		return (NULL);

	new_node->n = value;
	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = parent->right;
	parent->right = new_node;
	if (new_node->right)
		new_node->right->parent = new_node;
	return (new_node);
}
