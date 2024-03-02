#include "binary_trees.h"

/**
 * array_to_bst - builds a Binary Search Tree from an array
 * @array: first element of the array to be converted
 * @size: elements in the array
 * Return: root node of the created BST, NULL on failure
 */
bst_t *array_to_bst(int *array, size_t size)
{
	unsigned int x;
	bst_t *root = NULL;

	for (x = 0; x < size; x++)
		bst_insert(&root, array[x]);

	return (root);
}
