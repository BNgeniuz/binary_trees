#include "binary_trees.h"

/**
 * bst_insert - value in a Binary Search Tree
 * @tree: root node of the BST to insert the value
 * @value: value to store in the node to be inserted
 * Return: A pointer to the created node, NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *pmt = *tree;
	bst_t *second = NULL;
	bst_t *new = binary_tree_node(NULL, value);

	if (*tree == NULL)
		*tree = new;

	while (pmt)
	{
		second = pmt;
		if (value < pmt->n)
			pmt = pmt->left;
		else if (value > pmt->n)
			pmt = pmt->right;
		else if (value == pmt->n)
			return (NULL);
	}

	if (second == NULL)
		second = new;
	else if (value < second->n)
	{
		second->left = new;
		new->parent = second;
	}
	else
	{
		second->right = new;
		new->parent = second;
	}

	return (new);
}

/**
 * avl_insert - value in an AVL Tree
 * @tree: root node of the AVL tree
 * @value: val to insert
 *
 * Return: a pointer to the created node, NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	int balance = 0;
	avl_t *node = bst_insert(tree, value);

	balance = binary_tree_balance(*tree);

	if (balance > 1 && value < node->left->n)
		return (binary_tree_rotate_right(node));
	if (balance < -1 && value > node->right->n)
		return (binary_tree_rotate_left(node));
	if (balance > 1 && value > node->left->n)
	{
		node->left = binary_tree_rotate_left(node->left);
		return (binary_tree_rotate_right(node));
	}
	if (balance < -1 && value < node->right->n)
	{
		node->right = binary_tree_rotate_right(node->right);
		return (binary_tree_rotate_left(node));
	}

	return (node);
}
