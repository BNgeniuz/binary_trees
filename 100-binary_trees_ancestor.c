#include "binary_trees.h"

/**
 * binary_trees_ancestor - lowest common ancestor of two nodes
 * @first: input ptr node to find the ancestor
 * @second: ptr to fine second node of the ancestor
 *
 * Return: ancestor node, NULL if there is no ancestor node
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	size_t first_depth, second_depth;

	if (!first || !second)
		return (NULL);

	first_depth = binary_tree_depth(first);
	second_depth = binary_tree_depth(second);

	while (first_depth > second_depth)
	{
		first = first->parent;
		first_depth--;
	}
	while (second_depth > first_depth)
	{
		second = second->parent;
		second_depth--;
	}
	while (first && second)
	{
		if (first == second)
			return ((binary_tree_t *)first);
		first = first->parent;
		second = second->parent;
	}
	return ((binary_tree_t *)first);
}

/**
 * binary_tree_depth - measures the depth of a binary tree
 * @tree: input node to find the depth
 *
 * Return: depth of the node, 0 if tree is NULL
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t len = 0;

	if (!tree)
		return (0);

	while (tree->parent)
	{
		len++;
		tree = tree->parent;
	}

	return (len);
}
