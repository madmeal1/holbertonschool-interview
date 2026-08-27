#include <stdlib.h>
#include "binary_trees.h"

/**
 * free_avl - Free an AVL subtree
 *
 * @tree: Root of the subtree
 */
static void free_avl(avl_t *tree)
{
	if (tree == NULL)
		return;

	free_avl(tree->left);
	free_avl(tree->right);
	free(tree);
}

/**
 * build_avl - Build a balanced AVL tree from part of an array
 *
 * @array: Sorted array of integers
 * @start: First array index
 * @end: Last array index
 * @parent: Parent node
 *
 * Return: Pointer to the created subtree, or NULL on failure
 */
static avl_t *build_avl(int *array, size_t start, size_t end, avl_t *parent)
{
	avl_t *node;
	size_t middle;

	if (start > end)
		return (NULL);

	middle = start + (end - start) / 2;
	node = malloc(sizeof(*node));
	if (node == NULL)
		return (NULL);

	node->n = array[middle];
	node->parent = parent;
	node->left = NULL;
	node->right = NULL;

	if (middle > start)
		node->left = build_avl(array, start, middle - 1, node);
	if (middle > start && node->left == NULL)
	{
		free(node);
		return (NULL);
	}

	if (middle < end)
		node->right = build_avl(array, middle + 1, end, node);
	if (middle < end && node->right == NULL)
	{
		free_avl(node->left);
		free(node);
		return (NULL);
	}

	return (node);
}

/**
 * sorted_array_to_avl - Build an AVL tree from a sorted array
 *
 * @array: Sorted array of integers
 * @size: Number of elements in the array
 *
 * Return: Pointer to the root node, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);

	return (build_avl(array, 0, size - 1, NULL));
}
