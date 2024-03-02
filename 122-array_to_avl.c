#include "binary_trees.h"

/**
 * array_to_avl - builds an AVL tree from an array
 * @array: array to create from
 * @size: size of the array
 *
 * Return: a pointer to the root node of the created AVL tree
 *         NULL on failure
 */
avl_t *array_to_avl(int *array, size_t size)
{
	unsigned int x;
	avl_t *root = NULL;

	for (x = 0; x < size; x++)
		avl_insert(&root, array[x]);

	return (root);
}
