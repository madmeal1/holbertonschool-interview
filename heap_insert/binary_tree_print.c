/*
 * File: binary_tree_print.c
 * Description: Print a binary tree visually (provided helper for testing).
 */

#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/* Prototypes for internal functions */
static size_t _height(const binary_tree_t *tree);
static void print_level(const binary_tree_t *tree, int level, int indent);

/* Compute height of tree */
static size_t _height(const binary_tree_t *tree)
{
	size_t l, r;

	if (tree == NULL)
		return (0);
	l = _height(tree->left);
	r = _height(tree->right);
	return ((l > r ? l : r) + 1);
}

/* Print nodes at a given level */
static void print_level(const binary_tree_t *tree, int level, int indent)
{
	int i;

	if (level == 1)
	{
		for (i = 0; i < indent; i++)
			printf(" ");
		if (tree)
			printf("(%03d)", tree->n);
		else
			printf("     ");
	}
	else if (level > 1)
	{
		print_level(tree ? tree->left : NULL, level - 1, indent);
		print_level(tree ? tree->right : NULL, level - 1, indent);
	}
}

/**
 * binary_tree_print - Print a binary tree using level-order layout
 * @tree: Pointer to root node
 */
void binary_tree_print(const binary_tree_t *tree)
{
	int h, lvl;
	int indent;

	if (tree == NULL)
		return;

	h = (int)_height(tree);
	for (lvl = 1; lvl <= h; lvl++)
	{
		indent = (h - lvl) * 6;
		print_level(tree, lvl, indent);
		printf("\n");
	}
}
