
#include "binary_trees.h"
#include <stdlib.h>

/**
 * swap_up - Swaps a node up to maintain Max Heap property
 * @node: Pointer to the node to swap up
 * Return: Pointer to the final position of the inserted node
 */
static heap_t *swap_up(heap_t *node)
{
	int tmp;
	while (node->parent && node->n > node->parent->n)
	{
		tmp = node->n;
		node->n = node->parent->n;
		node->parent->n = tmp;
		node = node->parent;
	}
	return node;
}

/**
 * find_parent_bfs - Finds the parent for insertion using level-order traversal
 * @root: Pointer to the root node
 * Return: Pointer to the parent node for insertion
 */
static binary_tree_t *find_parent_bfs(binary_tree_t *root)
{
	binary_tree_t **queue, *parent = NULL;
	size_t front = 0, rear = 0, size = 1024;
	if (!root)
		return (NULL);
	queue = malloc(sizeof(binary_tree_t *) * size);
	if (!queue)
		return (NULL);
	queue[rear++] = root;
	while (front < rear)
	{
		parent = queue[front++];
		if (!parent->left || !parent->right)
			break;
		queue[rear++] = parent->left;
		queue[rear++] = parent->right;
	}
	free(queue);
	return parent;
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: Double pointer to the root node
 * @value: Value to insert
 * Return: Pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	binary_tree_t *parent, *new_node;

	if (!root)
		return (NULL);
	if (!*root)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}
	parent = find_parent_bfs(*root);
	if (!parent)
		return (NULL);
	if (!parent->left)
	{
		new_node = binary_tree_node(parent, value);
		if (!new_node)
			return (NULL);
		parent->left = new_node;
	}
	else
	{
		new_node = binary_tree_node(parent, value);
		if (!new_node)
			return (NULL);
		parent->right = new_node;
	}
	return swap_up(new_node);
}
