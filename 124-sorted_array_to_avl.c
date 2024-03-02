#include "binary_trees.h"

/**
 * create_tree - creates an AVL tree with recursion
 *
 * @node: pointer node
 * @array: input array of integers
 * @size: size of array
 * @mode: 1 to adding on the left, 2 to adding on the right
 * Return: no return
 */
void create_tree(avl_t **node, int *array, size_t size, int mode)
{
	size_t centre;

	if (size == 0)
		return;

	centre = (size / 2);
	centre = (size % 2 == 0) ? centre - 1 : centre;

	if (mode == 1)
	{
		(*node)->left = binary_tree_node(*node, array[centre]);
		create_tree(&((*node)->left), array, centre, 1);
		create_tree(&((*node)->left), array + centre + 1, (size - 1 - centre), 2);
	}
	else
	{
		(*node)->right = binary_tree_node(*node, array[centre]);
		create_tree(&((*node)->right), array, centre, 1);
		create_tree(&((*node)->right), array + centre + 1, (size - 1 - centre), 2);
	}
}

/**
 * sorted_array_to_avl - creates root node and calls to create_tree
 *
 * @array: input array of integers
 * @size: size of array
 * Return: pointer to the root
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root;
	size_t centre;

	root = NULL;

	if (size == 0)
		return (NULL);

	centre = (size / 2);

	centre = (size % 2 == 0) ? centre - 1 : centre;

	root = binary_tree_node(root, array[centre]);

	create_tree(&root, array, centre, 1);
	create_tree(&root, array + centre + 1, (size - 1 - centre), 2);

	return (root);
}
